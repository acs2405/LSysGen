
#include "Settings.h"

// #include "misc.h"

// #include <iostream>
// #include <map>

namespace lsysgen {

// std::map<std::string, Settings::backend_t> Settings::_formats;

Settings::InputMode   const Settings::DEFAULT_INPUT_MODE    = Settings::InputMode::LSD;

int                   const Settings::DEFAULT_ITERATIONS    = 0;
std::string           const Settings::DEFAULT_IGNORE        = "";
int                   const Settings::DEFAULT_SEED          = -1;
std::string           const Settings::DEFAULT_OUTPUT_FORMAT = "raw";

std::list<std::pair<std::string, std::string>> 
                      const Settings::DEFAULT_OUTPUTS       {};

float                 const Settings2D::DEFAULT_HEADING     = 0.0f;
float                 const Settings2D::DEFAULT_ROTATION    = 12.0f;
float                 const Settings2D::DEFAULT_LINE_WIDTH  = 0.1f;
std::string           const Settings2D::DEFAULT_LINE_COLOR  = "#000";
std::string           const Settings2D::DEFAULT_FILL_COLOR  = "#000";
std::string           const Settings2D::DEFAULT_BACKGROUND  = "#fff";
float                 const Settings2D::DEFAULT_WIDTH       = 500.0f;
float                 const Settings2D::DEFAULT_HEIGHT      = Settings2D::DEFAULT_WIDTH;

Settings              const Settings::DEFAULT;
Settings2D            const Settings2D::DEFAULT;

// void Settings::addFormat(std::string const& name, Settings::backend_t func) {return Settings::_formats[name] = func;}
// Settings::backend_t Settings::getFormat(std::string const& name) const {return Settings::_formats[name];}

// Settings::addFormat("str", node2text);
// Settings::addFormat("svg", node2svg);

Settings2D::Settings2D(): 
        heading(Settings2D::DEFAULT_HEADING), 
        rotation(Settings2D::DEFAULT_ROTATION), 
        lineWidth(Settings2D::DEFAULT_LINE_WIDTH), 
        lineColor(Settings2D::DEFAULT_LINE_COLOR), 
        fillColor(Settings2D::DEFAULT_FILL_COLOR), 
        background(Settings2D::DEFAULT_BACKGROUND), 
        width(Settings2D::DEFAULT_WIDTH), 
        height(Settings2D::DEFAULT_HEIGHT) {}

Settings2D::~Settings2D() {}

// Settings2D::unset() {}

Settings::Settings(): 
        // renderMode(Settings::RenderMode::NONE), 
        outputs(Settings::DEFAULT_OUTPUTS),
        inputMode(Settings::InputMode::LSD), 
        iterations(Settings::DEFAULT_ITERATIONS), 
        ignore(Settings::DEFAULT_IGNORE), 
        seed(Settings::DEFAULT_SEED), 
        settings2D() {}

Settings::~Settings() {}


template<typename T>
Setting<T>::Setting(): _defined(false) {}

template<typename T>
Setting<T>::Setting(T v): _defined(false), _value(v) {}

template<typename T>
Setting<T>::~Setting() {}

template<typename T>
T const& Setting<T>::operator=(T const& v2) {
    this->_value = v2;
    this->_defined = true;
    return v2;
}

template<typename T>
void Setting<T>::set() {this->_defined = true;}

template<typename T>
void Setting<T>::set(T const& v2) {
    this->_value = v2;
    this->_defined = true;
}

template<typename T>
bool Setting<T>::isset() const {return this->_defined;}

template<typename T>
T Setting<T>::get() const {return this->_value;}

template<typename T>
T & Setting<T>::getRef() {
    this->_defined = true;
    return this->_value;
}

template<typename T>
T const& Setting<T>::getRef() const {
    return this->_value;
}

// template<typename T>
// T & operator=(T & v1, Setting<T> & v2) {
//     return v1 = v2.value();
// }



template class Setting<int>;
template class Setting<float>;
template class Setting<std::string>;
template class Setting<Settings::InputMode>;
template class Setting<std::list<std::string>>;
template class Setting<std::map<std::string, std::string>>;
template class Setting<std::list<std::pair<std::string, std::string>>>;

}
