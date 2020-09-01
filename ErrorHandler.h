
#pragma once


namespace lsys {

class ErrorHandler;
class Error;
class StackTrace;

}

#include "Token.h"
#include "ParserRuleContext.h"

#include <string>
#include <iostream>
#include <list>
#include <vector>
#include <sstream>
#include <regex>


namespace lsys {

class ErrorHandler {
	std::list<Error*>* _errors;

public:
	ErrorHandler();
	~ErrorHandler();

	void addError(Error* e);
	const std::list<Error*>* errors() const;
};

class Error {
	std::string msg;
	StackTrace* trace;

public:
	Error(std::string msg, StackTrace* trace);
	~Error();

    std::string buildMessage() const;
};

class StackTrace {
    antlr4::Token* tokInit;
    antlr4::Token* tokEnd;
    StackTrace* parent;
    // Environment* scope;
    std::vector<std::string>* sourceLines;
    std::string filename;

public:
    StackTrace(antlr4::Token* tokInit, antlr4::Token* tokEnd, StackTrace* parent, std::vector<std::string>* sourceLines, std::string filename);
    StackTrace(antlr4::ParserRuleContext* ctx, StackTrace* parent, std::vector<std::string>* sourceLines, std::string filename);
	~StackTrace();

    int getLineNumber() const;
    std::string getLine() const;
    std::string getMark() const;
    std::string getTraceString() const;
    std::string getCallTraceString() const;

    int getColNumber() const;
    int getLength() const;
    int getEndCol() const;
    int getPos() const;
    std::string getTokenText() const;
    const StackTrace* getParent() const;
    // const Environment* getScope() const;
    std::string const& getFilename() const;

};

}
