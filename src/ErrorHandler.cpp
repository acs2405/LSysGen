
#include "ErrorHandler.h"


#include <sstream>
#include <regex>


namespace lsysgen {

ErrorHandler::ErrorHandler(std::string_view const filename, StackTrace const* st): 
        _filename(filename.size() > 0 && filename != "-" ? filename : "<inline>"), 
        _parentTrace(st), _messages(), _errors(), _warnings(), _notices(), _failed(false), 
        _stdin(filename == "-") {}

ErrorHandler::ErrorHandler(ErrorHandler const& eh): 
        _filename(eh._filename), _parentTrace(eh._parentTrace), 
        _messages(), _errors(), _warnings(), _notices(), _failed(false), _stdin(eh._stdin) {}

ErrorHandler::~ErrorHandler() {
    _messages.clear();
}

void ErrorHandler::fatalError(std::string_view const msg, StackTrace const* st) {
    Message const* e = this->createMessage(msg, Message::TYPE_FATAL_ERROR, st);
    _errors.push_back(e);
    _failed = true;
    this->addMessage(e);
    // this->dump();
    // std::cerr << "LSystem halted due to a runtime error." << std::endl;
    // exit(1);
}

void ErrorHandler::error(std::string_view const msg, StackTrace const* st) {
    Message const* err = this->createMessage(msg, Message::TYPE_ERROR, st);
    _errors.push_back(err);
    _failed = true;
    this->addMessage(err);
}

void ErrorHandler::warning(std::string_view const msg, StackTrace const* st) {
    Message const* warn = this->createMessage(msg, Message::TYPE_WARNING, st);
    _warnings.push_back(warn);
    this->addMessage(warn);
}

void ErrorHandler::notice(std::string_view const msg, StackTrace const* st) {
    Message const* notice = this->createMessage(msg, Message::TYPE_NOTICE, st);
    _notices.push_back(notice);
    this->addMessage(notice);
}

Message * ErrorHandler::createMessage(std::string_view const msg, int msgType, StackTrace const* st) const {
    // st must never be in the parent trace stack.
    if (st == nullptr) {
        if (_parentTrace != nullptr)
            st = new StackTrace(*_parentTrace);
    }
    return new Message(msgType, msg, st);
}

void ErrorHandler::addMessage(Message const* m) {
    _messages.push_back(m);
    std::cerr << *m << std::endl;
}

void ErrorHandler::dump() {
    // // Do not print here if you delete traces when abandoned
    // for (Message const* msg : _messages)
    //     std::cerr << *msg << std::endl;
    _messages.clear();
    _errors.clear();
    _warnings.clear();
    _notices.clear();
}

StackTrace * ErrorHandler::trace(antlr4::Token const* tokInit, antlr4::Token const* tokEnd, std::string_view const text) {
    antlr4::Token const* end = tokEnd != nullptr ? tokEnd : tokInit;
    return new StackTrace(text, tokInit, end, _parentTrace, _filename);
}

StackTrace * ErrorHandler::trace(antlr4::tree::TerminalNode * t1, antlr4::tree::TerminalNode * t2, std::string_view const text) {
    return this->trace(t1->getSymbol(), t2 != nullptr ? t2->getSymbol() : t1->getSymbol(), text);
}

StackTrace * ErrorHandler::trace(antlr4::ParserRuleContext const* ctx1, antlr4::ParserRuleContext const* ctx2, std::string_view const text) {
    return this->trace(ctx1->start, ctx2 != nullptr ? ctx2->stop : ctx1->stop, text);
}

void ErrorHandler::traceDown(StackTrace const* st) {
    this->_parentTrace = st;
}

void ErrorHandler::traceUp() {
    StackTrace const* parent = _parentTrace->getParent();
    delete this->_parentTrace;
    this->_parentTrace = parent;
}

StackTrace const* ErrorHandler::currentTrace() const {return _parentTrace;}

bool ErrorHandler::failed () const {return _failed;}
bool ErrorHandler::fromStdin() const {return _stdin;}

std::list<Message const*> const& ErrorHandler::messages() const {return _messages;}
std::list<Message const*> const& ErrorHandler::errors() const {return _errors;}
std::list<Message const*> const& ErrorHandler::warnings() const {return _warnings;}
std::list<Message const*> const& ErrorHandler::notices() const {return _notices;}

std::string const& ErrorHandler::fileName() const {return _filename;}



const int Message::TYPE_FATAL_ERROR = 1;
const int Message::TYPE_ERROR = 2;
const int Message::TYPE_WARNING = 3;
const int Message::TYPE_NOTICE = 4;

Message::Message(int type, std::string_view const msg, StackTrace const* trace): 
        _type(type), _msg(msg), _trace(trace) {}
Message::~Message() {
    delete this->_trace;
}

bool Message::isFatalError() const {return _type == Message::TYPE_FATAL_ERROR;}
bool Message::isError() const {return _type == Message::TYPE_ERROR;}
bool Message::isWarning() const {return _type == Message::TYPE_WARNING;}
bool Message::isNotice() const {return _type == Message::TYPE_NOTICE;}

std::string Message::buildMessage() const {
    std::string msgTypeStr;
    if (this->isFatalError())
        msgTypeStr = "\u001b[1m\u001b[31mFATAL ERROR:\u001b[0m " + _msg;
    else if (this->isError())
        msgTypeStr = "\u001b[1m\u001b[31mERROR:\u001b[0m " + _msg;
    else if (this->isWarning())
        msgTypeStr = "\u001b[1m\u001b[33mWARNING:\u001b[0m " + _msg;
    else if (this->isNotice())
        msgTypeStr = "\u001b[1m\u001b[36mNOTICE:\u001b[0m " + _msg;
    else
        msgTypeStr = "\u001b[1m\u001b[32mMESSAGE:\u001b[0m " + _msg;
    if (_trace)
        return _trace->getTraceString(_type, msgTypeStr);
    else {
        std::stringstream ss;
        ss << msgTypeStr << std::endl;
        return ss.str();
    }
}

// void Message::print(std::ostream& os) const {
//     os << this->buildMessage() << std::endl;
// }

// void Message::print() const {
//     this->print(std::cerr);
// }

std::ostream & operator<<(std::ostream & os, Message const& m) {
    return os << m.buildMessage();
}



StackTrace::StackTrace(std::string_view const text, 
            antlr4::Token const* tokInit, 
            antlr4::Token const* tokEnd, 
            StackTrace const* parent, 
            std::string_view const filename):
        _text(text), _tokInit(tokInit), _tokEnd(tokEnd), _parent(parent), 
        _filename(filename) {}

StackTrace::StackTrace(StackTrace const& st): 
        _text(st._text), _tokInit(st._tokInit), _tokEnd(st._tokEnd), _parent(st._parent), //_parent(new StackTrace(*st._parent)),
        _filename(st._filename) {}

// StackTrace::StackTrace(antlr4::ParserRuleContext* ctx, StackTrace* parent, std::vector<std::string>* sourceLines, std::string filename): 
//         StackTrace(ctx->start, ctx->stop, parent, sourceLines, filename) {}

StackTrace::~StackTrace() {}

std::string StackTrace::getLine() const {
    antlr4::CharStream * input = _tokInit->getInputStream();
    // if (_tokInit->getStartIndex() < input->size() && _tokInit->getStopIndex() < input->size())
    std::string untilTokEnd = input->getText(antlr4::misc::Interval(_tokInit->getStartIndex() - _tokInit->getCharPositionInLine(), _tokInit->getStopIndex()));
    int maxAfter = 60; // Takes up to 60 characters since _tokEnd->getStopIndex() + 1
    int after = std::min(maxAfter, static_cast<int>(input->size() - _tokInit->getStopIndex()));
    // if (_tokInit->getStopIndex() + 1 < input->size())
    std::string afterTokEnd = input->getText(antlr4::misc::Interval(_tokInit->getStopIndex() + 1, _tokInit->getStopIndex() + after));
    // afterTokEnd may contain line breaks
    std::string::size_type breakPos = afterTokEnd.find('\n');
    if (breakPos == std::string::npos)
        return untilTokEnd + afterTokEnd;
    else {
        std::string untilBreak(afterTokEnd.begin(), afterTokEnd.begin() + breakPos);
        return untilTokEnd + untilBreak;
    }
}

std::string StackTrace::getMessageLine(std::string const& format) const {
    // std::cout << "HERE!" << std::endl;
    int n = this->getColNumber();
    int len = this->getLength();
    std::regex retab ("\t");
    std::string normalFormat = "\u001b[0m";
    std::string line = this->getLine();
    line = std::regex_replace(line, retab, " ");
    line = line.substr(0, n) + format + line.substr(n, len+1) + normalFormat + (line.size() > 0 ? line.substr(n+len+1) : "");
    return line;
}
std::string StackTrace::getMessageMark(std::string const& format) const {
    std::string line = this->getLine();
    int n = this->getColNumber();
    int len = std::max(0, std::min((int)this->getLength(), (int)line.size() - n));
    std::string padBefore(n, ' ');
    std::string mark(len, '~');
    std::string normalFormat = "\u001b[0m";
    return padBefore + format + '^' + mark + normalFormat;
}
// std::string ErrorHandler::format(int format, std::string_view content) {
//     // TODO
//     // settings.html
//     // terminalSupportsColors();
// }
std::string StackTrace::getTraceString(int msgType, std::string_view const text) const {
    std::stringstream ss;
    std::string color;
    switch (msgType) {
        case Message::TYPE_FATAL_ERROR:   color = "\u001b[31m"; break;
        case Message::TYPE_ERROR:   color = "\u001b[31m"; break;
        case Message::TYPE_WARNING: color = "\u001b[33m"; break;
        case Message::TYPE_NOTICE:  color = "\u001b[36m"; break;
        default:                    color = "\u001b[32m"; break;
    }
    std::string slino = std::to_string(this->getLineNumber());
    // std::string smaxlino = std::to_string(getLine()->size());
    // int pad = smaxlino.size() - slino.size();
    std::string lino = "  " /*+ std::string(pad, ' ')*/ + slino + " | ";
    std::string linosp = std::string(lino.size() - 3, ' ') + " | ";
    ss << "\u001b[1m" << _filename;
    ss << ":" << this->getLineNumber();
    ss << ":" << this->getColNumber();
    ss << ":\u001b[0m " << (text.size() > 0 ? text : _text) << std::endl;
    ss << lino   << this->getMessageLine("\u001b[1m" + color) << std::endl;
    ss << linosp << this->getMessageMark("\u001b[1m" + color) << std::endl;
    if (_parent != nullptr)
        ss << _parent->getTraceString(Message::TYPE_NOTICE);
    return ss.str();
}
// std::string StackTrace::getCallTraceString(int msgType) const {
//     std::stringstream ss;
//     std::string slino = std::to_string(this->getLineNumber());
//     std::string smaxlino = std::to_string(_sourceLines->size());
//     int pad = smaxlino.size() - slino.size();
//     std::string lino = "  " + std::string(pad, ' ') + slino + " | ";
//     std::string linosp = std::string(lino.size() - 3, ' ') + " | ";
//     ss << this->_text << std::endl;
//     ss << "From \u001b[1m" << this->getFilename();
//     ss << "\u001b[0m, line \u001b[1m" << this->getLineNumber();
//     ss << "\u001b[0m, col \u001b[1m" << this->getColNumber();
//     ss << "\u001b[0m:" << std::endl;
//     ss << lino   << this->getLine("\u001b[1m\u001b[36m") << std::endl;
//     ss << linosp << this->getMark("\u001b[1m\u001b[36m") << std::endl;
//     if (_parent != nullptr)
//         ss << _parent->getCallTraceString();
//     return ss.str();
// }
int StackTrace::getLineNumber() const {return _tokInit->getLine();}
int StackTrace::getColNumber() const {return _tokInit->getCharPositionInLine();}
int StackTrace::getLength() const {return _tokEnd->getStopIndex() - _tokInit->getStartIndex();}
int StackTrace::getEndCol() const {return this->getColNumber() + this->getLength();
    // std::cerr << (*_sourceLines)[this->getLineNumber()] << std::endl;
    // std::cerr << _tokInit->getCharPositionInLine() << ", " << (*_sourceLines)[this->getLineNumber()].size() << std::endl;
    // return std::min(
    //         _tokInit->getCharPositionInLine(), 
    //         (*_sourceLines)[this->getLineNumber()].size()
    //     );
}
int StackTrace::getPos() const {return _tokInit->getStartIndex();}
// std::string StackTrace::getTokenText() const {return _tokInit->getText();}
StackTrace const* StackTrace::getParent() const {return _parent;}
// StackTrace* StackTrace::getParent() {return _parent;}
std::string const& StackTrace::getFilename() const {return _filename;}

}
