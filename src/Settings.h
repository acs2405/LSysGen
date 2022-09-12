
#pragma once


// namespace lsysgen {

// class Settings;

// template<typename T>
// class Setting;

// }

#include <string>
#include <map>
// #include <list>
// #include <vector>

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
};

// template<typename T>
// T & operator=(T & v1, Setting<T> & v2);

class Settings2D {
public:

    static double          const DEFAULT_HEADING;
    static double          const DEFAULT_ROTATION;
    static double          const DEFAULT_LINE_WIDTH;
    static std::string     const DEFAULT_BACKGROUND;
    static std::string     const DEFAULT_LINE_COLOR;
    static std::string     const DEFAULT_FILL_COLOR;

    static Settings2D      const DEFAULT;

    Setting<double> heading;
    Setting<double> rotation;
    Setting<double> lineWidth;
    Setting<std::string> background;
    Setting<std::string> lineColor;
    Setting<std::string> fillColor;

    Settings2D();

    ~Settings2D();

};

class Settings {
public:
    typedef enum {
        NONE,
        SVG
    } RenderMode;

    typedef enum {
        LSD,
        AXIOM
    } InputMode;

    static Settings::RenderMode  const DEFAULT_RENDER_MODE;
    static Settings::InputMode  const DEFAULT_INPUT_MODE;

    static int             const DEFAULT_ITERATIONS;
    static std::string     const DEFAULT_IGNORE;
    static int             const DEFAULT_SEED;

    static Settings        const DEFAULT;

    Setting<std::string> inputFile;
    Setting<std::string> outputResultFile;
    Setting<std::string> outputRenderFile;
    Setting<std::string> lsystem;
    Setting<std::string> axiom;
    Setting<Settings::RenderMode> renderMode;
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
