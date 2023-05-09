
#include "LSysDVisitor.h"

// #include "misc.h"
#include "LSysDLexer.h"

#include <utility>
// #include <sstream>
// #include <regex>


// TreeNode<InstanceNodeContent, char>* LSysDVisitor::parseInstanceNode(std::string s) {
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
//     TreeNode<InstanceNodeContent, char>* node = visitor.visit(tree);

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

LSysDVisitor::LSysDVisitor(std::string_view inputFile, Settings const& settings, Scope * scope, StackTrace const* trace): 
        module(nullptr), currentLSystem(nullptr), selectedLSystems(new std::vector<LSystem<char> *>()), 
        currentTable(nullptr), parentNode(nullptr), currentScope(nullptr), baseScope(nullptr), 
        inputFile(inputFile), settings(settings), eh(nullptr) {
    this->eh = new ErrorHandler(inputFile, trace);

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
}

void LSysDVisitor::setAxiom() {
    antlr4::ANTLRInputStream * axiomInput = new antlr4::ANTLRInputStream(settings.axiom.get());
    LSysDLexer * axiomLexer = new LSysDLexer(axiomInput);

    if (axiomLexer->getNumberOfSyntaxErrors() != 0)
        exit(1);

    antlr4::CommonTokenStream * axiomTokens = new antlr4::CommonTokenStream(axiomLexer);
    LSysDParser * axiomParser = new LSysDParser(axiomTokens);

    antlr4::ParserRuleContext * axiomTree = axiomParser->mainWord();
    // for (auto n : static_cast<LSysDParser::WordContext *>(axiomTree)->rItem())
    //     std::cerr << n->getText() << std::endl;

    if (axiomParser->getNumberOfSyntaxErrors() != 0)
        exit(1);

    currentLSystem->_axiom = 
            std::any_cast<TreeBranch<InstanceNodeContent, char> *>
            (visit(axiomTree)); //, splitInLines(settings.axiom)));
}

Module<char> * LSysDVisitor::createModule() const {
    std::string moduleName;
    moduleName = getModuleName(inputFile, settings.inputMode.get() == Settings::InputMode::AXIOM ? "" : "lsd");
    if (settings.inputFiles.isset() && inputFile != "-") { // || settings.inputFiles.get().size() == 0) {
        if (moduleName.size() > 0) {
            // std::regex_replace(moduleName, std::regex("[-]"), "_");
            // std::regex_replace(moduleName, std::regex("[^a-zA-Z0-9_]"), "");
        } else {
            if (settings.inputMode.get() == Settings::InputMode::LSD)
                eh->error("The input LSD file name must be a valid module name + .lsd");
            else
                eh->error("The input word file name must be a valid module name");
            return static_cast<Module<char> *>(nullptr);
        }
    }
    Module<char> * mod = new Module<char>(moduleName);
    mod->eh = eh; //new ErrorHandler(eh);
    mod->_scope = new Scope(baseScope);
    mod->_evaluator = new LSysDExpressionEvaluator(eh);
    return mod;
}

LSystem<char> * LSysDVisitor::createLSystem(std::string const& name) const {
    LSystem<char> * lsys = new LSystem<char>(module);
    lsys->_scope->set("i", 0);
    lsys->_scope->set("n", settings.iterations.get());
    lsys->_name = name;
    module->_lsystems[lsys->_name] = lsys;
    return lsys;
}

// VISITS:

std::any LSysDVisitor::visitMain(LSysDParser::MainContext *ctx) {
    module = createModule();
    if (module == nullptr)
        return static_cast<std::vector<LSystem<char> *> *>(nullptr);
    currentScope = module->_scope;
    if (ctx->module()) {
        // Named L Systems(s)
        visitChildren(ctx);
        if (module->_lsystems.size() == 0 || eh->failed() || module->eh->failed())
            return static_cast<std::vector<LSystem<char> *> *>(nullptr);
    } else {
        // Anonymous L System
        currentLSystem = createLSystem(module->_name);
        if (settings.lsystems.isset() && settings.lsystems.get().size() > 0)
            eh->error("Input file is just an anonymous L System. L System could not be selected by name");
        module->_mainLSystem = currentLSystem;
        selectedLSystems->push_back(currentLSystem);
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
            return static_cast<std::vector<LSystem<char> *> *>(nullptr);
        currentScope = currentScope->parent();
        // eh->traceDown(eh->trace(ctx->stop));
        currentLSystem->populateProperties(settings);
        // eh->traceUp();
        currentLSystem = nullptr;
    }
    currentScope = currentScope->parent();
    
    // setMainLSystem();

    if (eh->failed() || module->eh->failed())
            return static_cast<std::vector<LSystem<char> *> *>(nullptr);

    return selectedLSystems;
}

std::any LSysDVisitor::visitMainWord(LSysDParser::MainWordContext *ctx) {
    if (module) {
        return visitWord(ctx->word());
    } else {
        module = createModule();
        if (module == nullptr)
            return static_cast<std::vector<LSystem<char> *> *>(nullptr);
        currentScope = module->_scope;
        currentLSystem = createLSystem(module->_name);
        if (settings.lsystems.isset() && settings.lsystems.get().size() > 0)
            eh->error("Input file is just a word. L System could not be selected by name");
        module->_mainLSystem = currentLSystem;
        selectedLSystems->push_back(currentLSystem);
        currentScope = currentLSystem->_scope;
        parseArgs();
        currentLSystem->_axiom = std::any_cast<TreeBranch<InstanceNodeContent, char> *>(visitWord(ctx->word()));
        // Ignores settings.axiom, assumes it has been already processed
        if (settings.rules.isset())
            addRules();
        if (!eh->failed())
            currentLSystem->populateProperties(settings);
        currentLSystem = nullptr;
        currentScope = currentScope->parent();
        return selectedLSystems;
    }
}

std::any LSysDVisitor::visitGlobalDefs(LSysDParser::GlobalDefsContext *ctx) {
    std::vector<std::string> lsystems = settings.lsystems.get();
    for (auto gdef : ctx->globalDef()) {
        if (gdef->lsystem()) {
            bool selected = false;
            LSysDParser::LsystemContext * lsysdef = gdef->lsystem();
            LSystem<char> * lsys = createLSystem(lsysdef->ID()->getText());
            if (settings.lsystems.isset()) {
                if (settings.lsystems.get().size() == 0) {
                    selectedLSystems->push_back(lsys);
                    selected = true;
                } else {
                    std::vector<std::string>::iterator it = std::find(lsystems.begin(), lsystems.end(), lsys->_name);
                    if (it != lsystems.end()) {
                        selectedLSystems->push_back(lsys);
                        lsystems.erase(it);
                        selected = true;
                    }
                }
            }
            if (lsysdef->KWMAIN()) {
                if (module->_mainLSystem) {
                    if (selected)
                        eh->warning("Only one LSystem must be marked as main", eh->trace(lsysdef->KWMAIN()));
                    else
                        eh->error("Only one LSystem must be marked as main", eh->trace(lsysdef->KWMAIN()));
                } else
                    module->_mainLSystem = lsys;
            }
            // } else if (lsys->_name == module->_name) {
            //     module->_mainLSystem = lsys;
            // }
        }
    }
    if (selectedLSystems->size() == 0) {
        if (module->_lsystems.size() == 1) {
            selectedLSystems->push_back(module->_lsystems.begin()->second);
            // eh->warning("You should mark one L system as main");
        } else if (module->_mainLSystem != nullptr) {
            selectedLSystems->push_back(module->_mainLSystem);
        } else if (module->_lsystems.size() > 0) {
            eh->error("No L system is either selected (-l NAME... / --all) or marked as main in " + eh->fileName()); //, eh->trace(ctx->stop));
        } else {
            eh->warning("No L Systems defined in " + eh->fileName());
        }
    }
    // if (settings.lsystems.isset()) {
    if (lsystems.size() > 0) {
        for (std::string const& name : lsystems)
            eh->error("No L System with name '" + name + "' in " + eh->fileName());
    }
    // }

    return visitChildren(ctx);
}

std::any LSysDVisitor::visitLsystem(LSysDParser::LsystemContext *ctx) {
    LSystem<char> * lsys = module->_lsystems[ctx->ID()->getText()];
    if (currentScope->has(lsys->_name)) {
        eh->error("'" + lsys->_name + "' is already defined", eh->trace(ctx->ID()));
        lsys = createLSystem(ctx->ID()->getText());
    }
    currentLSystem = lsys;
    currentScope->set(currentLSystem->_name, Value(currentLSystem));
    currentScope = currentLSystem->_scope;
    bool selected = std::find(selectedLSystems->begin(), selectedLSystems->end(), currentLSystem) != selectedLSystems->end();
    if (selected && settings.args.isset())
        parseArgs();
    // eh->traceDown(eh->trace(ctx->ID(), nullptr, "in LSystem:"));
    visitChildren(ctx);
    if (currentLSystem->_axiom == nullptr)
        eh->error("No axiom is defined in the L system " + currentLSystem->_name, eh->trace(ctx->ID()));
    if (selected) {
        if (settings.axiom.isset())
            setAxiom();
        if (settings.rules.isset())
            addRules();
    }
    // eh->traceUp();
    currentScope = currentScope->parent();
    // eh->traceDown(eh->trace(ctx->ID()));
    if (!eh->failed() && selected)
        currentLSystem->populateProperties(settings);
    // eh->traceUp();
    currentLSystem = nullptr;
    return lsys;
}

std::any LSysDVisitor::visitAxiomDef(LSysDParser::AxiomDefContext *ctx) {
    if (currentLSystem->_axiom == nullptr) {
        currentLSystem->_axiom = std::any_cast<TreeBranch<InstanceNodeContent, char> *>(this->visitWord(ctx->word()));
    } else {
        eh->error("The axiom is already defined", eh->trace(ctx));
    }
    return nullptr;
}

std::any LSysDVisitor::visitConstDeclaration(LSysDParser::ConstDeclarationContext *ctx) {
    std::string pname = ctx->ID()->getText();
    if (currentScope->thisHas(pname))
        eh->error("'" + pname + "' is already defined", eh->trace(ctx->ID()));
    Value val = module->_evaluator->eval(ctx->expression(), currentScope);
    currentScope->set(pname, val); // TODO: must know it's a constant
    // std::cerr << "PROP" << std::endl;
    // std::cerr << (val.is<std::string*>()) << std::endl;
    // std::cerr << (val2.is<std::string*>()) << std::endl;
    // std::cerr << (currentScope->get(pname).is<std::string*>()) << std::endl;
    // std::cerr << *(std::any_cast<std::string*>(val2)) << std::endl;
    return nullptr;
}

std::any LSysDVisitor::visitVarDeclaration(LSysDParser::VarDeclarationContext *ctx) {
    std::string pname = ctx->ID()->getText();
    if (currentScope->thisHas(pname))
        eh->error("'" + pname + "' is already defined", eh->trace(ctx->ID()));
    Value val = Value::null();
    if (ctx->expression())
        val = module->_evaluator->eval(ctx->expression(), currentScope);
    currentScope->set(pname, val); // TODO: must know it's a variable
    return nullptr;
}

std::any LSysDVisitor::visitAssignment(LSysDParser::AssignmentContext *ctx) {
    std::string pname = ctx->ID()->getText();
    if (!currentScope->thisHas(pname))
        eh->error("'" + pname + "' is not defined", eh->trace(ctx->ID()));
    // else if (pname is a constant)
    //     eh->error("'" + pname + "' is a constant and cannot be re-assigned", eh->trace(ctx->ID()));
    Value val = module->_evaluator->eval(ctx->expression(), currentScope);
    currentScope->set(pname, val);
    return nullptr;
}

std::any LSysDVisitor::visitFuncDef(LSysDParser::FuncDefContext *ctx) {
    std::string fname = ctx->ID()->getText();
    if (currentScope->thisHas(fname))
        eh->error("'" + fname + "' is already defined", eh->trace(ctx->ID()));
    // LSysDParser::ExpressionContext * expr = ctx->expression();
    std::vector<Parameter*> * params = std::any_cast<std::vector<Parameter *> *>(this->visitParams(ctx->params()));
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
R* LSysDVisitor::defineRule(// LSysDParser::TagPrefixContext * tagCtx, 
                            LSysDParser::WeightContext * weightCtx, 
                            LSysDParser::LcontextContext * lctxCtx, 
                            LSysDParser::LsideContext * lsideCtx, 
                            LSysDParser::RcontextContext * rctxCtx, 
                            LSysDParser::CondContext * condCtx, 
                            LSysDParser::RsideContext * rsideCtx) {
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
    TreeBranch<LeftSideNodeContent, char> * lctx;
    if (lctxCtx)
        lctx = std::any_cast<TreeBranch<LeftSideNodeContent, char> *>(this->visitLcontext(lctxCtx));
    else
        lctx = nullptr;

    // Left char: // bad any_cast
    TreeLeaf<LeftSideNodeContent, char> * lnode = std::any_cast<TreeLeaf<LeftSideNodeContent, char> *>(this->visitLside(lsideCtx));

    // Right context:
    TreeBranch<LeftSideNodeContent, char> * rctx;
    if (rctxCtx)
        rctx = std::any_cast<TreeBranch<LeftSideNodeContent, char> *>(this->visitRcontext(rctxCtx));
    else
        rctx = nullptr;

    // Condition:
    LSysDParser::ExpressionContext * cond;
    if (condCtx)
        cond = condCtx->expression();
    else
        cond = nullptr;

    // Right side:
    TreeBranch<RightSideNodeContent, char> * rside = std::any_cast<TreeBranch<RightSideNodeContent, char> *>(this->visitRside(rsideCtx));

    // Assemble rule:
    R * rule = new R(weight, lctx, lnode, rctx, cond, rside);

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
    TreeBranch<LeftSideNodeContent, char> * parent = new TreeBranch<LeftSideNodeContent, char>();
    this->parentNode = reinterpret_cast<TreeBranch<NodeContent, char> *>(parent);
    this->visitLChar(ctx->lChar());
    this->parentNode = nullptr;
    if (parent->size() != 1)
        eh->error("the left side of the arrow (excluding contexts) must be of length 1", 
                eh->trace(ctx->lChar()->validLeftChar()));
    auto lChar = reinterpret_cast<TreeLeaf<LeftSideNodeContent, char> *>(parent->firstChild());
    parent->prune();
    delete parent;
    return lChar;
}

std::any LSysDVisitor::visitLcontext(LSysDParser::LcontextContext *ctx) {
    TreeBranch<LeftSideNodeContent, char> * parent = new TreeBranch<LeftSideNodeContent, char>();
    this->parentNode = reinterpret_cast<TreeBranch<NodeContent, char> *>(parent);
    for (LSysDParser::LItemContext * lictx : ctx->lItem())
        this->visitLItem(lictx);
    this->parentNode = nullptr;
    return parent;
}

std::any LSysDVisitor::visitRcontext(LSysDParser::RcontextContext *ctx) {
    TreeBranch<LeftSideNodeContent, char> * parent = new TreeBranch<LeftSideNodeContent, char>();
    this->parentNode = reinterpret_cast<TreeBranch<NodeContent, char> *>(parent);
    for (LSysDParser::LItemContext * lictx : ctx->lItem())
        this->visitLItem(lictx);
    this->parentNode = nullptr;
    return parent;
}

std::any LSysDVisitor::visitRside(LSysDParser::RsideContext *ctx) {
    TreeBranch<RightSideNodeContent, char> * parent = new TreeBranch<RightSideNodeContent, char>();
    this->parentNode = reinterpret_cast<TreeBranch<NodeContent, char> *>(parent);
    for (LSysDParser::RItemContext * rictx : ctx->rItem())
        this->visitRItem(rictx);
    this->parentNode = nullptr;
    return parent;
}

std::any LSysDVisitor::visitWord(LSysDParser::WordContext *ctx) {
    TreeBranch<InstanceNodeContent, char> * parent = new TreeBranch<InstanceNodeContent, char>();
    this->parentNode = reinterpret_cast<TreeBranch<NodeContent, char> *>(parent);
    for (LSysDParser::RItemContext * rictx : ctx->rItem())
        this->visitRItem(rictx);
    this->parentNode = nullptr;
    return parent;
}

std::any LSysDVisitor::visitLChar(LSysDParser::LCharContext *ctx) {
    this->visitValidLeftChar(ctx->validLeftChar());
    if (ctx->params()) {
        std::vector<Parameter *> * params = std::any_cast<std::vector<Parameter *> *>(this->visitParams(ctx->params()));
        TreeLeaf<LeftSideNodeContent, char>* lft = 
                reinterpret_cast<TreeLeaf<LeftSideNodeContent, char>*>(
                    this->parentNode->lastChild());
        lft->content().createParams();
        lft->content().params()->swap(*params);
        delete params;
    }
    return nullptr;
}

std::any LSysDVisitor::visitLItem(LSysDParser::LItemContext *ctx) {
    if (ctx->validLeftChar()) {
        this->visitValidLeftChar(ctx->validLeftChar());
        if (ctx->params()) {
            auto params = std::any_cast<std::vector<Parameter *> *>(this->visitParams(ctx->params()));
            TreeLeaf<LeftSideNodeContent, char> * lft = 
                    reinterpret_cast<TreeLeaf<LeftSideNodeContent, char> *>(
                        this->parentNode->lastChild());
            lft->content().createParams();
            lft->content().params()->swap(*params);
            delete params;
        }
    } else { // ctx->lItem()
        TreeBranch<LeftSideNodeContent, char> * node = new TreeBranch<LeftSideNodeContent, char>();
        this->parentNode->addChild(reinterpret_cast<TreeBranch<NodeContent, char> *>(node));
        this->parentNode = reinterpret_cast<TreeBranch<NodeContent, char> *>(node);
        for (LSysDParser::LItemContext * lictx : ctx->lItem())
            this->visitLItem(lictx);
        this->parentNode = reinterpret_cast<TreeBranch<NodeContent, char> *>(node->parent());
    }
    return nullptr;
}

std::any LSysDVisitor::visitRItem(LSysDParser::RItemContext *ctx) {
    if (ctx->validRightChar()) {
        this->visitValidRightChar(ctx->validRightChar());
        if (ctx->args()) {
            auto args = std::any_cast<std::vector<LSysDParser::ExpressionContext *> *>(this->visitArgs(ctx->args()));
            if (!this->parentNode->isInstance()) {
                auto rgt = reinterpret_cast<TreeLeaf<RightSideNodeContent, char> *>(this->parentNode->lastChild());
                rgt->content().createArgs();
                rgt->content().args()->swap(*args);
            } else {
                auto ins = reinterpret_cast<TreeLeaf<InstanceNodeContent, char> *>(this->parentNode->lastChild());
                ins->content().createValues();
                std::vector<Value> * values = ins->content().values();
                values->reserve(args->size());
                for (LSysDParser::ExpressionContext * exprctx : *args)
                    values->push_back(module->_evaluator->eval(exprctx, currentScope));
            }
            delete args;
        }
    } else if (ctx->rItem().size() > 0) {
        TreeBranch<NodeContent, char> * node;
        if (!this->parentNode->isInstance())
            node = reinterpret_cast<TreeBranch<NodeContent, char> *>(new TreeBranch<RightSideNodeContent, char>());
            // node = (new TreeBranch<RightSideNodeContent, char>())->asGeneric();
        else
            node = reinterpret_cast<TreeBranch<NodeContent, char> *>(new TreeBranch<InstanceNodeContent, char>());
            // node = (new TreeBranch<InstanceNodeContent, char>())->asGeneric();
        this->parentNode->addChild(node);
        this->parentNode = node;
        for (LSysDParser::RItemContext * rictx : ctx->rItem())
            this->visitRItem(rictx);
        this->parentNode = node->parent();
    } // else {} // block
    return nullptr;
}

std::any LSysDVisitor::visitValidLeftChar(LSysDParser::ValidLeftCharContext *ctx) {
    std::string s = std::any_cast<std::string>(this->visitValidChar(ctx->validChar()));
    for (char c : s) {
        TreeLeaf<LeftSideNodeContent, char> * node = new TreeLeaf<LeftSideNodeContent, char>(c);
        this->parentNode->addChild(reinterpret_cast<TreeLeaf<NodeContent, char> *>(node)); //->asGeneric());
    }
    return nullptr;
}

std::any LSysDVisitor::visitValidRightChar(LSysDParser::ValidRightCharContext *ctx) {
    std::string s = std::any_cast<std::string>(this->visitValidChar(ctx->validChar()));
    // int pos = 0;
    for (char c : s) {
        if (c == '_')
            eh->error("'_' (underscore) character is not valid for the right side of a rule or for an axiom", eh->trace(ctx));
        TreeLeaf<NodeContent, char> * node;
        if (!this->parentNode->isInstance())
            node = reinterpret_cast<TreeLeaf<NodeContent, char> *>(new TreeLeaf<RightSideNodeContent, char>(c));
            // node = (new TreeLeaf<RightSideNodeContent, char>(c))->asGeneric();
        else
            node = reinterpret_cast<TreeLeaf<NodeContent, char> *>(new TreeLeaf<InstanceNodeContent, char>(c));
            // node = (new TreeLeaf<InstanceNodeContent, char>(c))->asGeneric();
        this->parentNode->addChild(node);
        // ++pos;
    }
    return nullptr;
}

std::any LSysDVisitor::visitValidChar(LSysDParser::ValidCharContext *ctx) {
    return ctx->getText();
}

std::any LSysDVisitor::visitParams(LSysDParser::ParamsContext *ctx) {
    std::vector<Parameter *> * params = new std::vector<Parameter *>();
    params->reserve(ctx->param().size());
    for (LSysDParser::ParamContext * paramctx : ctx->param())
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
    std::vector<LSysDParser::ExpressionContext *> * args = new std::vector<LSysDParser::ExpressionContext *>();
    args->reserve(ctx->arg().size());
    for (LSysDParser::ArgContext * argctx : ctx->arg())
        args->push_back(std::any_cast<LSysDParser::ExpressionContext *>(this->visitArg(argctx)));
    return args;
}

std::any LSysDVisitor::visitArg(LSysDParser::ArgContext *ctx) {
    return ctx->expression();
}
