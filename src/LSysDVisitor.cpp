
#include "LSysDVisitor.h"

#include "misc.h"

#include <utility>
// #include <sstream>
// #include <regex>


// ParseTreeNode<InstanceNodeContent, char>* LSysDVisitor::parseInstanceNode(std::string s) {
//     std::stringstream ss;
//     ss << s;
//     antlr4::ANTLRInputStream input(ss);
//     LSysDLexer lexer(&input);
//     antlr4::CommonTokenStream tokens(&lexer);
//     LSysDParser parser(&tokens);

//     if (parser.getNumberOfSyntaxErrors() != 0)
//         return nullptr;

//     antlr4::tree::ParseTree *tree = parser.word();

//     // TreeShapeListener listener;
//     // tree::ParseTreeWalker::DEFAULT.walk(&listener, tree);

//     Scope* childEnv = new Scope(this->scope);
//     childEnv->set("i", 0);
//     LSysDVisitor visitor("<axiom>", new std::vector<std::string> {s}, childEnv);
//     ParseTreeNode<InstanceNodeContent, char>* node = visitor.visit(tree);

//     if (visitor.eh->failed()) {
//         visitor.eg->dump();
//         return nullptr;
//     }

//     return node;
// }

LSysDVisitor::LSysDVisitor(std::string const& filename, std::vector<std::string> const* sourceLines, Scope * scope, StackTrace const* trace) {
    this->eh = new ErrorHandler(filename, sourceLines, trace);

    this->currentLSystem = nullptr;
    this->currentTable = nullptr;
    this->parentNode = nullptr;

    this->baseScope = scope != nullptr ? new Scope(scope) : nullptr;
    this->currentScope = nullptr;

    // this->scope = scope ? new Scope(scope) : new Scope();
    // this->taggedRules = new std::map<std::string, Rule<char>*>();
    // this->tables = new std::map<std::string, Table<char>*>();
    // this->codingRules = new Table<char>("<default>");
}

LSysDVisitor::~LSysDVisitor() {
    // delete eh;
}

ErrorHandler* LSysDVisitor::messages() {return eh;}

// Value LSysDVisitor::eval(LSysDParser::ExpressionContext* ctx) {
//     return this->evaluator->eval(ctx);
// }



antlrcpp::Any LSysDVisitor::visitMain(LSysDParser::MainContext *ctx) {
    std::string moduleName;
    if (eh->stdin())
        moduleName = eh->fileName();
    else {
        moduleName = getModuleName(eh->fileName());
        if (moduleName.size() > 0) {
            // std::regex_replace(moduleName, std::regex("[-]"), "_");
            // std::regex_replace(moduleName, std::regex("[^a-zA-Z0-9_]"), "");
        } else {
            eh->error("The input file name must end in .lsd", eh->trace(ctx->stop));
            return static_cast<Module<char> *>(nullptr);
        }
    }
    module = new Module<char>(moduleName);
    module->eh = eh; //new ErrorHandler(eh);
    module->_scope = new Scope(baseScope);
    module->_evaluator = new LSysDExpressionEvaluator(eh);
    currentScope = module->_scope;
    if (ctx->module()) {
        visitChildren(ctx);
        if (eh->failed() > 0 || module->eh->failed())
            return static_cast<Module<char> *>(nullptr);
    } else {
        currentLSystem = new LSystem<char>(module);
        currentLSystem->_name = module->_name;
        currentScope = currentLSystem->_scope;
        if (ctx->inLsysDefs()) {
            visitChildren(ctx);
            if (currentLSystem->_axiom == nullptr)
                eh->error("No axiom is defined in the L system in file " + eh->fileName(), eh->trace(ctx->stop));
        // } else if (ctx->word()) {
        //     currentLSystem->_axiom = this->visitWord(ctx->word());
        }
        if (eh->failed() || module->eh->failed())
            return static_cast<Module<char> *>(nullptr);
        currentScope = currentScope->parent();
        eh->traceDown(eh->trace(ctx->stop));
        currentLSystem->populateProperties();
        eh->traceUp();
        module->_lsystems[currentLSystem->_name] = currentLSystem;
        currentLSystem = nullptr;
    }
    currentScope = currentScope->parent();
    
    if (module->_mainLSystem == nullptr) {
        if (module->_lsystems.size() == 1) {
            module->_mainLSystem = module->_lsystems.begin()->second;
            if (ctx->module())
                eh->warning("You should mark one L system as main", eh->trace(ctx->stop));
        } else {
            for (auto ls : module->_lsystems) {
                if (ls.second->_name == module->_name) {
                    module->_mainLSystem = ls.second;
                    break;
                }
            }
            if (module->_mainLSystem == nullptr) {
                eh->error("No L system marked as main in " + eh->fileName(), eh->trace(ctx->stop));
                return static_cast<Module<char> *>(nullptr);
            } else {
                eh->warning("You should mark one L system as main", eh->trace(ctx->stop));
            }
        }
    }

    return this->module;
}

antlrcpp::Any LSysDVisitor::visitLsystem(LSysDParser::LsystemContext *ctx) {
    currentLSystem = new LSystem<char>(module);
    currentLSystem->_name = ctx->ID()->getText();
    if (module->_lsystems.find(currentLSystem->_name) != module->_lsystems.end())
        eh->error("L system " + currentLSystem->_name + " is already defined", eh->trace(ctx->ID()));
    currentScope = currentLSystem->_scope;
    // eh->traceDown(eh->trace(ctx->ID(), nullptr, "in LSystem:"));
    visitChildren(ctx);
    if (currentLSystem->_axiom == nullptr)
        eh->error("No axiom is defined in the L system " + currentLSystem->_name, eh->trace(ctx->ID()));
    // eh->traceUp();
    currentScope = currentScope->parent();
    eh->traceDown(eh->trace(ctx->ID()));
    if (!eh->failed())
        currentLSystem->populateProperties();
    eh->traceUp();
    module->_lsystems[currentLSystem->_name] = currentLSystem;
    if (ctx->KWMAIN()) {
        if (module->_mainLSystem != nullptr)
            eh->error("Only one LSystem must be marked as main", eh->trace(ctx->KWMAIN()));
        module->_mainLSystem = currentLSystem;
    }
    currentLSystem = nullptr;
    return nullptr;
}

antlrcpp::Any LSysDVisitor::visitAxiomDef(LSysDParser::AxiomDefContext *ctx) {
    if (currentLSystem->_axiom == nullptr) {
        currentLSystem->_axiom = this->visitWord(ctx->word()).as<ParseTreeNode<InstanceNodeContent, char> *>();
    } else {
        eh->error("The axiom is already defined", eh->trace(ctx));
    }
    return nullptr;
}

antlrcpp::Any LSysDVisitor::visitConstDeclaration(LSysDParser::ConstDeclarationContext *ctx) {
    std::string pname = ctx->ID()->getText();
    if (currentScope->has(pname))
        eh->error("'" + pname + "' symbol is already defined", eh->trace(ctx->ID()));
    Value val = module->_evaluator->eval(ctx->expression(), currentScope);
    currentScope->set(pname, val);
    // std::cout << "PROP" << std::endl;
    // std::cout << (val.is<std::string*>()) << std::endl;
    // std::cout << (val2.is<std::string*>()) << std::endl;
    // std::cout << (currentScope->get(pname).is<std::string*>()) << std::endl;
    // std::cout << *(val2.as<std::string*>()) << std::endl;
    return nullptr;
}

antlrcpp::Any LSysDVisitor::visitVarDeclaration(LSysDParser::VarDeclarationContext *ctx) {
    std::string pname = ctx->ID()->getText();
    if (currentScope->has(pname))
        eh->error("'" + pname + "' symbol is already defined", eh->trace(ctx->ID()));
    Value val = module->_evaluator->eval(ctx->expression(), currentScope);
    currentScope->set(pname, val);
    return nullptr;
}

antlrcpp::Any LSysDVisitor::visitFuncDef(LSysDParser::FuncDefContext *ctx) {
    std::string fname = ctx->ID()->getText();
    if (currentScope->has(fname))
        eh->error("'" + fname + "' symbol is already defined", eh->trace(ctx->ID()));
    // LSysDParser::ExpressionContext* expr = ctx->expression();
    std::list<Parameter*>* params = this->visitParams(ctx->params()).as<std::list<Parameter *> *>();
    currentScope->set(fname, new Function(params, ctx->expression(), ctx));
    // currentScope->set(fname, new Function(params, ctx->block(), ctx));
    return nullptr;
}

// antlrcpp::Any LSysDVisitor::visitConstDef(LSysDParser::ConstDefContext *ctx) {
//     return visitChildren(ctx);
// }

antlrcpp::Any LSysDVisitor::visitTableBlock(LSysDParser::TableBlockContext *ctx) {
    // eh->traceDown(eh->trace(ctx->KWTABLE()->getSymbol(), ctx->ID()->getSymbol(), "in block:"));
    std::string tid = ctx->ID()->getText();
    Table<char>* table = new Table<char>(tid);
    currentTable = table;
    if (currentLSystem->_tables.find(tid) != currentLSystem->_tables.end())
        eh->error("table with name '" + tid + "' is already defined", eh->trace(ctx->ID()));
    currentLSystem->_tables[tid] = table;
    // module->tablesList->push_back(table);
    this->visitRules(ctx->rules());
    // table->rules = rules;
    currentTable = nullptr;
    // eh->traceUp();
    return nullptr;
}

antlrcpp::Any LSysDVisitor::visitRulesBlock(LSysDParser::RulesBlockContext *ctx) {
    // eh->traceDown(eh->trace(ctx->KWRULES()->getSymbol(), ctx->KWRULES()->getSymbol(), "in block:"));
    // this->currentTable = this->defaultTable;
    this->visitRuleDefs(ctx->ruleDefs());
    // this->currentTable = nullptr;
    // eh->traceUp();
    return nullptr;
}

antlrcpp::Any LSysDVisitor::visitProductionRulesBlock(LSysDParser::ProductionRulesBlockContext *ctx) {
    // eh->traceDown(eh->trace(ctx->KWPRODUCTION()->getSymbol(), ctx->KWRULES()->getSymbol(), "in block:"));
    currentTable = currentLSystem->_defaultTable;
    this->visitRuleDefs(ctx->ruleDefs());
    currentTable = nullptr;
    // eh->traceUp();
    return nullptr;
}

antlrcpp::Any LSysDVisitor::visitCodingRulesBlock(LSysDParser::CodingRulesBlockContext *ctx) {
    // eh->traceDown(eh->trace(ctx->KWCODING()->getSymbol(), ctx->KWRULES()->getSymbol(), "in block:"));
    currentTable = currentLSystem->_codingRules;
    this->visitRuleDefs(ctx->ruleDefs());
    currentTable = nullptr;
    // eh->traceUp();
    return nullptr;
}

antlrcpp::Any LSysDVisitor::visitProductionRule(LSysDParser::ProductionRuleContext *ctx) {
    // if (ctx->productionRuleDef()) {
    return this->visitProductionRuleDef(ctx->productionRuleDef());
    // } else {
    //     std::string tag = this->visitTag(ctx->tag());
    //     if (currentLSystem->_taggedRules.find(tag) != currentLSystem->_taggedRules.end()) {
    //         Rule<char>* rule = currentLSystem->_taggedRules.at(tag);
    //         if (rule->isProductionRule()) {
    //             this->currentTable->addRule(rule);
    //             // return rule;
    //         } else
    //             eh->error("production rule reference expected, but a coding rule reference was found", eh->trace(ctx->tag()));
    //     } else
    //         eh->error("the tag '" + tag + "' does not point to any existing rule", eh->trace(ctx->tag()));
    // }
    // return nullptr;
}

antlrcpp::Any LSysDVisitor::visitCodingRule(LSysDParser::CodingRuleContext *ctx) {
    return visitChildren(ctx);
}

antlrcpp::Any LSysDVisitor::visitRuleDef(LSysDParser::RuleDefContext *ctx) {
    return visitChildren(ctx);
}


template<class R> 
R* LSysDVisitor::defineRule(// LSysDParser::TagPrefixContext* tagCtx, 
                            LSysDParser::WeightContext* weightCtx, 
                            LSysDParser::LcontextContext* lctxCtx, 
                            LSysDParser::LsideContext* lsideCtx, 
                            LSysDParser::RcontextContext* rctxCtx, 
                            LSysDParser::CondContext* condCtx, 
                            LSysDParser::RsideContext* rsideCtx) {
    // // Tag:
    // std::string tag;
    // if (tagCtx)
    //     tag = this->visitTagPrefix(tagCtx).as<std::string>();
    // else
    //     tag = "";

    // Weight:
    weight_t weight;
    if (weightCtx)
        weight = this->visitWeight(weightCtx).as<weight_t>();
    else
        weight = Rule<char>::WEIGHT_UNSET;

    // Left context:
    ParseTreeNode<LeftSideNodeContent, char>* lctx;
    if (lctxCtx)
        lctx = this->visitLcontext(lctxCtx).as<ParseTreeNode<LeftSideNodeContent, char> *>();
    else
        lctx = nullptr;

    // Left char:
    ParseTreeNode<LeftSideNodeContent, char>* lnode = this->visitLside(lsideCtx)
            .as<ParseTreeNode<LeftSideNodeContent, char> *>();

    // Right context:
    ParseTreeNode<LeftSideNodeContent, char>* rctx;
    if (rctxCtx)
        rctx = this->visitRcontext(rctxCtx).as<ParseTreeNode<LeftSideNodeContent, char> *>();
    else
        rctx = nullptr;

    // Condition:
    LSysDParser::ExpressionContext* cond;
    if (condCtx)
        cond = condCtx->expression();
    else
        cond = nullptr;

    // Right side:
    ParseTreeNode<RightSideNodeContent, char>* rside = this->visitRside(rsideCtx)
            .as<ParseTreeNode<RightSideNodeContent, char> *>();

    // Assemble rule:
    R* rule = new R(weight, lctx, lnode, rctx, cond, rside);

    // if (tag != "")
    //     currentLSystem->_taggedRules[tag] = reinterpret_cast<Rule<char>*>(rule);

    return rule;
}


antlrcpp::Any LSysDVisitor::visitProductionRuleDef(LSysDParser::ProductionRuleDefContext *ctx) {
    if (this->currentTable == currentLSystem->_codingRules)
        eh->error("trying to define a production rule inside a coding rules block", eh->trace(ctx->ARROW()));
    else {
        ProductionRule<char>* rule = defineRule<ProductionRule<char>>(
            // ctx->tagPrefix(), 
            ctx->weight(), 
            ctx->lcontext(), 
            ctx->lside(), 
            ctx->rcontext(), 
            ctx->cond(), 
            ctx->rside()
        );
        Table<char>* t = this->currentTable;
        if (t == nullptr)
            t = currentLSystem->_defaultTable;
        t->addRule(reinterpret_cast<Rule<char>*>(rule));
    }
    return nullptr;
}

antlrcpp::Any LSysDVisitor::visitCodingRuleDef(LSysDParser::CodingRuleDefContext *ctx) {
    if (this->currentTable == currentLSystem->_defaultTable)
        eh->error("trying to define a coding rule inside a production block", eh->trace(ctx->DARROW()));
    else if (this->currentTable && this->currentTable != currentLSystem->_codingRules)
        eh->error("trying to define a coding rule inside a table block", eh->trace(ctx->DARROW()));
    else {
        CodingRule<char>* rule = defineRule<CodingRule<char>>(
            // ctx->tagPrefix(), 
            ctx->weight(), 
            ctx->lcontext(), 
            ctx->lside(), 
            ctx->rcontext(), 
            ctx->cond(), 
            ctx->rside()
        );
        currentLSystem->_codingRules->addRule(reinterpret_cast<Rule<char>*>(rule));
    }
    return nullptr;
}

antlrcpp::Any LSysDVisitor::visitTagPrefix(LSysDParser::TagPrefixContext *ctx) {
    std::string tag = this->visitTag(ctx->tag()).as<std::string>();
    if (currentLSystem->_taggedRules.find(tag) != currentLSystem->_taggedRules.end())
        eh->error("tag '" + tag + "' is already defined", eh->trace(ctx->tag()));
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
            eh->error("rule weight must be a decimal number", eh->trace(ctx->INT()));
        }
    } else if (ctx->FLOAT()) {
        weight = stof(ctx->FLOAT()->getText());
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
        eh->error("the left side of the arrow (excluding contexts) must be of length 1", 
                eh->trace(ctx->lChar()->validLeftChar()));
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
    if (ctx->params()) {
        std::list<Parameter *> * params = this->visitParams(ctx->params()).as<std::list<Parameter *> *>();
        ParseTreeNode<LeftSideNodeContent, char>* rgt = 
                reinterpret_cast<ParseTreeNode<LeftSideNodeContent, char>*>(
                    this->parentNode->rightmostChild());
        rgt->content().params = params;
    }
    return nullptr;
}

antlrcpp::Any LSysDVisitor::visitLItem(LSysDParser::LItemContext *ctx) {
    if (ctx->validLeftChar()) {
        this->visitValidLeftChar(ctx->validLeftChar());
        if (ctx->params()) {
            std::list<Parameter *> * params = this->visitParams(ctx->params()).as<std::list<Parameter *> *>();
            ParseTreeNode<LeftSideNodeContent, char>* rgt = 
                    reinterpret_cast<ParseTreeNode<LeftSideNodeContent, char>*>(
                        this->parentNode->rightmostChild());
            rgt->content().params = params;
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
            std::list<LSysDParser::ExpressionContext *> * args = this->visitArgs(ctx->args())
                    .as<std::list<LSysDParser::ExpressionContext *> *>();
            ParseTreeNode<NodeContent, char>* rgt = this->parentNode->rightmostChild();
            if (!this->parentNode->isInstance()) {
                reinterpret_cast<RightSideNodeContent<char>*>(&rgt->content())->args = args;
            } else {
                std::vector<Value>* values = new std::vector<Value>();
                for (LSysDParser::ExpressionContext* exprctx : *args)
                    values->push_back(module->_evaluator->eval(exprctx, currentScope));
                delete args;
                reinterpret_cast<InstanceNodeContent<char>*>(&rgt->content())->values = values;
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
    std::string s = this->visitValidChar(ctx->validChar()).as<std::string>();
    for (char c : s) {
        ParseTreeNode<LeftSideNodeContent, char>* node = new ParseTreeNode<LeftSideNodeContent, char>(c);
        this->parentNode->addChild(node->asGeneric());
    }
    return nullptr;
}

antlrcpp::Any LSysDVisitor::visitValidRightChar(LSysDParser::ValidRightCharContext *ctx) {
    std::string s = this->visitValidChar(ctx->validChar()).as<std::string>();
    // int pos = 0;
    for (char c : s) {
        if (c == '_')
            eh->error("'_' (underscore) character is not valid for the right side of a rule or for an axiom", eh->trace(ctx));
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

antlrcpp::Any LSysDVisitor::visitParams(LSysDParser::ParamsContext *ctx) {
    std::list<Parameter *> * params = new std::list<Parameter *>();
    for (LSysDParser::ParamContext* paramctx : ctx->param())
        params->push_back(this->visitParam(paramctx).as<Parameter *>());
    return params;
}

antlrcpp::Any LSysDVisitor::visitParam(LSysDParser::ParamContext *ctx) {
    return new Parameter(ctx->ID()->getText());
}

antlrcpp::Any LSysDVisitor::visitCond(LSysDParser::CondContext *ctx) {
    return ctx->expression();
}

antlrcpp::Any LSysDVisitor::visitArgs(LSysDParser::ArgsContext *ctx) {
    std::list<LSysDParser::ExpressionContext *> * args = new std::list<LSysDParser::ExpressionContext *>();
    for (LSysDParser::ArgContext* argctx : ctx->arg())
        args->push_back(this->visitArg(argctx).as<LSysDParser::ExpressionContext *>());
    return args;
}

antlrcpp::Any LSysDVisitor::visitArg(LSysDParser::ArgContext *ctx) {
    return ctx->expression();
}
