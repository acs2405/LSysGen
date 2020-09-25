
#pragma once


namespace lsysgen {

class MessageManager;
class ErrorHandler;
class Message;
class StackTrace;

}

#include "antlr4-runtime.h"
#include "ParserRuleContext.h"

#include <string>
#include <iostream>
#include <list>
#include <vector>


namespace lsysgen {

class ErrorHandler {
    std::list<Message const*> _messages;
    std::list<Message const*> _errors;
    std::list<Message const*> _warnings;
    std::list<Message const*> _notices;

    bool _failed;
    bool _stdin;

    std::string const _filename;
    std::vector<std::string> const* _sourceLines;
    StackTrace const* _parentTrace;

    Message * createMessage(std::string const& msg, int msgType=0, StackTrace const* st=nullptr) const;
    void addMessage(Message const* msg);

public:
    ErrorHandler(std::string const& filename, std::vector<std::string> const* sourceLines, StackTrace const* st=nullptr);
    ErrorHandler(ErrorHandler const& eh);
    ~ErrorHandler();

    void fatalError(std::string const& msg, StackTrace const* st=nullptr);
    void error(std::string const& msg, StackTrace const* st=nullptr);
    void warning(std::string const& msg, StackTrace const* st=nullptr);
    void notice(std::string const& msg, StackTrace const* st=nullptr);
    // void error(std::string const& msg, antlr4::ParserRuleContext* ctx);
    // void error(std::string const& msg, antlr4::tree::TerminalNode* terminal);

    void dump();

    StackTrace * trace(antlr4::Token const* tokInit, antlr4::Token const* tokEnd=nullptr, std::string const& text="");
    StackTrace * trace(antlr4::tree::TerminalNode * t1, antlr4::tree::TerminalNode * t2=nullptr, std::string const& text="");
    StackTrace * trace(antlr4::ParserRuleContext const* ctx1, antlr4::ParserRuleContext const* ctx2=nullptr, std::string const& text="");

    void traceDown(StackTrace const* st);
    void traceUp();

    StackTrace const* currentTrace() const;

    bool failed() const;
    bool stdin() const;

    std::list<Message const*> const& messages() const;
    std::list<Message const*> const& errors() const;
    std::list<Message const*> const& warnings() const;
    std::list<Message const*> const& notices() const;

    std::string const& fileName() const;
};

class Message {
public:
    static const int TYPE_FATAL_ERROR;
    static const int TYPE_ERROR;
    static const int TYPE_WARNING;
    static const int TYPE_NOTICE;

private:
    int _type;
	std::string const _msg;
	StackTrace const* _trace;

public:
	Message(int type, std::string const& msg, StackTrace const* trace);
	~Message();

    bool isFatalError() const;
    bool isError() const;
    bool isWarning() const;
    bool isNotice() const;

    std::string buildMessage() const;

    // void print(std::ostream& os) const;
    // void print() const;
};

std::ostream & operator<<(std::ostream & os, Message const& m);


class StackTrace {
    antlr4::Token const* _tokInit;
    antlr4::Token const* _tokEnd;
    StackTrace const* _parent;
    std::string _text;

    std::vector<std::string> const* _sourceLines;
    std::string const _filename;

public:
    StackTrace(std::string const& text, 
            antlr4::Token const* tokInit, 
            antlr4::Token const* tokEnd, 
            StackTrace const* parent, 
            std::vector<std::string> const* sourceLines, 
            std::string const& filename);
    StackTrace(StackTrace const& st);
	~StackTrace();

    int getLineNumber() const;
    std::string getLine(std::string const& format="") const;
    std::string getMark(std::string const& format="") const;
    std::string getTraceString(int msgType=0, std::string const& text="") const;
    // std::string getCallTraceString(int msgType=0) const;

    int getColNumber() const;
    int getLength() const;
    int getEndCol() const;
    int getPos() const;
    // std::string getTokenText() const;
    StackTrace const* getParent() const;
    // StackTrace* getParent();
    std::string const& getFilename() const;

};

}
