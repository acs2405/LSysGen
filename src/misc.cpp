
#include "misc.h"

#include <regex>
// #include <utility>
// #include <sstream>
#include <chrono>
#include <list>
#include <fstream>


namespace lsysgen {

Random::Random(): _seed(1), gen(_seed) {}

Random::~Random() {}

void Random::seed(std::uint_fast32_t seed) {
    this->_seed = seed;
    this->gen.seed(seed);
}

std::uint_fast32_t Random::seed() const {return this->_seed;}

std::uint_fast32_t Random::randomSeed() {
    std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();
    auto duration = now.time_since_epoch();
    auto millis = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
    std::mt19937 gen(millis);
    return gen() * millis % gen();
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

std::string getModuleName(std::string const& filename, std::string const& ext) {
    std::smatch sm;
    // std::regex_match(filename, sm, std::regex("^(?:[^/\\\\]*[/\\\\])*([^/\\\\]*)\\.lsd$"));
    // std::regex_search(filename, sm, std::regex("([^/\\\\:*?|]+)\\." + ext + "$"));
    std::string const re_id = "[a-zA-Z][a-zA-Z0-9_]*";
    if (ext.size() > 0)
        std::regex_search(filename, sm, std::regex("(?:^|[/\\\\:])(" + re_id + ")\\." + ext + "$"));
    else
        std::regex_search(filename, sm, std::regex("(?:^|[/\\\\:])(" + re_id + ")(?:\\.[a-zA-Z0-9]+)?$"));
    if (sm.size() > 0)
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

bool readFromFile(std::string const& fileName, std::string & content) {
    return readFromFile(fileName.c_str(), content);
}
bool readFromStream(std::istream & stream, std::string & content) {
    if (stream.fail()) {
        return false;
        // std::cerr << "File '" << fileName << "' does not exist." << std::endl;
        // exit(1);
    }
    content.assign((std::istreambuf_iterator<char>(stream)),
                     std::istreambuf_iterator<char>());
    return true;
}

bool readFromFile(char const* fileName, std::string & content) {
    if (strcmp(fileName, "-") == 0) {
        return readFromStream(std::cin, content);
    } else {
        std::ifstream file (fileName, std::ios::in);
        bool ret = readFromStream(file, content);
        file.close();
        return ret;
    }
}

bool writeToFile(std::string const& fileName, std::string_view content) {
    return writeToFile(fileName.c_str(), content);
}
bool writeToStream(std::ostream & stream, std::string_view content) {
    if (stream.fail()) {
        return false;
    }
    stream << content << std::endl; // << std::endl / std::flush;
    return true;
}

bool writeToFile(char const* fileName, std::string_view content) {
    if (strcmp(fileName, "-") == 0) {
        return writeToStream(std::cout, content);
    } else {
        std::ofstream file (fileName, std::ios::out);
        bool ret = writeToStream(file, content);
        file.close();
        return ret;
    }
}
    
}
