
#include "ErrorHandler.h"


namespace lsysgen {

ErrorHandler::ErrorHandler() {
    this->_errors = new std::list<Error*>();
}

ErrorHandler::~ErrorHandler() {
    for (Error* e : *this->_errors)
        delete e;
    delete this->_errors;
}

void ErrorHandler::addError(Error* e) {
    this->_errors->push_back(e);
}

const std::list<Error*>* ErrorHandler::errors() const {return this->_errors;}

// void ErrorHandler::dump() const {
//     for (Error* e : *this->_errors)
//         std::cerr << r->buildMessage();
// }



Error::Error(std::string msg, StackTrace* trace): msg(msg), trace(trace) {}
Error::~Error() {
    delete this->trace;
}
std::string Error::buildMessage() const {
    std::stringstream ss;
    ss << "ERROR: " << this->msg << std::endl;
    if (this->trace)
        ss << this->trace->getTraceString();
    return ss.str();
}



StackTrace::StackTrace(antlr4::Token* tokInit, antlr4::Token* tokEnd, StackTrace* parent, std::vector<std::string>* sourceLines, std::string filename):
        tokInit(tokInit), tokEnd(tokEnd), parent(parent), 
        sourceLines(sourceLines), filename(filename) {}

StackTrace::StackTrace(antlr4::ParserRuleContext* ctx, StackTrace* parent, std::vector<std::string>* sourceLines, std::string filename): 
        StackTrace(ctx->start, ctx->stop, parent, sourceLines, filename) {}

StackTrace::~StackTrace() {}

int StackTrace::getLineNumber() const {return this->tokInit->getLine();}
std::string StackTrace::getLine() const {
    // std::cout << "HERE!" << std::endl;
    std::regex tab ("\t");
    // std::cout << this->sourceLines->size() << std::endl;
    // std::cout << (*this->sourceLines)[this->tokInit->getLine() - 1] << std::endl;
    return std::regex_replace((*this->sourceLines)[this->tokInit->getLine() - 1], tab, " ");
}
std::string StackTrace::getMark() const {
    int n = this->getColNumber();
    int len = this->getLength();
    std::string padBefore(n, ' ');
    std::string mark(len + 1, '^');
    return padBefore + mark;
}
std::string StackTrace::getTraceString() const {
    std::stringstream ss;
    ss << "In "  << this->getFilename() << ", line " << this->getLineNumber() << ", col " << this->getColNumber() << ":" << std::endl;
    // String s = String.format("  In %s, line %d, col %d:" + eol, getFilename(), getLineNumber(), getColNumber());
    ss << this->getLine() << std::endl;
    ss << this->getMark() << std::endl;
    if (parent != nullptr)
        ss << parent->getCallTraceString();
    return ss.str();
}
std::string StackTrace::getCallTraceString() const {
    std::stringstream ss;
    ss << "From "  << this->getFilename() << ", line " << this->getLineNumber() << ", col " << this->getColNumber() << ":" << std::endl;
    // String s = String.format("  From %s, line %d, col %d:" + eol, getFilename(), getLineNumber(), getColNumber());
    ss << this->getLine() << std::endl;
    ss << this->getMark() << std::endl;
    if (parent != nullptr)
        ss << parent->getCallTraceString();
    return ss.str();
}
int StackTrace::getColNumber() const {return tokInit->getCharPositionInLine();}
int StackTrace::getLength() const {return tokEnd == nullptr ? 0 : tokEnd->getStopIndex() - tokInit->getStartIndex();}
int StackTrace::getEndCol() const {return this->getColNumber() + this->getLength();}
int StackTrace::getPos() const {return tokInit->getStartIndex();}
std::string StackTrace::getTokenText() const {return tokInit->getText();}
const StackTrace* StackTrace::getParent() const {return parent;}
// const Environment* StackTrace::getScope() {return scope;}
std::string const& StackTrace::getFilename() const {return filename;}

}
