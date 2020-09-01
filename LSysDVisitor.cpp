
#include "LSysDVisitor.h"

#include <utility>
#include <sstream>


ParseTreeNode<InstanceNodeContent, char>* LSysDVisitor::parseInstanceNode(std::string s) {
    std::stringstream ss;
    ss << s;
    antlr4::ANTLRInputStream input(ss);
    LSysDLexer lexer(&input);
    antlr4::CommonTokenStream tokens(&lexer);
    LSysDParser parser(&tokens);

    if (parser.getNumberOfSyntaxErrors() != 0)
        return nullptr;

    antlr4::tree::ParseTree *tree = parser.word();

    // TreeShapeListener listener;
    // tree::ParseTreeWalker::DEFAULT.walk(&listener, tree);

    LSysDVisitor visitor("<axiom>", new std::vector<std::string> {s}, this->env);
    ParseTreeNode<InstanceNodeContent, char>* node = visitor.visit(tree);

    if (visitor.errors()->size() > 0) {
        visitor.dumpErrors();
        return nullptr;
    }

    return node;
}

LSysDVisitor::LSysDVisitor(std::string filename, std::vector<std::string>* sourceLines, Environment* env):
        filename(filename), sourceLines(sourceLines), parentTrace(nullptr) {
    this->env = env ? new Environment(env) : new Environment();
    this->currentTable = nullptr;
    this->parentNode = nullptr;
    this->taggedRules = new std::map<std::string, Rule<char>*>();
    this->tables = new std::map<std::string, Table<char>*>();
    this->tablesList = new std::list<Table<char>*>();
    this->codingRules = new Table<char>("<default>");
}

LSysDVisitor::~LSysDVisitor() {
    delete this->sourceLines;
    // delete this->env;
    // delete this->evaluator;
}

void LSysDVisitor::error(std::string const& msg, StackTrace* st) {
    Error* e = new Error(msg, st);
    this->eh.addError(e);
}

void LSysDVisitor::error(std::string const& msg, antlr4::ParserRuleContext* ctx) {
    this->error(msg, this->trace(ctx, this->parentTrace));
}

void LSysDVisitor::error(std::string const& msg, antlr4::tree::TerminalNode* terminal) {
    this->error(msg, this->trace(terminal->getSymbol(), terminal->getSymbol(), this->parentTrace));
}

// void LSysDVisitor::error(string const& msg, antlr4::Token* tokInit, antlr4::Token* tokEnd) {
//     this->error(msg, this->trace(tokInit, tokEnd));
// }

StackTrace* LSysDVisitor::trace(antlr4::Token* tokInit, antlr4::Token* tokEnd, StackTrace* parent) {
    return new StackTrace(tokInit, tokEnd, parent, this->sourceLines, this->filename);
}

StackTrace* LSysDVisitor::trace(antlr4::ParserRuleContext* ctx, StackTrace* parent) {
    return new StackTrace(ctx, parent, this->sourceLines, this->filename);
}

const std::list<Error*>* LSysDVisitor::errors() const {
    return this->eh.errors();
}

void LSysDVisitor::dumpErrors() const {
    for (Error* e : *this->errors()) {
        std::cerr << e->buildMessage() << std::endl;
    }
}

// Environment* LSysDVisitor::getEnvironment() {
//     return env;
// }

// Value LSysDVisitor::eval(LSysDParser::ExpressionContext* ctx) {
//     return this->evaluator->eval(ctx);
// }



antlrcpp::Any LSysDVisitor::visitMain(LSysDParser::MainContext *ctx) {
    this->defaultTable = new Table<char>("<default>");
    (*this->tables)[this->defaultTable->name] = this->defaultTable;
    // this->tablesList->push_back(t);
    this->codingRules = new Table<char>("<coding>");

    visitChildren(ctx);

    LSystem<char>* lsys;

    if (this->errors()->size() == 0) {
        lsys = new LSystem<char>();

        if (ctx->name())
            lsys->name = this->visitName(ctx->name()).as<std::string>();
        lsys->tables = this->tables;
        // lsys->tablesList = this->tablesList;
        lsys->defaultTable = this->defaultTable;
        lsys->codingRules = this->codingRules;
        lsys->taggedRules = this->taggedRules;
        if (this->env->has("table_func")) {
            Value v = this->env->get("table_func");
            if (v.isFunction() && v.asFunction()->params()->size() == 1)
                lsys->tableFunc = v.asFunction();
            else
                this->error("table_func must be a function with one parameter");
        }
        if (this->env->has("axiom")) {
            Value v = this->env->get("axiom");
            if (v.isString()) {
                std::string axiom = v.asString();
                lsys->axiom = this->parseInstanceNode(axiom);
            } else
                this->error("axiom must be a string");
        }
        if (this->env->has("iterations")) {
            Value v = this->env->get("iterations");
            if (v.isInt())
                lsys->iterations = v.asInt();
            else
                this->error("iterations must be a integer number");
        }
        if (this->env->has("ignore")) {
            Value v = this->env->get("ignore");
            if (v.isString()) {
                std::string ignore = v.asString();
                lsys->ignore = new std::list<char>(ignore.begin(), ignore.end());
            } else
                this->error("ignore must be a string");
        }
        if (this->env->has("initial_heading")) {
            Value v = this->env->get("initial_heading");
            if (v.isFloat())
                lsys->initialHeading = v.asFloat();
            else if (v.isInt())
                lsys->initialHeading = v.asInt();
            else
                this->error("initial_heading must be a number");
        }
        if (this->env->has("rotation")) {
            Value v = this->env->get("rotation");
            if (v.isFloat())
                lsys->initialHeading = v.asFloat();
            else if (v.isInt())
                lsys->initialHeading = v.asInt();
            else
                this->error("rotation must be a number");
        }
        lsys->env = this->env;
    }

    if (this->errors()->size() > 0) {
        this->dumpErrors();
        lsys = nullptr;
    }

    return lsys;
}

antlrcpp::Any LSysDVisitor::visitName(LSysDParser::NameContext *ctx) {
    return ctx->ID()->getText();
}

antlrcpp::Any LSysDVisitor::visitDefinitions(LSysDParser::DefinitionsContext *ctx) {
    return visitChildren(ctx);
}

antlrcpp::Any LSysDVisitor::visitDefinition(LSysDParser::DefinitionContext *ctx) {
    // if (ctx->ruleDef()) {
    //     this->currentTable = this->defaultTable;
    //     this->visitRuleDef(ctx->ruleDef());
    //     this->currentTable = nullptr;
    //     return nullptr;
    // }
    return visitChildren(ctx);
}

antlrcpp::Any LSysDVisitor::visitPropDef(LSysDParser::PropDefContext *ctx) {
    std::string pname = ctx->ID()->getText();
    if (this->env->has(pname))
        this->error("'" + pname + "' field already defined", ctx->ID());
    // LSysDParser::ExpressionContext* expr = ctx->expression();
    Value val = eval(ctx->expression(), this->env);
    // TODO: Propagar error de eval
    this->env->set(pname, val);
    // std::cout << "PROP" << std::endl;
    // std::cout << (val.is<std::string*>()) << std::endl;
    // std::cout << (val2.is<std::string*>()) << std::endl;
    // std::cout << (this->env->get(pname).is<std::string*>()) << std::endl;
    // std::cout << *(val2.as<std::string*>()) << std::endl;
    return nullptr;
}

antlrcpp::Any LSysDVisitor::visitFuncDef(LSysDParser::FuncDefContext *ctx) {
    std::string fname = ctx->ID()->getText();
    if (this->env->has(fname))
        this->error("'" + fname + "' field already defined", ctx->ID());
    // LSysDParser::ExpressionContext* expr = ctx->expression();
    std::list<Parameter*>* params = this->visitParams(ctx->params());
    this->env->set(fname, new Function(params, ctx->expression(), ctx));
    return nullptr;
}

// antlrcpp::Any LSysDVisitor::visitConstDef(LSysDParser::ConstDefContext *ctx) {
//     return visitChildren(ctx);
// }

antlrcpp::Any LSysDVisitor::visitTableBlock(LSysDParser::TableBlockContext *ctx) {
    this->parentTrace = this->trace(ctx->KWTABLE()->getSymbol(), ctx->ID()->getSymbol(), this->parentTrace);
    std::string tid = ctx->ID()->getText();
    Table<char>* table = new Table<char>(tid);
    this->currentTable = table;
    if (this->tables->find(tid) != this->tables->end())
        this->error("table with name '" + tid + "' is already defined", ctx->ID());
    (*this->tables)[tid] = table;
    this->tablesList->push_back(table);
    this->visitRules(ctx->rules());
    // table->rules = rules;
    this->currentTable = nullptr;
    this->parentTrace = nullptr;
    return nullptr;
}

antlrcpp::Any LSysDVisitor::visitRulesBlock(LSysDParser::RulesBlockContext *ctx) {
    this->parentTrace = this->trace(ctx->KWRULES()->getSymbol(), ctx->KWRULES()->getSymbol(), this->parentTrace);
    // this->currentTable = this->defaultTable;
    this->visitRuleDefs(ctx->ruleDefs());
    // this->currentTable = nullptr;
    this->parentTrace = nullptr;
    return nullptr;
}

antlrcpp::Any LSysDVisitor::visitProductionRulesBlock(LSysDParser::ProductionRulesBlockContext *ctx) {
    this->parentTrace = this->trace(ctx->KWPRODUCTION()->getSymbol(), ctx->KWRULES()->getSymbol(), this->parentTrace);
    this->currentTable = this->defaultTable;
    this->visitRuleDefs(ctx->ruleDefs());
    this->currentTable = nullptr;
    this->parentTrace = nullptr;
    return nullptr;
}

antlrcpp::Any LSysDVisitor::visitCodingRulesBlock(LSysDParser::CodingRulesBlockContext *ctx) {
    this->parentTrace = this->trace(ctx->KWCODING()->getSymbol(), ctx->KWRULES()->getSymbol(), this->parentTrace);
    this->currentTable = this->codingRules;
    this->visitRuleDefs(ctx->ruleDefs());
    this->currentTable = nullptr;
    this->parentTrace = nullptr;
    return nullptr;
}

antlrcpp::Any LSysDVisitor::visitRules(LSysDParser::RulesContext *ctx) {
    return visitChildren(ctx);
}

antlrcpp::Any LSysDVisitor::visitRuleDefs(LSysDParser::RuleDefsContext *ctx) {
    return visitChildren(ctx);
}

antlrcpp::Any LSysDVisitor::visitProductionRuleDefs(LSysDParser::ProductionRuleDefsContext *ctx) {
    return visitChildren(ctx);
}

antlrcpp::Any LSysDVisitor::visitCodingRuleDefs(LSysDParser::CodingRuleDefsContext *ctx) {
    return visitChildren(ctx);
}

antlrcpp::Any LSysDVisitor::visitAnyRule(LSysDParser::AnyRuleContext *ctx) {
    return visitChildren(ctx);
}

antlrcpp::Any LSysDVisitor::visitProductionRule(LSysDParser::ProductionRuleContext *ctx) {
    if (ctx->productionRuleDef()) {
        return this->visitProductionRuleDef(ctx->productionRuleDef());
    } else {
        std::string tag = this->visitTag(ctx->tag());
        if (this->taggedRules->find(tag) != this->taggedRules->end()) {
            Rule<char>* rule = this->taggedRules->at(tag);
            if (rule->isProductionRule()) {
                this->currentTable->addRule(rule);
                // return rule;
            } else
                this->error("production rule reference expected, but a coding rule reference was found", ctx->tag());
        } else
            this->error("the tag '" + tag + "' does not point to any existing rule", ctx->tag());
    }
    return nullptr;
}

antlrcpp::Any LSysDVisitor::visitCodingRule(LSysDParser::CodingRuleContext *ctx) {
    return visitChildren(ctx);
}

antlrcpp::Any LSysDVisitor::visitRuleDef(LSysDParser::RuleDefContext *ctx) {
    return visitChildren(ctx);
}

antlrcpp::Any LSysDVisitor::visitProductionRuleDef(LSysDParser::ProductionRuleDefContext *ctx) {
    if (this->currentTable == this->codingRules)
        this->error("trying to define a production rule inside a coding rules block", ctx->ARROW());
    else {
        ProductionRule<char>* rule = this->defineRule<ProductionRule<char>>(
            ctx->tagPrefix(), 
            ctx->weight(), 
            ctx->lcontext(), 
            ctx->lside(), 
            ctx->rcontext(), 
            ctx->rside()
        );
        Table<char>* t = this->currentTable;
        if (t == nullptr)
            t = this->defaultTable;
        t->addRule(reinterpret_cast<Rule<char>*>(rule));
    }
    return nullptr;
}

antlrcpp::Any LSysDVisitor::visitCodingRuleDef(LSysDParser::CodingRuleDefContext *ctx) {
    if (this->currentTable == this->defaultTable)
        this->error("trying to define a coding rule inside a production block", ctx->DARROW());
    else if (this->currentTable && this->currentTable != this->codingRules)
        this->error("trying to define a coding rule inside a table block", ctx->DARROW());
    else {
        CodingRule<char>* rule = this->defineRule<CodingRule<char>>(
            ctx->tagPrefix(), 
            ctx->weight(), 
            ctx->lcontext(), 
            ctx->lside(), 
            ctx->rcontext(), 
            ctx->rside()
        );
        this->codingRules->addRule(reinterpret_cast<Rule<char>*>(rule));
    }
    return nullptr;
}


template<class R> 
R* LSysDVisitor::defineRule(LSysDParser::TagPrefixContext* tagCtx, 
                            LSysDParser::WeightContext* weightCtx, 
                            LSysDParser::LcontextContext* lctxCtx, 
                            LSysDParser::LsideContext* lsideCtx, 
                            LSysDParser::RcontextContext* rctxCtx, 
                            LSysDParser::RsideContext* rsideCtx) {
    // Tag:
    std::string tag;
    if (tagCtx)
        tag = this->visitTagPrefix(tagCtx).as<std::string>();
    else
        tag = "";

    // Weight:
    weight_t weight;
    if (weightCtx)
        weight = this->visitWeight(weightCtx);
    else
        weight = Rule<char>::WEIGHT_UNSET;

    // Left context:
    ParseTreeNode<LeftSideNodeContent, char>* lctx;
    if (lctxCtx)
        lctx = this->visitLcontext(lctxCtx);
    else
        lctx = nullptr;

    // Left char:
    ParseTreeNode<LeftSideNodeContent, char>* lnode = this->visitLside(lsideCtx);

    // Right context:
    ParseTreeNode<LeftSideNodeContent, char>* rctx;
    if (rctxCtx)
        rctx = this->visitRcontext(rctxCtx);
    else
        rctx = nullptr;

    // Right side:
    ParseTreeNode<RightSideNodeContent, char>* rside = this->visitRside(rsideCtx);

    // Assemble rule:
    R* rule = new R(tag, weight, lctx, lnode, rctx, rside);

    if (tag != "")
        (*this->taggedRules)[tag] = reinterpret_cast<Rule<char>*>(rule);

    return rule;
}


antlrcpp::Any LSysDVisitor::visitTagPrefix(LSysDParser::TagPrefixContext *ctx) {
    std::string tag = this->visitTag(ctx->tag());
    if (this->taggedRules->find(tag) != this->taggedRules->end())
        this->error("tag '" + tag + "' already defined", ctx->tag());
    return tag;
}

antlrcpp::Any LSysDVisitor::visitTag(LSysDParser::TagContext *ctx) {
    return ctx->ID()->getText();
}

antlrcpp::Any LSysDVisitor::visitWeight(LSysDParser::WeightContext *ctx) {
    weight_t weight;
    if (ctx->INT()) {
        if (ctx->INT()->getText().find('x') == std::string::npos)
            weight = static_cast<weight_t>(stoi(ctx->INT()->getText()));
        else {
            weight = Rule<char>::WEIGHT_UNSET;
            this->error("rule weight must be a decimal number", ctx->INT());
        }
    } else
        weight = Rule<char>::WEIGHT_ALWAYS;
    return weight;
}

antlrcpp::Any LSysDVisitor::visitLside(LSysDParser::LsideContext *ctx) {
    ParseTreeNode<LeftSideNodeContent, char>* parent = new ParseTreeNode<LeftSideNodeContent, char>();
    this->parentNode = parent->asGeneric();
    this->visitLChar(ctx->lChar());
    this->parentNode = nullptr;
    if (parent->size() != 1)
        this->error("the left side of the arrow (excluding contexts) must be of length 1", 
                ctx->lChar()->validLeftChar());
    return parent->leftmostChild();
}

antlrcpp::Any LSysDVisitor::visitLcontext(LSysDParser::LcontextContext *ctx) {
    ParseTreeNode<LeftSideNodeContent, char>* parent = new ParseTreeNode<LeftSideNodeContent, char>();
    this->parentNode = parent->asGeneric();
    for (LSysDParser::LItemContext* lictx : ctx->lItem())
        this->visitLItem(lictx);
    this->parentNode = nullptr;
    return parent;
}

antlrcpp::Any LSysDVisitor::visitRcontext(LSysDParser::RcontextContext *ctx) {
    ParseTreeNode<LeftSideNodeContent, char>* parent = new ParseTreeNode<LeftSideNodeContent, char>();
    this->parentNode = parent->asGeneric();
    for (LSysDParser::LItemContext* lictx : ctx->lItem())
        this->visitLItem(lictx);
    this->parentNode = nullptr;
    return parent;
}

antlrcpp::Any LSysDVisitor::visitRside(LSysDParser::RsideContext *ctx) {
    ParseTreeNode<RightSideNodeContent, char>* parent = new ParseTreeNode<RightSideNodeContent, char>();
    this->parentNode = parent->asGeneric();
    for (LSysDParser::RItemContext* rictx : ctx->rItem())
        this->visitRItem(rictx);
    this->parentNode = nullptr;
    return parent;
}

antlrcpp::Any LSysDVisitor::visitWord(LSysDParser::WordContext *ctx) {
    ParseTreeNode<InstanceNodeContent, char>* parent = new ParseTreeNode<InstanceNodeContent, char>();
    this->parentNode = parent->asGeneric();
    for (LSysDParser::RItemContext* rictx : ctx->rItem())
        this->visitRItem(rictx);
    this->parentNode = nullptr;
    return parent;
}

antlrcpp::Any LSysDVisitor::visitLChar(LSysDParser::LCharContext *ctx) {
    this->visitValidLeftChar(ctx->validLeftChar());
    if (ctx->paramsWithCond()) {
        auto paramsCond = this->visitParamsWithCond(ctx->paramsWithCond())
            .as<std::pair<std::list<Parameter*>*, LSysDParser::ExpressionContext*>>();
        ParseTreeNode<LeftSideNodeContent, char>* rgt = 
                reinterpret_cast<ParseTreeNode<LeftSideNodeContent, char>*>(
                    this->parentNode->rightmostChild());
        rgt->content()->params = paramsCond.first;
        if (paramsCond.second != nullptr)
            rgt->content()->cond = paramsCond.second;
    }
    return nullptr;
}

antlrcpp::Any LSysDVisitor::visitLItem(LSysDParser::LItemContext *ctx) {
    if (ctx->validLeftChar()) {
        this->visitValidLeftChar(ctx->validLeftChar());
        if (ctx->paramsWithCond()) {
            std::pair<std::list<Parameter*>*, LSysDParser::ExpressionContext*> paramsCond = 
                    this->visitParamsWithCond(ctx->paramsWithCond());
            ParseTreeNode<LeftSideNodeContent, char>* rgt = 
                    reinterpret_cast<ParseTreeNode<LeftSideNodeContent, char>*>(
                        this->parentNode->rightmostChild());
            rgt->content()->params = paramsCond.first;
            if (paramsCond.second != nullptr)
                rgt->content()->cond = paramsCond.second;
        }
    } else {
        ParseTreeNode<LeftSideNodeContent, char>* node = new ParseTreeNode<LeftSideNodeContent, char>();
        this->parentNode->addChild(node->asGeneric());
        this->parentNode = node->asGeneric();
        for (LSysDParser::LItemContext* lictx : ctx->lItem())
            this->visitLItem(lictx);
        this->parentNode = node->parent()->asGeneric();
    }
    return nullptr;
}

antlrcpp::Any LSysDVisitor::visitRItem(LSysDParser::RItemContext *ctx) {
    if (ctx->validRightChar()) {
        this->visitValidRightChar(ctx->validRightChar());
        if (ctx->args()) {
            std::list<LSysDParser::ExpressionContext*>* args = this->visitArgs(ctx->args());
            ParseTreeNode<NodeContent, char>* rgt = this->parentNode->rightmostChild();
            if (!this->parentNode->isInstance()) {
                reinterpret_cast<RightSideNodeContent<char>*>(rgt->content())->args = args;
            } else {
                std::list<Value>* values = new std::list<Value>();
                for (LSysDParser::ExpressionContext* exprctx : *args)
                    values->push_back(eval(exprctx, this->env));
                delete args;
                reinterpret_cast<InstanceNodeContent<char>*>(rgt->content())->values = values;
            }
        }
    } else {
        ParseTreeNode<NodeContent, char>* node;
        if (!this->parentNode->isInstance())
            node = (new ParseTreeNode<RightSideNodeContent, char>())->asGeneric();
        else
            node = (new ParseTreeNode<InstanceNodeContent, char>())->asGeneric();
        this->parentNode->addChild(node);
        this->parentNode = node;
        for (LSysDParser::RItemContext* rictx : ctx->rItem())
            this->visitRItem(rictx);
        this->parentNode = node->parent();
    }
    return nullptr;
}

antlrcpp::Any LSysDVisitor::visitValidLeftChar(LSysDParser::ValidLeftCharContext *ctx) {
    std::string s = this->visitValidChar(ctx->validChar());
    for (char c : s) {
        ParseTreeNode<LeftSideNodeContent, char>* node = new ParseTreeNode<LeftSideNodeContent, char>(c);
        this->parentNode->addChild(node->asGeneric());
    }
    return nullptr;
}

antlrcpp::Any LSysDVisitor::visitValidRightChar(LSysDParser::ValidRightCharContext *ctx) {
    std::string s = this->visitValidChar(ctx->validChar());
    // int pos = 0;
    for (char c : s) {
        if (c == '_')
            this->error("'_' (underscore) character is not valid for the right side of a rule", ctx);
        ParseTreeNode<NodeContent, char>* node;
        if (!this->parentNode->isInstance())
            node = (new ParseTreeNode<RightSideNodeContent, char>(c))->asGeneric();
        else
            node = (new ParseTreeNode<InstanceNodeContent, char>(c))->asGeneric();
        this->parentNode->addChild(node);
        // ++pos;
    }
    return nullptr;
}

antlrcpp::Any LSysDVisitor::visitValidChar(LSysDParser::ValidCharContext *ctx) {
    return ctx->getText();
}

antlrcpp::Any LSysDVisitor::visitParamsWithCond(LSysDParser::ParamsWithCondContext *ctx) {
    std::list<Parameter*>* params = this->visitParams(ctx->params());
    LSysDParser::ExpressionContext* cond;
    if (ctx->cond())
        cond = this->visitCond(ctx->cond());
    else
        cond = nullptr;
    return make_pair(params, cond);
}

antlrcpp::Any LSysDVisitor::visitParams(LSysDParser::ParamsContext *ctx) {
    std::list<Parameter*>* params = new std::list<Parameter*>();
    for (LSysDParser::ParamContext* paramctx : ctx->param())
        params->push_back(this->visitParam(paramctx));
    return params;
}

antlrcpp::Any LSysDVisitor::visitParam(LSysDParser::ParamContext *ctx) {
    return new Parameter(ctx->ID()->getText());
}

antlrcpp::Any LSysDVisitor::visitCond(LSysDParser::CondContext *ctx) {
    return ctx->expression();
}

antlrcpp::Any LSysDVisitor::visitArgs(LSysDParser::ArgsContext *ctx) {
    std::list<LSysDParser::ExpressionContext*>* args = new std::list<LSysDParser::ExpressionContext*>();
    for (LSysDParser::ArgContext* argctx : ctx->arg())
        args->push_back(this->visitArg(argctx));
    return args;
}

antlrcpp::Any LSysDVisitor::visitArg(LSysDParser::ArgContext *ctx) {
    return ctx->expression();
}
