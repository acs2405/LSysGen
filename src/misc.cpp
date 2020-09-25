
#include "misc.h"

#include <regex>
// #include <utility>
// #include <sstream>


namespace lsysgen {

// template<typename Base, typename T>
// bool instanceof(T const*) {
//    return is_base_of<Base, T>::value;
// }

// LSysDExpressionEvaluator * evaluator = new LSysDExpressionEvaluator();
// Value eval(LSysDParser::ExpressionContext * expr, Scope * scope) {
//     return evaluator->eval(expr, scope);
// }

// std::string anyToString(antlrcpp::Any& v) {
//     if (v.is<int>()) {
//         return std::to_string(v.as<int>());
//     } else if (v.is<double>()) {
//         return std::to_string(v.as<double>());
//     } else if (v.is<bool>()) {
//         return v.as<bool>() ? "true" : "false";
//     } else if (v.is<std::string>()) {
//         return '"' + strEscape(v.as<std::string>()) + '"';
//     } else if (v.is<Function *>()) {
//         return v.as<Function *>()->toString();
//     } else {
//         return "<error>";
//     }
// }

// bool checkCondition (LSysDParser::ExpressionContext * cond, Scope * paramMapping) {
//     Value v = eval(cond, paramMapping);
//     if (v.isBool()) {
//         return v.asBool();
//     } else if (!v.isError()) {
//         err("The condition expression (of type " + v.type().name() + ") must be a boolean");
//     }
//     return false;
// }

std::string strEscape(std::string const& s) {
    std::string str = s;
    str = std::regex_replace(str, std::regex("\\\\"), "\\\\");
    str = std::regex_replace(str, std::regex("\""), "\\\"");
    str = std::regex_replace(str, std::regex("\r"), "\\r");
    str = std::regex_replace(str, std::regex("\n"), "\\n");
    str = std::regex_replace(str, std::regex("\t"), "\\t");
    return str;
}

std::string strUnescape(std::string const& s) {
    std::string str = s;
    str = std::regex_replace(str, std::regex("\\\\\\\\"), "\\");
    str = std::regex_replace(str, std::regex("\\\\\""), "\"");
    str = std::regex_replace(str, std::regex("\\\\r"), "\r");
    str = std::regex_replace(str, std::regex("\\\\n"), "\n");
    str = std::regex_replace(str, std::regex("\\\\t"), "\t");
    return str;
}

std::string sanitizeXML(std::string const& s) {
    std::string str = s;
    str = std::regex_replace(str, std::regex("&"), "&amp;");
    str = std::regex_replace(str, std::regex("<"), "&lt;");
    str = std::regex_replace(str, std::regex(">"), "&gt;");
    str = std::regex_replace(str, std::regex("\""), "&quot;");
    str = std::regex_replace(str, std::regex("'"), "&apos;");
    return str;
}

std::string getModuleName(std::string const& filename) {
    std::smatch sm;
    // std::regex_match(filename, sm, std::regex("^(?:[^/\\\\]*[/\\\\])*([^/\\\\]*)\\.lsd$"));
    std::regex_search(filename, sm, std::regex("([^/\\\\:*?|]+)\\.lsd$"));
    if (sm.size() == 2)
        return sm[1];
    else
        return "";
}
    
}
