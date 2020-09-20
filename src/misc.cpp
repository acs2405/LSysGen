
#include "misc.h"

#include <regex>
#include <utility>
#include <sstream>
#include <cstdlib>
#include <chrono>


namespace lsysgen {

Parameter::Parameter(std::string const& name): name(name) {}

bool operator==(Parameter const& p1, Parameter const& p2) {return p1.name == p2.name;}



Function::Function(std::list<Parameter*>* params, 
            LSysDParser::ExpressionContext* expr, 
            antlr4::tree::ParseTree* ctx):
        _params(params), expr(expr), ctx(ctx) {}

const std::list<Parameter*>* Function::params() const {return this->_params;}

std::string Function::toString() {
    std::string s = "(";
    for (auto it = this->_params->begin(); it != this->_params->end(); ++it) {
        if (it != this->_params->begin())
            s += ", ";
        s += (*it)->name;
    }
    s += ") -> " + this->expr->getText();
    return s;
}

Value Function::call(std::list<Value>* args) {
    Environment *paramMapping = new Environment();
    if ((args == nullptr && this->_params != nullptr && this->_params->size() > 0) || 
        (args != nullptr && this->_params != nullptr && this->_params->size() != args->size()))
        return Value::error();
    std::list<Parameter*>::iterator param;
    std::list<Value>::iterator arg;
    for (param = this->_params->begin(), arg = args->begin();
            param != this->_params->end();
            ++param, ++arg)
        paramMapping->set((*param)->name, *arg);
    return eval(this->expr, paramMapping); 
}



ValueType::ValueType(std::string const& name): _name(name) {}

std::string const& ValueType::name() const {return this->_name;}

bool operator==(ValueType const& t1, ValueType const& t2) {return t1._name == t2._name;}

const ValueType ValueType::INT_TYPE("int");
const ValueType ValueType::FLOAT_TYPE("float");
const ValueType ValueType::BOOL_TYPE("bool");
const ValueType ValueType::STRING_TYPE("string");
const ValueType ValueType::FUNCTION_TYPE("function");
const ValueType ValueType::ERROR_TYPE("error");



Value::Value(ValueType const& type, boost::any value): _type(type), _value(value) {}
Value::Value(): _type(ValueType::ERROR_TYPE), _value(antlrcpp::Any()) {}
Value::Value(int value): _type(ValueType::INT_TYPE), _value(value) {}
Value::Value(double value): _type(ValueType::FLOAT_TYPE), _value(value) {}
Value::Value(bool value): _type(ValueType::BOOL_TYPE), _value(value) {}
Value::Value(std::string value): _type(ValueType::STRING_TYPE), _value(value) {}
Value::Value(Function* value): _type(ValueType::FUNCTION_TYPE), _value(value) {}

ValueType const& Value::type() const {return this->_type;}

bool Value::is (ValueType const& t) const {return t == this->_type;}

bool Value::isInt () const {return this->is(ValueType::INT_TYPE);}
bool Value::isFloat () const {return this->is(ValueType::FLOAT_TYPE);}
bool Value::isBool () const {return this->is(ValueType::BOOL_TYPE);}
bool Value::isString () const {return this->is(ValueType::STRING_TYPE);}
bool Value::isFunction () const {return this->is(ValueType::FUNCTION_TYPE);}
bool Value::isError () const {return this->is(ValueType::ERROR_TYPE);}

// bool Value::isTrue () const {
//     if (this->isBool()) {
//         return this->as<bool>();
//     } else if (!this->isError()) {
//         err("The condition expression (" + this->_type.name() + ") must be a boolean"); //, cond);
//         return false;
//     }
//     return false;
// }

int Value::asInt () const {return this->as<int>();}
double Value::asFloat () const {return this->as<double>();}
bool Value::asBool () const {return this->as<bool>();}
std::string Value::asString () const {return this->as<std::string>();}
Function* Value::asFunction () {return this->as<Function*>();}
Function* Value::asFunction () const {return this->as<Function*>();}

template<typename T>
T Value::as () {
    return boost::any_cast<T>(this->_value);
}
template<typename T>
const T Value::as () const {
    return boost::any_cast<T>(this->_value);
    // return this->_value.as<T>();
}

std::string Value::toString() const {
    if (this->isInt()) {
        return std::to_string(this->as<int>());
    } else if (this->isFloat()) {
        std::stringstream ss;
        ss << std::fixed << std::setprecision(2) << this->as<double>();
        return ss.str();
    } else if (this->isBool()) {
        return this->as<bool>() ? "true" : "false";
    } else if (this->isString()) {
        return '"' + strEscape(this->as<std::string>()) + '"';
    } else if (this->isFunction()) {
        return this->as<Function*>()->toString();
    } else {
        return "<error>";
    }
}

Value& Value::operator=(Value const& t2) {
    this->_type = t2._type;
    this->_value = t2._value;
    return *this;
}

Value const& Value::error() {return Value::ERROR;}

const Value Value::ERROR = Value(ValueType::ERROR_TYPE, nullptr);



Environment::Environment() {
    this->mapping = new std::map<std::string, Value>();
}
Environment::Environment(Environment* env) {
    this->mapping = new std::map<std::string, Value>(env->mapping->begin(), env->mapping->end());
}

Environment::~Environment() {
    delete this->mapping;
}

void Environment::set(std::string const& var, Value const& val) {
    (*this->mapping)[var] =  val;
}
Value Environment::get(std::string const& var) {
    return (*this->mapping->find(var)).second;
}
bool Environment::has(std::string const& var) const {
    return this->mapping->find(var) != this->mapping->end();
}
// Environment* Environment::copy() {
//     Environment* env = new Environment();
//     env->merge(this);
//     return env;
// }
void Environment::merge(Environment* env) {
    this->mapping->insert(env->mapping->begin(), env->mapping->end());
}



// template<typename Base, typename T>
// bool instanceof(const T*) {
//    return is_base_of<Base, T>::value;
// }

LSysDExpressionEvaluator* evaluator = new LSysDExpressionEvaluator();
Value eval(LSysDParser::ExpressionContext* expr, Environment* env) {
    return evaluator->eval(expr, env);
}

// std::string anyToString(antlrcpp::Any& v) {
//     if (v.is<int>()) {
//         return std::to_string(v.as<int>());
//     } else if (v.is<double>()) {
//         return std::to_string(v.as<double>());
//     } else if (v.is<bool>()) {
//         return v.as<bool>() ? "true" : "false";
//     } else if (v.is<std::string>()) {
//         return '"' + strEscape(v.as<std::string>()) + '"';
//     } else if (v.is<Function*>()) {
//         return v.as<Function*>()->toString();
//     } else {
//         return "<error>";
//     }
// }

template<typename T>
bool checkSideContext(ParseTreeNode<LeftSideNodeContent, T>* contextNode, ParseTreeNode<InstanceNodeContent, T>* instanceNode, bool rightSide, std::list<T>* ignore, Environment* paramMapping) {
    if (contextNode == nullptr)
        return true;
    if (instanceNode == nullptr)
        return false;
    // print("Check %s context %s matches %s" % ("right" if rightSide else "left", str(contextNode->to_str_with_context()), str(instanceNode->to_str_with_context())))
    // if rightSide:
    //     str_iter = instanceNode->ltr_siblings_iterator()
    //     ctx_iter = contextNode->ltr_siblings_iterator()
    // else:
    //     str_iter = instanceNode->rtl_global_iterator()
    //     ctx_iter = contextNode->rtl_siblings_iterator()
    ParseTreeNode<LeftSideNodeContent, T>* ctxNode;
    ParseTreeNode<InstanceNodeContent, T>* insNode;
    for (ctxNode = contextNode, insNode = instanceNode; 
             ctxNode != nullptr; 
             ctxNode = rightSide ? contextNode->right() : contextNode->left(),
             insNode = rightSide ? instanceNode->right() : instanceNode->nextLeft()) {
        if (insNode == nullptr)
            return false;
        if (ctxNode->isLeaf()) {
            ignore->end();
            while (insNode->isBranch() || std::find(ignore->begin(), ignore->end(), insNode->element()) != ignore->end()) {
                // insNode = next(str_iter, None)
                insNode = rightSide ? insNode->right() : insNode->nextLeft();
                if (insNode == nullptr)
                    return false;
            }
            if (ctxNode->element() != insNode->element())
                return false;
        } else if (ctxNode->isBranch()) {
            if (!insNode->isBranch())
                return false;
            if (!checkRightContext(ctxNode->leftmostChild(), insNode->leftmostChild(), ignore, paramMapping))
                return false;
        }
    }
    // std::cerr << "Here 3!" << std::endl;
    if (mapArgs(instanceNode->content()->values, contextNode->content()->params, paramMapping) == nullptr)
        return false;
    if (contextNode->content()->cond && !checkCondition(contextNode->content()->cond, paramMapping))
        return false;
    return true;
}

template<typename T>
bool checkLeftContext(ParseTreeNode<LeftSideNodeContent, T>* contextNode, ParseTreeNode<InstanceNodeContent, T>* instanceNode, std::list<T>* ignore, Environment* paramMapping) {
    return checkSideContext(contextNode, instanceNode, false, ignore, paramMapping);
}

template<typename T>
bool checkRightContext(ParseTreeNode<LeftSideNodeContent, T>* contextNode, ParseTreeNode<InstanceNodeContent, T>* instanceNode, std::list<T>* ignore, Environment* paramMapping) {
    return checkSideContext(contextNode, instanceNode, true, ignore, paramMapping);
}

template<typename T>
ParseTreeNode<InstanceNodeContent, T>* evaluateRightNode(const ParseTreeNode<RightSideNodeContent, T>* node, Environment* paramMapping) {
    ParseTreeNode<InstanceNodeContent, T>* instanceNode = new ParseTreeNode<InstanceNodeContent, T>(node->element(), node->type());
    if (node->isLeaf()) {
        if (node->content()->args != nullptr) {
            std::vector<Value>* values = new std::vector<Value>();
            for (LSysDParser::ExpressionContext* arg : *node->content()->args)
                values->push_back(eval(arg, paramMapping));
            instanceNode->content()->values = values;
        }
    } else {
        for (ParseTreeNode<RightSideNodeContent, T>* child = node->leftmostChild();
                child != nullptr;
                child = child->right()) {
            ParseTreeNode<InstanceNodeContent, T>* childInstanceNode = evaluateRightNode(child, paramMapping);
            instanceNode->addChild(childInstanceNode);
        }
    }
    return instanceNode;
}

template<typename T>
ParseTreeNode<InstanceNodeContent, T>* derive(ParseTreeNode<InstanceNodeContent, T>* node, Table<T>* table, std::list<T>* ignore, Environment* env) {
    // std::cout << "HERE with " << node->toStringWithContext() << std::endl;
    if (node->isBranch()) {
        ParseTreeNode<InstanceNodeContent, T>* replacement = new ParseTreeNode<InstanceNodeContent, T>();
        for (ParseTreeNode<InstanceNodeContent, T>* child = node->leftmostChild(); 
                child != nullptr; 
                child = child->right()) {
            ParseTreeNode<InstanceNodeContent, T>* encapsulatedChildReplacement = derive(child, table, ignore, env);
            for (ParseTreeNode<InstanceNodeContent, T>* child2 = encapsulatedChildReplacement->leftmostChild(); 
                    child2 != nullptr; 
                    child2 = child2->right())
                replacement->addChild(child2);
        }
        return node->isRoot() ? replacement : replacement->encapsulate();
    }
    // std::cerr << "Here 2!" << std::endl;
    const std::list<Rule<T>*>* candidateRules = table->rulesFor(node->content()->element());
    std::list<Rule<T>*>* applicableRules = new std::list<Rule<T>*>();
    Environment* paramMapping = new Environment(env);
    for (Rule<T>* r : *candidateRules) {
        // std::cout << "RULE CANDIDATE: " << r->toString() << std::endl;
        // Check arguments:
        if (mapArgs(node->content()->values, r->params(), paramMapping) == nullptr)
            continue;
        // Left context:
        if (r->lctx) {
            if (!checkLeftContext(r->lctx->rightmostChild(), node->nextLeft(), ignore, paramMapping))
                continue;
        }
        // Right context:
        if (r->rctx) {
            if (!checkRightContext(r->rctx->leftmostChild(), node->right(), ignore, paramMapping))
                continue;
        }
        // Check condition:
        if (r->cond() && !checkCondition(r->cond(), paramMapping)){
            continue;
        }
        applicableRules->push_back(r);
    }
    // std::cerr << "Here 3!" << std::endl;
    if (applicableRules->size() > 0) {
        Rule<T>* chosenRule = chooseRule(applicableRules);
        // std::cout << "RULE APPLIED: " << chosenRule->toString() << std::endl;
        return evaluateRightNode(chosenRule->rside, paramMapping);
    }
    ParseTreeNode<InstanceNodeContent, T>* ret = new ParseTreeNode<InstanceNodeContent, T>(node);
    return ret->encapsulate();
}
template ParseTreeNode<InstanceNodeContent, char>* derive(ParseTreeNode<InstanceNodeContent, char>* node, Table<char>* table, std::list<char>* ignore, Environment* env);

Environment* mapArgs(std::vector<Value>* values, std::list<Parameter*>* params, Environment* paramMapping) {
    // std::cout << "HERE with params " << params << " and args " << values << std::endl;
    if (params != nullptr) {
        // for param in params:
        //     if param in paramMapping:
        //         print("%s parameter is repeated" % param)
        if (values == nullptr || params->size() != values->size())
            return nullptr;
        std::list<Parameter*>::iterator param;
        std::vector<Value>::iterator value;
        for (param = params->begin(), value = values->begin();
                param != params->end() && value != values->end();
                ++param, ++value) {
            paramMapping->set((*param)->name, *value);
        }
    }
    return paramMapping;
}

bool checkCondition (LSysDParser::ExpressionContext* cond, Environment* paramMapping) {
    Value v = eval(cond, paramMapping);
    if (v.isBool()) {
        return v.asBool();
    } else if (!v.isError()) {
        err("The condition expression (of type " + v.type().name() + ") must be a boolean");
    }
    return false;
}

template<typename T>
Rule<T>* chooseRule(std::list<Rule<T>*>* rules) {
    if (rules->size() == 1)
        return rules->front();
    double total = 0.0;
    for (Rule<T>* r : *rules) {
        total += r->weight;
        if (r->weight < 0)
            return r;
    }
    std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();
    auto duration = now.time_since_epoch();
    auto millis = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
    double rnd = (double)rand() / RAND_MAX;
    srand(rand() + millis);
    double choice = total * rnd;
    double current = 0.0;
    for (Rule<T>* r : *rules) {
        current += r->weight;
        if (choice < current)
            return r;
    }
    err("No rule can be chosen in chooseRule()");
    return nullptr;
}

void err(std::string const& msg, std::string const& source, antlr4::tree::ParseTree* token, int len, int pos) {
    std::cerr << msg << std::endl;
    exit(1);
}

void warning(std::string const& msg, std::string const& source, antlr4::tree::ParseTree* token, int len, int pos) {
    std::cerr << msg << std::endl;
}

std::string strEscape(std::string const& s) {
    std::string str = s;
    str = std::regex_replace(str, std::regex("\\"), "\\\\");
    str = std::regex_replace(str, std::regex("\""), "\\\"");
    str = std::regex_replace(str, std::regex("\r"), "\\r");
    str = std::regex_replace(str, std::regex("\n"), "\\n");
    str = std::regex_replace(str, std::regex("\t"), "\\t");
    return str;
}

std::string strUnescape(std::string const& s) {
    std::string str = s;
    str = std::regex_replace(str, std::regex("\\\\"), "\\");
    str = std::regex_replace(str, std::regex("\\\""), "\"");
    str = std::regex_replace(str, std::regex("\\r"), "\r");
    str = std::regex_replace(str, std::regex("\\n"), "\n");
    str = std::regex_replace(str, std::regex("\\t"), "\t");
    return str;
}
    
}
