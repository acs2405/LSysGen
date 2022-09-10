
#include "misc.h"

#include <regex>
// #include <utility>
// #include <sstream>
#include <chrono>
#include <list>
#include <fstream>


namespace lsysgen {

Random::Random(): gen() {}

Random::~Random() {}

void Random::seed(std::uint_fast32_t seed) {
    this->gen.seed(seed);
}

std::uint_fast32_t Random::randomSeed() {
    std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();
    auto duration = now.time_since_epoch();
    auto millis = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
    return static_cast<std::uint_fast32_t>(millis);
}

std::uint_fast32_t Random::rand() {
    return this->gen();
}

double Random::randFloat() {
    return static_cast<double>(this->rand()) / this->gen.max();
}

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

bool terminalSupportsColors() {
    const std::string env_term = std::getenv("TERM");
    if(env_term.size() > 0) {
        const std::list<std::string> terms {"xterm",  "xterm-256", "xterm-256color",
                                         "vt100",  "color",     "ansi",
                                         "cygwin", "linux"};
        return std::find(terms.begin(), terms.end(), env_term) != terms.end();
    }
    return false;
}

void readFromFile(char const* fileName, std::string & content) {
    std::ifstream file(fileName, std::ios::in);
    if (file.fail()) {
        std::cerr << "File '" << fileName << "' does not exist." << std::endl;
        exit(1);
    }
    content.assign((std::istreambuf_iterator<char>(file)),
                     std::istreambuf_iterator<char>());
    file.close();
}

void writeToFile(char const* fileName, std::string_view content) {
    std::ofstream file(fileName, std::ios::out);
    if (file.fail()) {
        std::cerr << "File '" << fileName << "' is not writable." << std::endl;
        exit(1);
    }
    file << content << std::endl;
    file.close();
}
    
}
