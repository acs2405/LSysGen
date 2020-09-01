
#include "operations.h"


#include <cmath>

namespace lsysgen {

Value op_error(std::string op, Value const& op1, Value const& op2) {
	if (!op1.isError() && !op2.isError())
		err("Cannot use operator " + op + " with a " + op1.type().name() + " and a " + op2.type().name());
	return Value::error();
}

Value op_error(std::string op, Value const& op1) {
	if (!op1.isError())
		err("Cannot use operator " + op + " with a " + op1.type().name());
	return Value::error();
}

Value op_add(Value const& op1, Value const& op2) {
	if (op1.isInt() && op2.isInt())
		return Value(op1.asInt() + op2.asInt());
	else if (op1.isFloat() && op2.isInt())
		return Value(op1.asFloat() + op2.asInt());
	else if (op1.isInt() && op2.isFloat())
		return Value(op1.asInt() + op2.asFloat());
	else if (op1.isFloat() && op2.isFloat())
		return Value(op1.asFloat() + op2.asFloat());
	// else if (op1.isString() && op2.isInt())
	// 	return Value(op1.asString() + op2.asInt());
	// else if (op1.isString() && op2.isFloat())
	// 	return Value(op1.asString() + op2.asFloat());
	else if (op1.isString() && op2.isString())
		return Value(op1.asString() + op2.asString());
	else 
		return op_error("+", op1, op2);
}

Value op_sub(Value const& op1, Value const& op2) {
	if (op1.isInt() && op2.isInt())
		return Value(op1.asInt() - op2.asInt());
	else if (op1.isFloat() && op2.isInt())
		return Value(op1.asFloat() - op2.asInt());
	else if (op1.isInt() && op2.isFloat())
		return Value(op1.asInt() - op2.asFloat());
	else if (op1.isFloat() && op2.isFloat())
		return Value(op1.asFloat() - op2.asFloat());
	else
		return op_error("-", op1, op2);
}

Value op_mul(Value const& op1, Value const& op2) {
	if (op1.isInt() && op2.isInt())
		return Value(op1.asInt() * op2.asInt());
	else if (op1.isFloat() && op2.isInt())
		return Value(op1.asFloat() * op2.asInt());
	else if (op1.isInt() && op2.isFloat())
		return Value(op1.asInt() * op2.asFloat());
	else if (op1.isFloat() && op2.isFloat())
		return Value(op1.asFloat() * op2.asFloat());
	else
		return op_error("*", op1, op2);
}

Value op_div(Value const& op1, Value const& op2) {
	if (op1.isInt() && op2.isInt())
		return Value(op1.asInt() / op2.asInt());
	else if (op1.isFloat() && op2.isInt())
		return Value(op1.asFloat() / op2.asInt());
	else if (op1.isInt() && op2.isFloat())
		return Value(op1.asInt() / op2.asFloat());
	else if (op1.isFloat() && op2.isFloat())
		return Value(op1.asFloat() / op2.asFloat());
	else
		return op_error("/", op1, op2);
}

Value op_mod(Value const& op1, Value const& op2) {
	if (op1.isInt() && op2.isInt())
		return Value(op1.asInt() % op2.asInt());
	// else if (op1.isFloat() && op2.isInt())
	// 	return Value(op1.asFloat() % op2.asInt());
	// else if (op1.isInt() && op2.isFloat())
	// 	return Value(op1.asInt() % op2.asFloat());
	// else if (op1.isFloat() && op2.isFloat())
	// 	return Value(op1.asFloat() % op2.asFloat());
	else
		return op_error("%", op1, op2);
}

Value op_pow(Value const& op1, Value const& op2) {
	if (op1.isInt() && op2.isInt())
		return Value(std::pow(static_cast<double>(op1.asInt()), op2.asInt()));
	else if (op1.isFloat() && op2.isInt())
		return Value(std::pow(op1.asFloat(), op2.asInt()));
	else if (op1.isInt() && op2.isFloat())
		return Value(std::pow(static_cast<double>(op1.asInt()), op2.asFloat()));
	else if (op1.isFloat() && op2.isFloat())
		return Value(std::pow(op1.asFloat(), op2.asFloat()));
	else
		return op_error("**", op1, op2);
}

Value op_eq(Value const& op1, Value const& op2) {
	if (op1.isInt() && op2.isInt())
		return Value(op1.asInt() == op2.asInt());
	else if (op1.isFloat() && op2.isInt())
		return Value(op1.asFloat() == op2.asInt());
	else if (op1.isInt() && op2.isFloat())
		return Value(op1.asInt() == op2.asFloat());
	else if (op1.isFloat() && op2.isFloat())
		return Value(op1.asFloat() == op2.asFloat());
	else if (op1.isBool() && op2.isBool())
		return Value(op1.asBool() == op2.asBool());
	else if (op1.isString() && op2.isString())
		return Value(op1.asString() == op2.asString());
	else 
		return op_error("==", op1, op2);
}

Value op_ne(Value const& op1, Value const& op2) {
	if (op1.isInt() && op2.isInt())
		return Value(op1.asInt() != op2.asInt());
	else if (op1.isFloat() && op2.isInt())
		return Value(op1.asFloat() != op2.asInt());
	else if (op1.isInt() && op2.isFloat())
		return Value(op1.asInt() != op2.asFloat());
	else if (op1.isFloat() && op2.isFloat())
		return Value(op1.asFloat() != op2.asFloat());
	else if (op1.isBool() && op2.isBool())
		return Value(op1.asBool() != op2.asBool());
	else if (op1.isString() && op2.isString())
		return Value(op1.asString() != op2.asString());
	else 
		return op_error("!=", op1, op2);
}

Value op_lt(Value const& op1, Value const& op2) {
	if (op1.isInt() && op2.isInt())
		return Value(op1.asInt() < op2.asInt());
	else if (op1.isFloat() && op2.isInt())
		return Value(op1.asFloat() < op2.asInt());
	else if (op1.isInt() && op2.isFloat())
		return Value(op1.asInt() < op2.asFloat());
	else if (op1.isFloat() && op2.isFloat())
		return Value(op1.asFloat() < op2.asFloat());
	else if (op1.isString() && op2.isString())
		return Value(op1.asString() < op2.asString());
	else 
		return op_error("<", op1, op2);
}

Value op_le(Value const& op1, Value const& op2) {
	if (op1.isInt() && op2.isInt())
		return Value(op1.asInt() <= op2.asInt());
	else if (op1.isFloat() && op2.isInt())
		return Value(op1.asFloat() <= op2.asInt());
	else if (op1.isInt() && op2.isFloat())
		return Value(op1.asInt() <= op2.asFloat());
	else if (op1.isFloat() && op2.isFloat())
		return Value(op1.asFloat() <= op2.asFloat());
	else if (op1.isString() && op2.isString())
		return Value(op1.asString() <= op2.asString());
	else 
		return op_error("<=", op1, op2);
}

Value op_gt(Value const& op1, Value const& op2) {
	if (op1.isInt() && op2.isInt())
		return Value(op1.asInt() > op2.asInt());
	else if (op1.isFloat() && op2.isInt())
		return Value(op1.asFloat() > op2.asInt());
	else if (op1.isInt() && op2.isFloat())
		return Value(op1.asInt() > op2.asFloat());
	else if (op1.isFloat() && op2.isFloat())
		return Value(op1.asFloat() > op2.asFloat());
	else if (op1.isString() && op2.isString())
		return Value(op1.asString() > op2.asString());
	else 
		return op_error(">", op1, op2);
}

Value op_ge(Value const& op1, Value const& op2) {
	if (op1.isInt() && op2.isInt())
		return Value(op1.asInt() >= op2.asInt());
	else if (op1.isFloat() && op2.isInt())
		return Value(op1.asFloat() >= op2.asInt());
	else if (op1.isInt() && op2.isFloat())
		return Value(op1.asInt() >= op2.asFloat());
	else if (op1.isFloat() && op2.isFloat())
		return Value(op1.asFloat() >= op2.asFloat());
	else if (op1.isString() && op2.isString())
		return Value(op1.asString() >= op2.asString());
	else 
		return op_error(">=", op1, op2);
}

Value op_and(Value const& op1, Value const& op2) {
	if (op1.isBool() && op2.isBool())
		return Value(op1.asBool() && op2.asBool());
	else 
		return op_error("and", op1, op2);
}

Value op_or(Value const& op1, Value const& op2) {
	if (op1.isBool() && op2.isBool())
		return Value(op1.asBool() || op2.asBool());
	else 
		return op_error("or", op1, op2);
}

Value op_bitand(Value const& op1, Value const& op2) {
	if (op1.isInt() && op2.isInt())
		return Value(op1.asInt() & op2.asInt());
	else 
		return op_error("&", op1, op2);
}

Value op_bitor(Value const& op1, Value const& op2) {
	if (op1.isInt() && op2.isInt())
		return Value(op1.asInt() | op2.asInt());
	else 
		return op_error("|", op1, op2);
}

Value op_bitxor(Value const& op1, Value const& op2) {
	if (op1.isInt() && op2.isInt())
		return Value(op1.asInt() ^ op2.asInt());
	else 
		return op_error("^", op1, op2);
}

Value op_pos(Value const& op1) {
	if (op1.isInt())
		return Value(op1.asInt());
	if (op1.isFloat())
		return Value(op1.asFloat());
	else 
		return op_error("+", op1);
}

Value op_neg(Value const& op1) {
	if (op1.isInt())
		return Value(-op1.asInt());
	if (op1.isFloat())
		return Value(-op1.asFloat());
	else 
		return op_error("-", op1);
}

Value op_not(Value const& op1) {
	if (op1.isBool())
		return Value(!op1.asBool());
	else 
		return op_error("not", op1);
}

Value op_bitnot(Value const& op1) {
	if (op1.isInt())
		return Value(~op1.asInt());
	else 
		return op_error("~", op1);
}

}