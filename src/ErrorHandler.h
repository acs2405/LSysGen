
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
#include <string_view>
#include <iostream>
#include <list>
#include <vector>


namespace lsysgen {

class Message {
public:
    typedef enum {
        NONE,
        FATAL_ERROR,
        ERROR,
        WARNING,
        NOTICE
    } Type;

private:
    Message::Type _type;
    std::string const _msg;
    StackTrace const* _trace;

public:
    Message(Message::Type type, std::string_view const msg, StackTrace const* trace);
    ~Message();

    bool isFatalError() const;
    bool isError() const;
    bool isWarning() const;
    bool isNotice() const;
    Message::Type type() const;

    std::string buildMessage() const;

    static std::string colored(Message::Type type, std::string const& content);
    static std::string bold(std::string const& content);

    // void print(std::ostream& os) const;
    // void print() const;
};

std::ostream & operator<<(std::ostream & os, Message const& m);


class ErrorHandler {
public:
    // typedef enum {
    //     NONE,
    //     COLOR_TERMINAL
    //     // HTML
    // } Format;

    static bool const terminalSupportsColors;

private:
    std::list<Message const*> _messages;
    std::list<Message const*> _errors;
    std::list<Message const*> _warnings;
    std::list<Message const*> _notices;

    bool _failed;
    bool _stdin;
    // ErrorHandler::Format _format;

    std::string const _filename;
    StackTrace const* _parentTrace;

    Message * createMessage(std::string_view const msg, Message::Type msgType=Message::Type::NONE, StackTrace const* st=nullptr) const;
    void addMessage(Message const* msg);

public:
    ErrorHandler(std::string_view const filename, StackTrace const* st=nullptr);
    ErrorHandler(ErrorHandler const& eh);
    ~ErrorHandler();

    void fatalError(std::string_view const msg, StackTrace const* st=nullptr);
    void error(std::string_view const msg, StackTrace const* st=nullptr);
    void warning(std::string_view const msg, StackTrace const* st=nullptr);
    void notice(std::string_view const msg, StackTrace const* st=nullptr);
    // void error(std::string_view const msg, antlr4::ParserRuleContext* ctx);
    // void error(std::string_view const msg, antlr4::tree::TerminalNode* terminal);

    void dump();

    StackTrace * trace(antlr4::Token const* tokInit, antlr4::Token const* tokEnd=nullptr, std::string_view const text="");
    StackTrace * trace(antlr4::tree::TerminalNode * t1, antlr4::tree::TerminalNode * t2=nullptr, std::string_view const text="");
    StackTrace * trace(antlr4::ParserRuleContext const* ctx1, antlr4::ParserRuleContext const* ctx2=nullptr, std::string_view const text="");

    void traceDown(StackTrace const* st);
    void traceUp();

    StackTrace const* currentTrace() const;

    bool failed() const;
    bool fromStdin() const;
    // ErrorHandler::Format format() const;

    std::list<Message const*> const& messages() const;
    std::list<Message const*> const& errors() const;
    std::list<Message const*> const& warnings() const;
    std::list<Message const*> const& notices() const;

    std::string const& fileName() const;
};


class StackTrace {
    antlr4::Token const* _tokInit;
    antlr4::Token const* _tokEnd;
    StackTrace const* _parent;
    std::string _text;

    std::vector<std::string> const* _sourceLines;
    std::string const _filename;

public:
    StackTrace(std::string_view const text, 
            antlr4::Token const* tokInit, 
            antlr4::Token const* tokEnd, 
            StackTrace const* parent, 
            std::string_view const filename);
    StackTrace(StackTrace const& st);
	~StackTrace();

    std::string getLine() const;
    std::string getMessageLine(Message::Type msgType=Message::Type::NONE) const;
    std::string getMessageMark(Message::Type msgType=Message::Type::NONE) const;
    std::string getTraceString(Message::Type msgType=Message::Type::NONE, std::string_view const text="") const;
    // std::string getCallTraceString(int msgType=0) const;

    int getLineNumber() const;
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
