
#pragma once


// namespace lsysgen {

// class Settings;

// template<typename T>
// class Setting;

// }

#include "common.h"


namespace lsysgen {

template<typename T>
class Setting {
    bool _defined;
    T _value;

public:
    Setting();
    Setting(T v);

    ~Setting();

    // Setting<T> operator=(T v2);
    T const& operator=(T const& v2);

    void set(T const& v2);
    void set();

    bool isset() const;
    T get() const;
    T & getRef();
    T const& getRef() const;
};

// template<typename T>
// T & operator=(T & v1, Setting<T> & v2);

class Settings2D {
public:

    static float          const DEFAULT_HEADING;
    static float          const DEFAULT_ROTATION;
    static float          const DEFAULT_LINE_WIDTH;
    static std::string     const DEFAULT_BACKGROUND;
    static std::string     const DEFAULT_LINE_COLOR;
    static std::string     const DEFAULT_FILL_COLOR;
    static float          const DEFAULT_WIDTH;
    static float          const DEFAULT_HEIGHT;

    static Settings2D      const DEFAULT;

    Setting<float> heading;
    Setting<float> rotation;
    Setting<float> lineWidth;
    Setting<std::string> lineColor;
    Setting<std::string> fillColor;
    Setting<std::string> background;
    Setting<float> width;
    Setting<float> height;

    Settings2D();

    ~Settings2D();

};

class Settings {
public:
    // typedef std::string (*)(TreeNode<lsysgen::InstanceNodeContent, char>* parent, LSystem<char>* lsystem) backend_t;

    typedef enum {
        LSD,
        AXIOM
    } InputMode;

private:
    // static std::map<std::string, backend_t> _formats;

public:
    static Settings::InputMode   const DEFAULT_INPUT_MODE;

    static int                   const DEFAULT_ITERATIONS;
    static std::string           const DEFAULT_IGNORE;
    static int                   const DEFAULT_SEED;
    static std::string           const DEFAULT_OUTPUT_FORMAT;

    static std::map<std::string, std::string> 
                                 const DEFAULT_OUTPUTS;

    static Settings              const DEFAULT;

    // static std::map<std::string, backend_t> formats();
    // static std::map<std::string, backend_t> const formats() const;

    // void addFormat(std::string const& name, backend_t func);
    // backend_t getFormat(std::string const& name) const;

public:
    Setting<std::list<std::string>> inputFiles;
    // Setting<std::string> outputResultFile;
    // Setting<std::string> outputRenderFile;
    Setting<std::list<std::string>> lsystems;
    Setting<std::string> axiom;
    Setting<std::map<std::string, std::string>> outputs;
    // Setting<Settings::RenderMode> renderMode;
    Setting<Settings::InputMode> inputMode;
    Setting<std::string> rules;
    Setting<std::map<std::string, std::string>> args;

    Setting<int> iterations;
    Setting<std::string> ignore;
    Setting<int> seed;

    Settings2D settings2D;

    // TODO: poner aquí las constantes especiales del lenguaje (iterations, seed,...)
    // ... o bien las de una parte del programa en una clase hija, u otra clase (constantes 
    // ... SVG) -> SVGSettings

    Settings();

    ~Settings();
};

}
