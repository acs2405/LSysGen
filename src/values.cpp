
#include "values.h"


#include "misc.h"

#include <iomanip>


namespace lsysgen {

Parameter::Parameter(std::string_view const name): name(static_cast<std::string>(name)) {}

bool operator==(Parameter const& p1, Parameter const& p2) {return p1.name == p2.name;}



Function::Function(std::list<Parameter *> * params, 
            LSysDParser::ExpressionContext * expr, 
            antlr4::tree::ParseTree * ctx):
        _params(params), expr(expr), ctx(ctx) {}

std::list<Parameter *> const* Function::params() const {return this->_params;}

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

Value Function::call(std::list<Value> * args, Scope * scope, LSysDExpressionEvaluator * ee) {
    Scope paramMapping(scope);
    if ((args == nullptr && this->_params != nullptr && this->_params->size() > 0) || 
        (args != nullptr && this->_params != nullptr && this->_params->size() != args->size()))
        return Value::error();
    std::list<Parameter*>::iterator param;
    std::list<Value>::iterator arg;
    for (param = this->_params->begin(), arg = args->begin();
            param != this->_params->end();
            ++param, ++arg)
        paramMapping.set((*param)->name, *arg);
    return ee->eval(this->expr, &paramMapping);
}



ValueType::ValueType(std::string_view const name): _name(static_cast<std::string>(name)) {}

std::string const& ValueType::name() const {return this->_name;}

ValueType const ValueType::INT_TYPE("int");
ValueType const ValueType::FLOAT_TYPE("float");
ValueType const ValueType::BOOL_TYPE("bool");
ValueType const ValueType::STRING_TYPE("string");
ValueType const ValueType::FUNCTION_TYPE("function");
ValueType const ValueType::LSYSTEM_TYPE("lsystem");
ValueType const ValueType::NULL_TYPE("nullType");
ValueType const ValueType::ERROR_TYPE("error");



Value::Value(ValueType const* type, std::any const& value): _type(type), _value(value) {}
Value::Value(): _type(&ValueType::ERROR_TYPE), _value(antlrcpp::Any()) {}
Value::Value(int value): _type(&ValueType::INT_TYPE), _value(value) {}
Value::Value(double value): _type(&ValueType::FLOAT_TYPE), _value(value) {}
Value::Value(bool value): _type(&ValueType::BOOL_TYPE), _value(value) {}
Value::Value(std::string_view const value): _type(&ValueType::STRING_TYPE), _value(static_cast<std::string>(value)) {}
Value::Value(Function* value): _type(&ValueType::FUNCTION_TYPE), _value(value) {}
Value::Value(LSystem<char> * value): _type(&ValueType::LSYSTEM_TYPE), _value(value) {}
Value::Value(std::nullptr_t value): _type(&ValueType::NULL_TYPE), _value(value) {}

ValueType const* Value::type() const {return this->_type;}

bool Value::is (ValueType const* t) const {return t == _type;}

bool Value::isInt () const {return this->is(&ValueType::INT_TYPE);}
bool Value::isFloat () const {return this->is(&ValueType::FLOAT_TYPE);}
bool Value::isBool () const {return this->is(&ValueType::BOOL_TYPE);}
bool Value::isString () const {return this->is(&ValueType::STRING_TYPE);}
bool Value::isFunction () const {return this->is(&ValueType::FUNCTION_TYPE);}
bool Value::isLSystem () const {return this->is(&ValueType::LSYSTEM_TYPE);}
bool Value::isNull () const {return this->is(&ValueType::NULL_TYPE);}
bool Value::isError () const {return this->is(&ValueType::ERROR_TYPE);}

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
std::nullptr_t Value::asNull () const {return this->as<std::nullptr_t>();}
Function * Value::asFunction () {return this->as<Function *>();}
Function const* Value::asFunction () const {return this->as<Function const*>();}
LSystem<char> * Value::asLSystem () {return this->as<LSystem<char> *>();}
LSystem<char> const* Value::asLSystem () const {return this->as<LSystem<char> const*>();}

template<typename T>
T Value::as () {
    return std::any_cast<T>(this->_value);
}
template<typename T>
const T Value::as () const {
    return std::any_cast<T>(this->_value);
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
        return this->as<Function *>()->toString();
    } else if (this->isLSystem()) {
        return "<LSystem " + this->as<LSystem<char> *>()->name() + ">";
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
Value const& Value::null() {return Value::NIL;}

Value const Value::ERROR = Value(&ValueType::ERROR_TYPE, nullptr);
Value const Value::NIL = Value(&ValueType::NULL_TYPE, nullptr);



Scope::Scope(): Scope(nullptr) {}
Scope::Scope(Scope * parent): 
        _parent(parent), mapping() {}
// Scope::Scope(Scope const& scope): 
//         parent(scope.parent), 
//         mapping(scope.mapping.begin(), scope.mapping.end()) {}

Scope::~Scope() {
    // delete this->mapping;
}

Scope * Scope::parent()  {return this->_parent;}
Scope const* Scope::parent() const {return this->_parent;}

void Scope::set(std::string const& var, Value const& val) {
    mapping[var] =  val;
}

Value const& Scope::get(std::string const& var) const {
    if (mapping.find(var) != mapping.end()) {
        return mapping.find(var)->second;
    } else if (_parent != nullptr) {
        return _parent->get(var);
    }
    return Value::null();
}

bool Scope::has(std::string const& var) const {
    if (mapping.find(var) != mapping.end())
        return true;
    else if (_parent != nullptr)
        return _parent->has(var);
    return false;
}

void Scope::merge(Scope const* scope) {
    mapping.insert(scope->mapping.begin(), scope->mapping.end());
}

}
