
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

// LSysDVisitor::LSysDVisitor(Settings const* settings, 
//         std::vector<std::string> const* sourceLines, 
//         Scope * scope, StackTrace const* trace): 
//         module(module), currentLSystem(nullptr), currentTable(nullptr), parentNode(nullptr), 
//         baseScope(nullptr), currentScope(nullptr) {
//     this->eh = new ErrorHandler(settings->inputFile.get(), sourceLines, trace);
// }

LSysDVisitor::LSysDVisitor(Settings const& settings, Scope * scope, StackTrace const* trace): 
        module(nullptr), currentLSystem(nullptr), selectedLSystem(nullptr), currentTable(nullptr), 
        parentNode(nullptr), currentScope(nullptr), baseScope(nullptr), settings(settings), eh(nullptr) {
    this->eh = new ErrorHandler(settings.inputFile.get(), trace);

    if (scope != nullptr)
        this->baseScope = new Scope(scope); // TODO ??? El padre del padre???

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

// void LSysDVisitor::setMainLSystem() { //(antlr4::ParserRuleContext* ctx) {
//     if (settings.lsystem.isset()) {
//         if (module->_lsystems.find(settings.lsystem.get()) != module->_lsystems.end())
//             module->_mainLSystem = module->_lsystems[settings.lsystem.get()];
//         else
//             eh->error("No L-System named " + settings.lsystem.get()); //, eh->trace(ctx->stop));
//     } else if (module->_mainLSystem == nullptr) {
//         if (module->_lsystems.size() == 1) {
//             module->_mainLSystem = module->_lsystems.begin()->second;
//             // if (ctx->module())
//             //     eh->warning("You should mark one L system as main", eh->trace(ctx->stop));
//         } else {
//             for (auto [name, lsys] : module->_lsystems) {
//                 if (lsys->_name == module->_name) {
//                     module->_mainLSystem = lsys;
//                     break;
//                 }
//             }
//             if (module->_mainLSystem == nullptr) {
//                 eh->error("No L system is either selected (-l NAME) or marked as main in " + eh->fileName()); //, eh->trace(ctx->stop));
//                 // return static_cast<Module<char> *>(nullptr);
//             } else {
//                 eh->warning("You should either select (-l NAME) or mark one L system as main"); //, eh->trace(ctx->stop));
//             }
//         }
//     }
// }

void LSysDVisitor::parseArgs() {
    for (auto [param, value] : settings.args.get()) {
        antlr4::ANTLRInputStream * exprInput = new antlr4::ANTLRInputStream(value);
        LSysDLexer * exprLexer = new LSysDLexer(exprInput);

        if (exprLexer->getNumberOfSyntaxErrors() != 0)
            exit(1);

        antlr4::CommonTokenStream * exprTokens = new antlr4::CommonTokenStream(exprLexer);
        LSysDParser * exprParser = new LSysDParser(exprTokens);

        LSysDParser::ExpressionContext * expr = exprParser->expression();

        if (exprParser->getNumberOfSyntaxErrors() != 0)
            exit(1);

        Value v = module->_evaluator->eval(expr, currentScope);

        if (module->_evaluator->messages()->failed()) {
            module->_evaluator->messages()->dump();
            exit(1);
        }

        currentScope->set(param, v);
    }
}

void LSysDVisitor::addRules() {
    antlr4::ANTLRInputStream * rulesInput = new antlr4::ANTLRInputStream(settings.rules.get());
    LSysDLexer * rulesLexer = new LSysDLexer(rulesInput);

    if (rulesLexer->getNumberOfSyntaxErrors() != 0)
        exit(1);

    antlr4::CommonTokenStream * rulesTokens = new antlr4::CommonTokenStream(rulesLexer);
    LSysDParser * rulesParser = new LSysDParser(rulesTokens);

    antlr4::ParserRuleContext * rulesTree = rulesParser->mainRuleDefs();

    if (rulesParser->getNumberOfSyntaxErrors() != 0)
        exit(1);

    // This adds the rules to the current LSystem
    visit(rulesTree); //, splitInLines(settings.rules));

    // if (eh->failed()) {
    //     eh->dump();
    //     exit(1);
    // }
}

void LSysDVisitor::setAxiom() {
    antlr4::ANTLRInputStream * axiomInput = new antlr4::ANTLRInputStream(settings.axiom.get());
    LSysDLexer * axiomLexer = new LSysDLexer(axiomInput);

    if (axiomLexer->getNumberOfSyntaxErrors() != 0)
        exit(1);

    antlr4::CommonTokenStream * axiomTokens = new antlr4::CommonTokenStream(axiomLexer);
    LSysDParser * axiomParser = new LSysDParser(axiomTokens);

    antlr4::ParserRuleContext * axiomTree = axiomParser->mainWord();
    // for (auto n : static_cast<LSysDParser::WordContext*>(axiomTree)->rItem())
    //     std::cout << n->getText() << std::endl;

    if (axiomParser->getNumberOfSyntaxErrors() != 0)
        exit(1);

    currentLSystem->_axiom = 
            std::any_cast<ParseTreeNode<InstanceNodeContent, char> *>
            (visit(axiomTree)); //, splitInLines(settings.axiom)));

    // if (eh->failed()) {
    //     eh->dump();
    //     exit(1);
    // }
}



std::any LSysDVisitor::visitMain(LSysDParser::MainContext *ctx) {
    std::string moduleName;
    if (eh->fromStdin())
        moduleName = eh->fileName();
    else {
        moduleName = getModuleName(eh->fileName());
        if (moduleName.size() > 0) {
            // std::regex_replace(moduleName, std::regex("[-]"), "_");
            // std::regex_replace(moduleName, std::regex("[^a-zA-Z0-9_]"), "");
        } else {
            eh->error("The input file name must end in .lsd", eh->trace(ctx->stop));
            return static_cast<LSystem<char> *>(nullptr);
        }
    }
    module = new Module<char>(moduleName);
    module->eh = eh; //new ErrorHandler(eh);
    module->_scope = new Scope(baseScope);
    module->_evaluator = new LSysDExpressionEvaluator(eh);
    currentScope = module->_scope;
    if (ctx->module()) {
        // Named L Systems(s)
        visitChildren(ctx);
        if (eh->failed() || module->eh->failed())
            return static_cast<LSystem<char> *>(nullptr);
    } else {
        // Anonymous L System
        currentLSystem = new LSystem<char>(module);
        currentLSystem->_name = module->_name;
        module->_lsystems[currentLSystem->_name] = currentLSystem;
        if (settings.lsystem.isset())
            eh->error("Anonymous L System. No '" + settings.lsystem.get() + "' L System can be selected");
        module->_mainLSystem = currentLSystem;
        selectedLSystem = currentLSystem;
        currentScope = currentLSystem->_scope;
        parseArgs();
        visitChildren(ctx);
        if (currentLSystem->_axiom == nullptr) {
            if (settings.axiom.isset()) {
                eh->warning("No axiom is defined in the L System in file " + eh->fileName() + 
                        ", the axiom argument will be used", eh->trace(ctx->stop));
            } else {
                eh->error("No axiom is defined in the L System in file " + eh->fileName(), eh->trace(ctx->stop));
            }
        }
        if (settings.axiom.isset())
            setAxiom();
        if (settings.rules.isset())
            addRules();
        if (eh->failed() || module->eh->failed())
            return static_cast<LSystem<char> *>(nullptr);
        currentScope = currentScope->parent();
        // eh->traceDown(eh->trace(ctx->stop));
        currentLSystem->populateProperties(settings);
        // eh->traceUp();
        currentLSystem = nullptr;
    }
    currentScope = currentScope->parent();
    
    // setMainLSystem();

    if (eh->failed() || module->eh->failed())
            return static_cast<LSystem<char> *>(nullptr);

    return selectedLSystem;
}

std::any LSysDVisitor::visitMainWord(LSysDParser::MainWordContext *ctx) {
    if (module) {
        return visitWord(ctx->word());
    } else {
        module = new Module<char>(eh->fileName());
        module->eh = eh; //new ErrorHandler(eh);
        module->_scope = new Scope(baseScope);
        module->_evaluator = new LSysDExpressionEvaluator(eh);
        currentLSystem = new LSystem<char>(module);
        currentLSystem->_name = module->_name;
        module->_lsystems[currentLSystem->_name] = currentLSystem;
        module->_mainLSystem = currentLSystem;
        selectedLSystem = currentLSystem;
        currentScope = currentLSystem->_scope;
        parseArgs();
        currentLSystem->_axiom = std::any_cast<ParseTreeNode<InstanceNodeContent, char> *>(visitWord(ctx->word()));
        // Ignores settings.axiom, assumes it has been already processed
        if (settings.rules.isset())
            addRules();
        if (!eh->failed())
            currentLSystem->populateProperties(settings);
        currentLSystem = nullptr;
        currentScope = currentScope->parent();
        return selectedLSystem;
    }
}

std::any LSysDVisitor::visitGlobalDefs(LSysDParser::GlobalDefsContext *ctx) {
    for (auto gdef : ctx->globalDef()) {
        if (gdef->lsystem()) {
            LSysDParser::LsystemContext * lsysdef = gdef->lsystem();
            LSystem<char> * lsys = new LSystem<char>(module);
            lsys->_name = lsysdef->ID()->getText();
            module->_lsystems[lsys->_name] = lsys;
            if (settings.lsystem.isset() && settings.lsystem.get() == lsys->_name) {
                if (selectedLSystem == nullptr)
                    selectedLSystem = lsys;
                else
                    eh->error("There is more than one L System with name '" + settings.lsystem.get() + "' in " + eh->fileName(), eh->trace(lsysdef->ID()));
            }
            if (lsysdef->KWMAIN()) {
                if (module->_mainLSystem)
                    eh->error("Only one LSystem must be marked as main", eh->trace(lsysdef->KWMAIN()));
                else
                    module->_mainLSystem = lsys;
            }
            // } else if (lsys->_name == module->_name) {
            //     module->_mainLSystem = lsys;
            // }
        }
    }
    if (selectedLSystem == nullptr) {
        if (settings.lsystem.isset()) {
            eh->error("There is no L System with name '" + settings.lsystem.get() + "' in " + eh->fileName());
        } else if (module->_mainLSystem != nullptr) {
            selectedLSystem = module->_mainLSystem;
        } else if (module->_lsystems.size() == 1) {
            selectedLSystem = module->_lsystems.begin()->second;
            // eh->warning("You should mark one L system as main");
        } else {
            eh->error("No L system is either selected (-l NAME) or marked as main in " + eh->fileName()); //, eh->trace(ctx->stop));
        }
    }

    return visitChildren(ctx);
}

std::any LSysDVisitor::visitLsystem(LSysDParser::LsystemContext *ctx) {
    currentLSystem = module->_lsystems[ctx->ID()->getText()];
    if (currentScope->has(currentLSystem->_name))
        eh->error("'" + currentLSystem->_name + "' is already defined", eh->trace(ctx->ID()));
    currentScope->set(currentLSystem->_name, Value(currentLSystem));
    currentScope = currentLSystem->_scope;
    if (currentLSystem == selectedLSystem && settings.args.isset())
        parseArgs();
    // eh->traceDown(eh->trace(ctx->ID(), nullptr, "in LSystem:"));
    visitChildren(ctx);
    if (currentLSystem->_axiom == nullptr)
        eh->error("No axiom is defined in the L system " + currentLSystem->_name, eh->trace(ctx->ID()));
    if (currentLSystem == selectedLSystem) {
        if (settings.axiom.isset())
            setAxiom();
        if (settings.rules.isset())
            addRules();
    }
    // eh->traceUp();
    currentScope = currentScope->parent();
    // eh->traceDown(eh->trace(ctx->ID()));
    if (!eh->failed() && currentLSystem == selectedLSystem)
        currentLSystem->populateProperties(settings);
    // eh->traceUp();
    currentLSystem = nullptr;
    return nullptr;
}

std::any LSysDVisitor::visitAxiomDef(LSysDParser::AxiomDefContext *ctx) {
    if (currentLSystem->_axiom == nullptr) {
        currentLSystem->_axiom = std::any_cast<ParseTreeNode<InstanceNodeContent, char> *>(this->visitWord(ctx->word()));
    } else {
        eh->error("The axiom is already defined", eh->trace(ctx));
    }
    return nullptr;
}

std::any LSysDVisitor::visitConstDeclaration(LSysDParser::ConstDeclarationContext *ctx) {
    std::string pname = ctx->ID()->getText();
    if (currentScope->has(pname))
        eh->error("'" + pname + "' is already defined", eh->trace(ctx->ID()));
    Value val = module->_evaluator->eval(ctx->expression(), currentScope);
    currentScope->set(pname, val); // TODO: must know it's a constant
    // std::cout << "PROP" << std::endl;
    // std::cout << (val.is<std::string*>()) << std::endl;
    // std::cout << (val2.is<std::string*>()) << std::endl;
    // std::cout << (currentScope->get(pname).is<std::string*>()) << std::endl;
    // std::cout << *(std::any_cast<std::string*>(val2)) << std::endl;
    return nullptr;
}

std::any LSysDVisitor::visitVarDeclaration(LSysDParser::VarDeclarationContext *ctx) {
    std::string pname = ctx->ID()->getText();
    if (currentScope->has(pname))
        eh->error("'" + pname + "' is already defined", eh->trace(ctx->ID()));
    Value val = Value::null();
    if (ctx->expression())
        val = module->_evaluator->eval(ctx->expression(), currentScope);
    currentScope->set(pname, val); // TODO: must know it's a variable
    return nullptr;
}

std::any LSysDVisitor::visitAssignment(LSysDParser::AssignmentContext *ctx) {
    std::string pname = ctx->ID()->getText();
    if (!currentScope->has(pname))
        eh->error("'" + pname + "' is not defined", eh->trace(ctx->ID()));
    // else if (pname is a constant)
    //     eh->error("'" + pname + "' is a constant and cannot be re-assigned", eh->trace(ctx->ID()));
    Value val = module->_evaluator->eval(ctx->expression(), currentScope);
    currentScope->set(pname, val);
    return nullptr;
}

std::any LSysDVisitor::visitFuncDef(LSysDParser::FuncDefContext *ctx) {
    std::string fname = ctx->ID()->getText();
    if (currentScope->has(fname))
        eh->error("'" + fname + "' is already defined", eh->trace(ctx->ID()));
    // LSysDParser::ExpressionContext* expr = ctx->expression();
    std::list<Parameter*>* params = std::any_cast<std::list<Parameter *> *>(this->visitParams(ctx->params()));
    currentScope->set(fname, new Function(params, ctx->expression(), ctx));
    // currentScope->set(fname, new Function(params, ctx->block(), ctx));
    return nullptr;
}

// std::any LSysDVisitor::visitConstDef(LSysDParser::ConstDefContext *ctx) {
//     return visitChildren(ctx);
// }

std::any LSysDVisitor::visitTableBlock(LSysDParser::TableBlockContext *ctx) {
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

std::any LSysDVisitor::visitRulesBlock(LSysDParser::RulesBlockContext *ctx) {
    // eh->traceDown(eh->trace(ctx->KWRULES()->getSymbol(), ctx->KWRULES()->getSymbol(), "in block:"));
    // this->currentTable = this->defaultTable;
    this->visitRuleDefs(ctx->ruleDefs());
    // this->currentTable = nullptr;
    // eh->traceUp();
    return nullptr;
}

std::any LSysDVisitor::visitProductionRulesBlock(LSysDParser::ProductionRulesBlockContext *ctx) {
    // eh->traceDown(eh->trace(ctx->KWPRODUCTION()->getSymbol(), ctx->KWRULES()->getSymbol(), "in block:"));
    currentTable = currentLSystem->_defaultTable;
    this->visitRuleDefs(ctx->ruleDefs());
    currentTable = nullptr;
    // eh->traceUp();
    return nullptr;
}

std::any LSysDVisitor::visitCodingRulesBlock(LSysDParser::CodingRulesBlockContext *ctx) {
    // eh->traceDown(eh->trace(ctx->KWCODING()->getSymbol(), ctx->KWRULES()->getSymbol(), "in block:"));
    currentTable = currentLSystem->_codingRules;
    this->visitRuleDefs(ctx->ruleDefs());
    currentTable = nullptr;
    // eh->traceUp();
    return nullptr;
}

std::any LSysDVisitor::visitProductionRule(LSysDParser::ProductionRuleContext *ctx) {
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

std::any LSysDVisitor::visitCodingRule(LSysDParser::CodingRuleContext *ctx) {
    return visitChildren(ctx);
}

std::any LSysDVisitor::visitRuleDef(LSysDParser::RuleDefContext *ctx) {
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
    //     tag = std::any_cast<std::string>(this->visitTagPrefix(tagCtx));
    // else
    //     tag = "";

    // Weight:
    weight_t weight;
    if (weightCtx)
        weight = std::any_cast<weight_t>(this->visitWeight(weightCtx));
    else
        weight = Rule<char>::WEIGHT_UNSET;

    // Left context:
    ParseTreeNode<LeftSideNodeContent, char>* lctx;
    if (lctxCtx)
        lctx = std::any_cast<ParseTreeNode<LeftSideNodeContent, char> *>(this->visitLcontext(lctxCtx));
    else
        lctx = nullptr;

    // Left char:
    ParseTreeNode<LeftSideNodeContent, char>* lnode = std::any_cast<ParseTreeNode<LeftSideNodeContent, char> *>(this->visitLside(lsideCtx));

    // Right context:
    ParseTreeNode<LeftSideNodeContent, char>* rctx;
    if (rctxCtx)
        rctx = std::any_cast<ParseTreeNode<LeftSideNodeContent, char> *>(this->visitRcontext(rctxCtx));
    else
        rctx = nullptr;

    // Condition:
    LSysDParser::ExpressionContext* cond;
    if (condCtx)
        cond = condCtx->expression();
    else
        cond = nullptr;

    // Right side:
    ParseTreeNode<RightSideNodeContent, char>* rside = std::any_cast<ParseTreeNode<RightSideNodeContent, char> *>(this->visitRside(rsideCtx));

    // Assemble rule:
    R* rule = new R(weight, lctx, lnode, rctx, cond, rside);

    // if (tag != "")
    //     currentLSystem->_taggedRules[tag] = reinterpret_cast<Rule<char>*>(rule);

    return rule;
}


std::any LSysDVisitor::visitProductionRuleDef(LSysDParser::ProductionRuleDefContext *ctx) {
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

std::any LSysDVisitor::visitCodingRuleDef(LSysDParser::CodingRuleDefContext *ctx) {
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

std::any LSysDVisitor::visitTagPrefix(LSysDParser::TagPrefixContext *ctx) {
    std::string tag = std::any_cast<std::string>(this->visitTag(ctx->tag()));
    if (currentLSystem->_taggedRules.find(tag) != currentLSystem->_taggedRules.end())
        eh->error("tag '" + tag + "' is already defined", eh->trace(ctx->tag()));
    return tag;
}

std::any LSysDVisitor::visitTag(LSysDParser::TagContext *ctx) {
    return ctx->ID()->getText();
}

std::any LSysDVisitor::visitWeight(LSysDParser::WeightContext *ctx) {
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

std::any LSysDVisitor::visitLside(LSysDParser::LsideContext *ctx) {
    ParseTreeNode<LeftSideNodeContent, char>* parent = new ParseTreeNode<LeftSideNodeContent, char>();
    this->parentNode = parent->asGeneric();
    this->visitLChar(ctx->lChar());
    this->parentNode = nullptr;
    if (parent->size() != 1)
        eh->error("the left side of the arrow (excluding contexts) must be of length 1", 
                eh->trace(ctx->lChar()->validLeftChar()));
    return parent->leftmostChild();
}

std::any LSysDVisitor::visitLcontext(LSysDParser::LcontextContext *ctx) {
    ParseTreeNode<LeftSideNodeContent, char>* parent = new ParseTreeNode<LeftSideNodeContent, char>();
    this->parentNode = parent->asGeneric();
    for (LSysDParser::LItemContext* lictx : ctx->lItem())
        this->visitLItem(lictx);
    this->parentNode = nullptr;
    return parent;
}

std::any LSysDVisitor::visitRcontext(LSysDParser::RcontextContext *ctx) {
    ParseTreeNode<LeftSideNodeContent, char>* parent = new ParseTreeNode<LeftSideNodeContent, char>();
    this->parentNode = parent->asGeneric();
    for (LSysDParser::LItemContext* lictx : ctx->lItem())
        this->visitLItem(lictx);
    this->parentNode = nullptr;
    return parent;
}

std::any LSysDVisitor::visitRside(LSysDParser::RsideContext *ctx) {
    ParseTreeNode<RightSideNodeContent, char>* parent = new ParseTreeNode<RightSideNodeContent, char>();
    this->parentNode = parent->asGeneric();
    for (LSysDParser::RItemContext* rictx : ctx->rItem())
        this->visitRItem(rictx);
    this->parentNode = nullptr;
    return parent;
}

std::any LSysDVisitor::visitWord(LSysDParser::WordContext *ctx) {
    ParseTreeNode<InstanceNodeContent, char>* parent = new ParseTreeNode<InstanceNodeContent, char>();
    this->parentNode = parent->asGeneric();
    for (LSysDParser::RItemContext* rictx : ctx->rItem())
        this->visitRItem(rictx);
    this->parentNode = nullptr;
    return parent;
}

std::any LSysDVisitor::visitLChar(LSysDParser::LCharContext *ctx) {
    this->visitValidLeftChar(ctx->validLeftChar());
    if (ctx->params()) {
        std::list<Parameter *> * params = std::any_cast<std::list<Parameter *> *>(this->visitParams(ctx->params()));
        ParseTreeNode<LeftSideNodeContent, char>* rgt = 
                reinterpret_cast<ParseTreeNode<LeftSideNodeContent, char>*>(
                    this->parentNode->rightmostChild());
        rgt->content().params = params;
    }
    return nullptr;
}

std::any LSysDVisitor::visitLItem(LSysDParser::LItemContext *ctx) {
    if (ctx->validLeftChar()) {
        this->visitValidLeftChar(ctx->validLeftChar());
        if (ctx->params()) {
            std::list<Parameter *> * params = std::any_cast<std::list<Parameter *> *>(this->visitParams(ctx->params()));
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

std::any LSysDVisitor::visitRItem(LSysDParser::RItemContext *ctx) {
    if (ctx->validRightChar()) {
        this->visitValidRightChar(ctx->validRightChar());
        if (ctx->args()) {
            std::list<LSysDParser::ExpressionContext *> * args = std::any_cast<std::list<LSysDParser::ExpressionContext *> *>(this->visitArgs(ctx->args()));
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

std::any LSysDVisitor::visitValidLeftChar(LSysDParser::ValidLeftCharContext *ctx) {
    std::string_view s = std::any_cast<std::string>(this->visitValidChar(ctx->validChar()));
    for (char c : s) {
        ParseTreeNode<LeftSideNodeContent, char>* node = new ParseTreeNode<LeftSideNodeContent, char>(c);
        this->parentNode->addChild(node->asGeneric());
    }
    return nullptr;
}

std::any LSysDVisitor::visitValidRightChar(LSysDParser::ValidRightCharContext *ctx) {
    std::string_view s = std::any_cast<std::string>(this->visitValidChar(ctx->validChar()));
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

std::any LSysDVisitor::visitValidChar(LSysDParser::ValidCharContext *ctx) {
    return ctx->getText();
}

std::any LSysDVisitor::visitParams(LSysDParser::ParamsContext *ctx) {
    std::list<Parameter *> * params = new std::list<Parameter *>();
    for (LSysDParser::ParamContext* paramctx : ctx->param())
        params->push_back(std::any_cast<Parameter *>(this->visitParam(paramctx)));
    return params;
}

std::any LSysDVisitor::visitParam(LSysDParser::ParamContext *ctx) {
    return new Parameter(ctx->ID()->getText());
}

std::any LSysDVisitor::visitCond(LSysDParser::CondContext *ctx) {
    return ctx->expression();
}

std::any LSysDVisitor::visitArgs(LSysDParser::ArgsContext *ctx) {
    std::list<LSysDParser::ExpressionContext *> * args = new std::list<LSysDParser::ExpressionContext *>();
    for (LSysDParser::ArgContext* argctx : ctx->arg())
        args->push_back(std::any_cast<LSysDParser::ExpressionContext *>(this->visitArg(argctx)));
    return args;
}

std::any LSysDVisitor::visitArg(LSysDParser::ArgContext *ctx) {
    return ctx->expression();
}
