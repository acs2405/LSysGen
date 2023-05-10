
#include "ErrorHandler.h"


#include "misc.h"

#include <sstream>
#include <regex>


namespace lsysgen {

bool const ErrorHandler::terminalSupportsColors = lsysgen::terminalSupportsColors();

ErrorHandler::ErrorHandler(std::string_view const filename, StackTrace const* st): 
        _messages(), _errors(), _warnings(), _notices(), 
        _failed(false), _stdin(filename == "-"), _parentTrace(st) {
    if (filename.size() == 0)
        _filename = "<inline>";
    else if (filename == "-")
        _filename = "<stdin>";
    else
        _filename = filename;
    // if (ErrorHandler::terminalSupportsColors)
    //     this->_format = ErrorHandler::Format::COLOR_TERMINAL;
    // else
    //     this->_format = ErrorHandler::Format::NONE;
}

ErrorHandler::ErrorHandler(ErrorHandler const& eh): 
        ErrorHandler(eh._filename, eh._parentTrace) {}

ErrorHandler::~ErrorHandler() {
    _messages.clear();
}

void ErrorHandler::fatalError(std::string_view const msg, StackTrace const* st) {
    Message const* e = this->createMessage(msg, Message::Type::FATAL_ERROR, st);
    _errors.push_back(e);
    _failed = true;
    this->addMessage(e);
    // this->dump();
    // std::cerr << "LSystem halted due to a runtime error." << std::endl;
    // exit(1);
}

void ErrorHandler::error(std::string_view const msg, StackTrace const* st) {
    Message const* err = this->createMessage(msg, Message::Type::ERROR, st);
    _errors.push_back(err);
    _failed = true;
    this->addMessage(err);
}

void ErrorHandler::warning(std::string_view const msg, StackTrace const* st) {
    Message const* warn = this->createMessage(msg, Message::Type::WARNING, st);
    _warnings.push_back(warn);
    this->addMessage(warn);
}

void ErrorHandler::notice(std::string_view const msg, StackTrace const* st) {
    Message const* notice = this->createMessage(msg, Message::Type::NOTICE, st);
    _notices.push_back(notice);
    this->addMessage(notice);
}

Message * ErrorHandler::createMessage(std::string_view const msg, Message::Type msgType, StackTrace const* st) const {
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
// ErrorHandler::Format ErrorHandler::format() const {return _format;}

std::list<Message const*> const& ErrorHandler::messages() const {return _messages;}
std::list<Message const*> const& ErrorHandler::errors() const {return _errors;}
std::list<Message const*> const& ErrorHandler::warnings() const {return _warnings;}
std::list<Message const*> const& ErrorHandler::notices() const {return _notices;}

std::string const& ErrorHandler::fileName() const {return _filename;}



Message::Message(Message::Type type, std::string_view const msg, StackTrace const* trace): 
        _type(type), _msg(msg), _trace(trace) {}
Message::~Message() {
    delete this->_trace;
}

bool Message::isFatalError() const {return _type == Message::Type::FATAL_ERROR;}
bool Message::isError() const {return _type == Message::Type::ERROR;}
bool Message::isWarning() const {return _type == Message::Type::WARNING;}
bool Message::isNotice() const {return _type == Message::Type::NOTICE;}
Message::Type Message::type() const {return _type;}

std::string Message::buildMessage() const {
    std::string msgTypeStr;
    switch(_type) {
        case Message::Type::FATAL_ERROR:
            msgTypeStr = Message::bold(Message::colored(_type, "FATAL ERROR: ")) + _msg;
            break;
        case Message::Type::ERROR:
            msgTypeStr = Message::bold(Message::colored(_type, "ERROR: ")) + _msg;
            break;
        case Message::Type::WARNING:
            msgTypeStr = Message::bold(Message::colored(_type, "WARNING: ")) + _msg;
            break;
        case Message::Type::NOTICE:
            msgTypeStr = Message::bold(Message::colored(_type, "NOTICE: ")) + _msg;
            break;
        default:
            msgTypeStr = _msg;
    }
    if (_trace)
        return _trace->getTraceString(_type, msgTypeStr);
    else {
        std::stringstream ss;
        ss << msgTypeStr << std::endl;
        return ss.str();
    }
}

std::string Message::colored(Message::Type type, std::string const& content) {
    if (ErrorHandler::terminalSupportsColors) {
        switch(type) {
            case Message::Type::FATAL_ERROR:
            case Message::Type::ERROR:
                return "\u001b[31m" + content + "\u001b[0m";
            case Message::Type::WARNING:
                return "\u001b[33m" + content + "\u001b[0m";
            case Message::Type::NOTICE:
                return "\u001b[36m" + content + "\u001b[0m";
            default:
                return content;
        }
    } else {
        return content;
    }
}
std::string Message::bold(std::string const& content) {
    if (ErrorHandler::terminalSupportsColors)
        return "\u001b[1m" + content + "\u001b[0m";
    else
        return content;
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
        _tokInit(tokInit), _tokEnd(tokEnd), _parent(parent), 
        _text(text), _filename(filename) {}

StackTrace::StackTrace(StackTrace const& st): 
        _tokInit(st._tokInit), _tokEnd(st._tokEnd), _parent(st._parent), //_parent(new StackTrace(*st._parent)),
        _text(st._text), _filename(st._filename) {}

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

std::string StackTrace::getMessageLine(Message::Type msgType) const {
    // std::cout << "HERE!" << std::endl;
    size_t n = this->getColNumber();
    size_t len = this->getLength();
    std::regex retab ("\t");
    std::string line = this->getLine();
    line = std::regex_replace(line, retab, " ");
    line = line.substr(0, n) + Message::bold(Message::colored(msgType, line.substr(n, len+1))) + 
            (line.size() > 0 ? line.substr(n+len+1) : "");
    return line;
}
std::string StackTrace::getMessageMark(Message::Type msgType) const {
    std::string line = this->getLine();
    size_t n = this->getColNumber();
    int len = std::max(0, std::min((int)this->getLength(), (int)(line.size() - n)));
    std::string padBefore(n, ' ');
    std::string mark(len, '~');
    return padBefore + Message::bold(Message::colored(msgType, '^' + mark));
}
// std::string ErrorHandler::format(int format, std::string_view content) {
//     // TODO
//     // settings.html
//     // terminalSupportsColors();
// }
std::string StackTrace::getTraceString(Message::Type msgType, std::string_view const text) const {
    std::stringstream ss;
    std::string slino = std::to_string(this->getLineNumber());
    // std::string smaxlino = std::to_string(getLine()->size());
    // int pad = smaxlino.size() - slino.size();
    std::string lino = "  " /*+ std::string(pad, ' ')*/ + slino + " | ";
    std::string linosp = std::string(lino.size() - 3, ' ') + " | ";
    ss << Message::bold(_filename + 
            ":" + std::to_string(this->getLineNumber()) + 
            ":" + std::to_string(this->getColNumber()) + 
            ": ");
    ss << (text.size() > 0 ? text : _text) << std::endl;
    ss << lino   << this->getMessageLine(msgType) << std::endl;
    ss << linosp << this->getMessageMark(msgType) << std::endl;
    if (_parent != nullptr)
        ss << _parent->getTraceString(Message::Type::NOTICE);
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
size_t StackTrace::getLineNumber() const {return _tokInit->getLine();}
size_t StackTrace::getColNumber() const {return _tokInit->getCharPositionInLine();}
size_t StackTrace::getLength() const {return _tokEnd->getStopIndex() - _tokInit->getStartIndex();}
size_t StackTrace::getEndCol() const {return this->getColNumber() + this->getLength();
    // std::cerr << (*_sourceLines)[this->getLineNumber()] << std::endl;
    // std::cerr << _tokInit->getCharPositionInLine() << ", " << (*_sourceLines)[this->getLineNumber()].size() << std::endl;
    // return std::min(
    //         _tokInit->getCharPositionInLine(), 
    //         (*_sourceLines)[this->getLineNumber()].size()
    //     );
}
size_t StackTrace::getPos() const {return _tokInit->getStartIndex();}
// std::string StackTrace::getTokenText() const {return _tokInit->getText();}
StackTrace const* StackTrace::getParent() const {return _parent;}
// StackTrace* StackTrace::getParent() {return _parent;}
std::string const& StackTrace::getFilename() const {return _filename;}

}
