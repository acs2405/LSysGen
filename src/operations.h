
#pragma once


namespace lsysgen {

class Operations;

}

#include "common.h"
#include "values.h"
#include "ErrorHandler.h"

#include <string>
#include <iostream>


namespace lsysgen {

class Operations {
	ErrorHandler* eh;

	Value op_error(std::string const& op, Value const& op1, Value const& op2);
	Value op_error(std::string const& op, Value const& op1);

public:
	Operations(ErrorHandler* eh);

	~Operations();

	Value op_add(Value const& op1, Value const& op2);
	Value op_sub(Value const& op1, Value const& op2);
	Value op_mul(Value const& op1, Value const& op2);
	Value op_div(Value const& op1, Value const& op2);
	Value op_mod(Value const& op1, Value const& op2);
	Value op_pow(Value const& op1, Value const& op2);
	Value op_eq(Value const& op1, Value const& op2);
	Value op_ne(Value const& op1, Value const& op2);
	Value op_lt(Value const& op1, Value const& op2);
	Value op_le(Value const& op1, Value const& op2);
	Value op_gt(Value const& op1, Value const& op2);
	Value op_ge(Value const& op1, Value const& op2);
	Value op_and(Value const& op1, Value const& op2);
	Value op_or(Value const& op1, Value const& op2);
	Value op_bitand(Value const& op1, Value const& op2);
	Value op_bitor(Value const& op1, Value const& op2);
	Value op_bitxor(Value const& op1, Value const& op2);
	Value op_pos(Value const& op1);
	Value op_neg(Value const& op1);
	Value op_not(Value const& op1);
	Value op_bitnot(Value const& op1);

};

}
