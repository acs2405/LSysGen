
#include "misc.h"

#include <regex>
// #include <utility>
// #include <sstream>


namespace lsysgen {

// template<typename Base, typename T>
// bool instanceof(T const*) {
//    return is_base_of<Base, T>::value;
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
