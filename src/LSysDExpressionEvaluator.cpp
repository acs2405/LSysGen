#include "LSysDExpressionEvaluator.h"


LSysDExpressionEvaluator::LSysDExpressionEvaluator(): env(nullptr) {}

LSysDExpressionEvaluator::~LSysDExpressionEvaluator() {}

// string LSysDExpressionEvaluator::getFullText(antlr4::RuleContext* ctx) {
//     return ctx->getText();
// }

void LSysDExpressionEvaluator::error(std::string msg, antlr4::tree::ParseTree* token, int len, int pos) {
    err(msg, "<inline>", token, len, pos);
}


Value LSysDExpressionEvaluator::eval(LSysDParser::ExpressionContext* expr, Environment* env) {
    this->env = env;
    Value ret = this->visit(expr);
    this->env = nullptr;
    return ret;
}


antlrcpp::Any LSysDExpressionEvaluator::visitConstExpr(LSysDParser::ConstExprContext *ctx) {
    return this->visit(ctx->constant());
}

antlrcpp::Any LSysDExpressionEvaluator::visitIdExpr(LSysDParser::IdExprContext *ctx) {
    std::string name = ctx->ID()->getText();
    if (this->env->has(name)) {
        return Value(this->env->get(name));
    } else {
        this->error("Undefined name '" + name + "'", ctx);
        return Value::error();
    }
}

antlrcpp::Any LSysDExpressionEvaluator::visitAritBinaryExpr(LSysDParser::AritBinaryExprContext *ctx) {
    Value op1 = this->visit(ctx->expression()[0]);
    Value op2 = this->visit(ctx->expression()[1]);
    Value res = Value::error();
    if (ctx->ADD()) {
        res = op_add(op1, op2);
    } else if (ctx->SUB()) {
        res = op_sub(op1, op2);
    } else if (ctx->MUL()) {
        res = op_mul(op1, op2);
    } else if (ctx->DIV()) {
        res = op_div(op1, op2);
    } else if (ctx->MOD()) {
        res = op_mod(op1, op2);
    } else if (ctx->POW()) {
        res = op_pow(op1, op2);
    }
    return res;
}

// antlrcpp::Any LSysDExpressionEvaluator::visitFunctionDefExpr(LSysDParser::FunctionDefExprContext *ctx) {
//     return visitChildren(ctx);
// }

// antlrcpp::Any LSysDExpressionEvaluator::visitIndexExpr(LSysDParser::IndexExprContext *ctx) {
//     return visitChildren(ctx);
// }

// antlrcpp::Any LSysDExpressionEvaluator::visitSetDefExpr(LSysDParser::SetDefExprContext *ctx) {
//     return visitChildren(ctx);
// }

antlrcpp::Any LSysDExpressionEvaluator::visitLogicBinaryExpr(LSysDParser::LogicBinaryExprContext *ctx) {
    Value op1 = this->visit(ctx->expression()[0]);
    Value op2 = this->visit(ctx->expression()[1]);
    Value res = Value::error();
    if (ctx->AND()) {
        res = op_and(op1, op2);
    } else if (ctx->OR()) {
        res = op_or(op1, op2);
    }
    return res;
}

antlrcpp::Any LSysDExpressionEvaluator::visitCmpBinaryExpr(LSysDParser::CmpBinaryExprContext *ctx) {
    Value op1 = this->visit(ctx->expression()[0]);
    Value op2 = this->visit(ctx->expression()[1]);
    Value res = Value::error();
    if (ctx->EQ()) {
        res = op_eq(op1, op2);
    } else if (ctx->NE()) {
        res = op_ne(op1, op2);
    } else if (ctx->LT()) {
        res = op_lt(op1, op2);
    } else if (ctx->LE()) {
        res = op_le(op1, op2);
    } else if (ctx->GT()) {
        res = op_gt(op1, op2);
    } else if (ctx->GE()) {
        res = op_ge(op1, op2);
    }
    return res;
}

antlrcpp::Any LSysDExpressionEvaluator::visitFunctionCallExpr(LSysDParser::FunctionCallExprContext *ctx) {
    std::list<Value>* args = this->visitArguments(ctx->arguments());
    Value vf = this->visit(ctx->expression());
    if (vf.isFunction()) {
        return vf.asFunction()->call(args);
    } else if (!vf.isError()) {
        // this->error("'" + vf.type().name() + "' is not a function", ctx->expression());
    }
    return Value::error();
}

// antlrcpp::Any LSysDExpressionEvaluator::visitTupleDefExpr(LSysDParser::TupleDefExprContext *ctx) {
//     return visitChildren(ctx);
// }

antlrcpp::Any LSysDExpressionEvaluator::visitBitBinaryExpr(LSysDParser::BitBinaryExprContext *ctx) {
    Value op1 = this->visit(ctx->expression()[0]);
    Value op2 = this->visit(ctx->expression()[1]);
    Value res = Value::error();
    if (ctx->BITAND()) {
        res = op_bitand(op1, op2);
    } else if (ctx->BITOR()) {
        res = op_bitor(op1, op2);
    } else if (ctx->BITXOR()) {
        res = op_bitxor(op1, op2);
    }
    return res;
}

// antlrcpp::Any LSysDExpressionEvaluator::visitListDefExpr(LSysDParser::ListDefExprContext *ctx) {
//     return visitChildren(ctx);
// }

// antlrcpp::Any LSysDExpressionEvaluator::visitMapDefExpr(LSysDParser::MapDefExprContext *ctx) {
//     return visitChildren(ctx);
// }

antlrcpp::Any LSysDExpressionEvaluator::visitAritUnaryExpr(LSysDParser::AritUnaryExprContext *ctx) {
    Value op1 = this->visit(ctx->expression());
    Value res = Value::error();
    if (ctx->ADD()) {
        res = op_pos(op1);
    } else if (ctx->SUB()) {
        res = op_neg(op1);
    }
    return res;
}

antlrcpp::Any LSysDExpressionEvaluator::visitLogicUnaryExpr(LSysDParser::LogicUnaryExprContext *ctx) {
    Value op1 = this->visit(ctx->expression());
    Value res = Value::error();
    if (ctx->NOT()) {
        res = op_not(op1);
    } else if (ctx->BITNOT()) {
        res = op_bitnot(op1);
    }
    return res;
}

antlrcpp::Any LSysDExpressionEvaluator::visitParenthesizedExpr(LSysDParser::ParenthesizedExprContext *ctx) {
    return this->visit(ctx->expression());
}

// antlrcpp::Any LSysDExpressionEvaluator::visitPropertyAccessorExpr(LSysDParser::PropertyAccessorExprContext *ctx) {
//     return visitChildren(ctx);
// }

// antlrcpp::Any LSysDExpressionEvaluator::visitInExpr(LSysDParser::InExprContext *ctx) {
//     return visitChildren(ctx);
// }

antlrcpp::Any LSysDExpressionEvaluator::visitIfElseExpr(LSysDParser::IfElseExprContext *ctx) {
    Value cond = this->visit(ctx->expression()[0]);
    Value res = Value::error();
    if (cond.isBool())
        res = this->visit(ctx->expression()[cond.asBool() ? 1 : 2]);
    else
        this->error("The condition expression (of type " + cond.type().name() + ") must be a boolean");
    return res;
}

antlrcpp::Any LSysDExpressionEvaluator::visitArguments(LSysDParser::ArgumentsContext *ctx) {
    std::list<Value>* args = new std::list<Value>();
    for (LSysDParser::ArgumentContext* argctx : ctx->argument())
        args->push_back(this->visitArgument(argctx));
    return args;
}

antlrcpp::Any LSysDExpressionEvaluator::visitArgument(LSysDParser::ArgumentContext *ctx) {
    return this->visit(ctx->expression());
}

// antlrcpp::Any LSysDExpressionEvaluator::visitIndexes(LSysDParser::IndexesContext *ctx) {
//     return visitChildren(ctx);
// }

// antlrcpp::Any LSysDExpressionEvaluator::visitIndex(LSysDParser::IndexContext *ctx) {
//     return visitChildren(ctx);
// }

// antlrcpp::Any LSysDExpressionEvaluator::visitFormalParameters(LSysDParser::FormalParametersContext *ctx) {
//     return visitChildren(ctx);
// }

// antlrcpp::Any LSysDExpressionEvaluator::visitFormalParameter(LSysDParser::FormalParameterContext *ctx) {
//     return visitChildren(ctx);
// }

// antlrcpp::Any LSysDExpressionEvaluator::visitIteratordef(LSysDParser::IteratordefContext *ctx) {
//     return visitChildren(ctx);
// }

// antlrcpp::Any LSysDExpressionEvaluator::visitListdef(LSysDParser::ListdefContext *ctx) {
//     return visitChildren(ctx);
// }

// antlrcpp::Any LSysDExpressionEvaluator::visitTupledef(LSysDParser::TupledefContext *ctx) {
//     return visitChildren(ctx);
// }

// antlrcpp::Any LSysDExpressionEvaluator::visitSetdef(LSysDParser::SetdefContext *ctx) {
//     return visitChildren(ctx);
// }

// antlrcpp::Any LSysDExpressionEvaluator::visitMapdef(LSysDParser::MapdefContext *ctx) {
//     return visitChildren(ctx);
// }

// antlrcpp::Any LSysDExpressionEvaluator::visitMapiteratordef(LSysDParser::MapiteratordefContext *ctx) {
//     return visitChildren(ctx);
// }

// antlrcpp::Any LSysDExpressionEvaluator::visitMapitem(LSysDParser::MapitemContext *ctx) {
//     return visitChildren(ctx);
// }

// antlrcpp::Any LSysDExpressionEvaluator::visitFunctiondef(LSysDParser::FunctiondefContext *ctx) {
//     return visitChildren(ctx);
// }

// antlrcpp::Any LSysDExpressionEvaluator::visitSource(LSysDParser::SourceContext *ctx) {
//     return visitChildren(ctx);
// }

antlrcpp::Any LSysDExpressionEvaluator::visitIntConstant(LSysDParser::IntConstantContext *ctx) {
    int i;
    if (ctx->INT()->getText().find('x') == std::string::npos) {
        i = std::stoi(ctx->INT()->getText());
    } else {
        std::string s = ctx->INT()->getText();
        i = std::stoi(s.substr(2), nullptr, 16);
    }
    return Value(i);
}

antlrcpp::Any LSysDExpressionEvaluator::visitFloatConstant(LSysDParser::FloatConstantContext *ctx) {
    double f = stod(ctx->FLOAT()->getText());
    return Value(f);
}

antlrcpp::Any LSysDExpressionEvaluator::visitStringConstant(LSysDParser::StringConstantContext *ctx) {
    std::string s = ctx->STRING()->getText();
    return Value(strUnescape(s.substr(1, s.size()-2)));
}

antlrcpp::Any LSysDExpressionEvaluator::visitTrueValue(LSysDParser::TrueValueContext *ctx) {
    return Value(true);
}

antlrcpp::Any LSysDExpressionEvaluator::visitFalseValue(LSysDParser::FalseValueContext *ctx) {
    return Value(false);
}

// antlrcpp::Any LSysDExpressionEvaluator::visitNullValue(LSysDParser::NullValueContext *ctx) {
//     return Value(nullptr);
// }
