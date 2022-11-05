
#include "interpreter2D.h"


// #define _USE_MATH_DEFINES
#include <cmath>
#include <regex>
// #include <format>

double const PI = 3.14159265358979323846264338327950288;

using namespace lsysgen;


Point2D::Point2D(float x, float y): x(x), y(y) {}
Point2D::Point2D(): x(0), y(0) {}

std::string Point2D::toString() const {
    char buf[200];
    snprintf(buf, 200, "%.2f %.2f ", x, y);
    return buf;
    // return std::format("{0:.2} {1:.2} ", x, y);
}

Color::Color(float r, float g, float b, float a): 
        r(std::max(0.0f, std::min(r, 1.0f))), 
        g(std::max(0.0f, std::min(g, 1.0f))), 
        b(std::max(0.0f, std::min(b, 1.0f))), 
        a(std::max(0.0f, std::min(a, 1.0f))) {}
Color::Color(std::string const& color): Color() {this->parse(color);}
Color::Color(): r(0.0), g(0.0), b(0.0), a(1.0) {}

std::regex const colorHexRegex ("^ *#([0-9a-fA-F]+) *$");
std::regex const colorRgbRegex ("^ *(rgba?) *\\( *([0-9]+) *, *([0-9]+) *, *([0-9]+) *(?:, *([0-9]+(?:\\.[0-9]+)?|\\.[0-9]+) *)?\\) *$");

void Color::parse(std::string const& s) {
    // std::cout << s << std::endl;
    std::smatch m;
    if (std::regex_match(s, m, colorHexRegex)) {
        if (m[1].str().size() == 3 || m[1].str().size() == 4 || 
                m[1].str().size() == 6 || m[1].str().size() == 8) {
            // std::cout << m[1] << std::endl;
            size_t n = m[1].str().size() == 3 || m[1].str().size() == 4 ? 1 : 2;
            float max = n == 1 ? 15.0 : 255.0;
            r = std::stoi(m[1].str().substr(0*n, n), 0, 16) / max;
            g = std::stoi(m[1].str().substr(1*n, n), 0, 16) / max;
            b = std::stoi(m[1].str().substr(2*n, n), 0, 16) / max;
            if (m[1].str().size() == 4*n)
                a = std::stoi(m[1].str().substr(3*n, n), 0, 16) / max;
        }
    } else if (std::regex_match(s, m, colorRgbRegex)) {
        // std::cout << m.length(5) << std::endl;
        if ((m[1] == "rgb" && m.length(5) == 0) || (m[1] == "rgba" && m.length(5) > 0)) {
            r = std::max(0, std::min(std::stoi(m[2]), 255)) / 255.0;
            g = std::max(0, std::min(std::stoi(m[3]), 255)) / 255.0;
            b = std::max(0, std::min(std::stoi(m[4]), 255)) / 255.0;
            if (m[1] == "rgba")
                a = std::max(0.0, std::min(std::stod(m[5]), 1.0));
        }
    }
    // std::cout << toString() << std::endl;
}

Color Color::rgb() const {return Color(r, g, b);}

std::string Color::toString() const {
    char buf[50];
    if (a == 1.0)
        snprintf(buf, 50, "#%02X%02X%02X", static_cast<int>(255*r), static_cast<int>(255*g), static_cast<int>(255*b));
    else
        snprintf(buf, 50, "rgba(%d,%d,%d,%f)", static_cast<int>(255*r), static_cast<int>(255*g), static_cast<int>(255*b), a);
    return buf;
    // return std::format("#{0:02X}{1:02X}{2:02X}", static_cast<int>(255*r), static_cast<int>(255*g), static_cast<int>(255*b));
}

std::string Color::alpha() const {
    char buf[10];
    snprintf(buf, 10, "%.6f", a);
    return buf;
}

State2D::State2D(): pos(), dir(0.0), penColor(), fillColor(), lineWidth(NAN) {}

Bounds2D::Bounds2D(): p0(), p1() {}

// Shape2D::Shape2D(): points(), mode(Shape2D::MODE_STROKE) {};
// Shape2D::Shape2D(int mode): points(), mode(mode) {};


std::string node2svg(
        ParseTreeNode<InstanceNodeContent, char>* parent, 
        LSystem<char>* lsystem) {
    State2D initialState;
    Bounds2D bounds;
    // TODO: isNaN(rotation y linewidth) ???
    Settings2D settings2D = lsystem ? lsystem->settings2D() : Settings2D::DEFAULT;
    initialState.dir = settings2D.heading.get();
    initialState.lineWidth = settings2D.lineWidth.get();
    initialState.penColor = Color(settings2D.lineColor.get());
    initialState.fillColor = Color(settings2D.fillColor.get());
    std::string svgContent = node2svg(parent, initialState, bounds, lsystem);
    float marginProportion = 0.05;
    float boundsWidth = bounds.p1.x - bounds.p0.x,
        boundsHeight = bounds.p1.y - bounds.p0.y;
    // if (boundsWidth == 0.0)
    //     boundsWidth = 1.0;
    // if (boundsHeight == 0.0)
    //     boundsHeight = 1.0;
    float ratio = (boundsWidth + 2) / (boundsHeight + 2);
    float desiredWidth, desiredHeight;
    if (settings2D.height.isset()) {
        desiredHeight = settings2D.height.get();
        if (settings2D.width.isset())
            desiredWidth = settings2D.width.get();
        else
            desiredWidth = desiredHeight * ratio;
    } else {
        desiredWidth = settings2D.width.get();
        desiredHeight = desiredWidth / ratio;
    }
    float margin = std::max(boundsWidth, boundsHeight) * marginProportion + 1;
    std::string svg = "<svg viewBox=\"0 0 " + std::to_string(desiredWidth) + " " + std::to_string(desiredHeight);
    svg += "\" xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\">\n";
    if (lsystem != nullptr)
        svg += "<!-- SEED " + std::to_string(lsystem->seed()) + " -->\n";
    if (settings2D.background.isset()) {
        Color bg = Color(settings2D.background.get());
        svg += "<rect";
        // svg += " width=\"100%\" height=\"100%\"";
        svg += " width=\"" + std::to_string(desiredWidth) + "\"";
        svg += " height=\"" + std::to_string(desiredHeight) + "\"";
        svg += " fill=\"" + bg.rgb().toString() + "\"";
        svg += " fill-opacity=\"" + bg.alpha() + "\"";
        svg += "/>\n";
    }
    svg += "<g transform=\"";
    // svg += "translate(" + std::to_string(margin); // when margin was absolute
    // svg += "," + std::to_string(margin) + ") ";
    svg += "scale(" + std::to_string((desiredWidth)/(boundsWidth+2*margin));
    svg += "," + std::to_string((desiredHeight)/(boundsHeight+2*margin)) + ") ";
    svg += "translate(" + std::to_string(-bounds.p0.x + margin);
    svg += "," + std::to_string(-bounds.p0.y + margin) + ") ";
    svg += "\">\n";
    svg += svgContent;
    svg += "</g>\n";
    svg += "</svg>\n";
    return svg;
}

std::string node2svg(
        ParseTreeNode<InstanceNodeContent, char>* parent, 
        State2D& state, 
        Bounds2D &bounds, 
        LSystem<char>* lsystem) {
    std::string svgContent = "";

    auto stack = new std::list<std::pair<State2D, ParseTreeNode<InstanceNodeContent, char>*>>();
    // glBegin(GL_POINTS);
    ParseTreeNode<InstanceNodeContent, char>* node;
    std::vector<Value>* values;
    Value v[4];
    double move;
    bool endPath = false, inPath = false;
    // std::string command = "";
    // bool fill = false;
    // std::list<Point2D>* fillList = new std::list<Point2D>();
    bool draw = false, fill = false, drawn = false;
    float globalLineWidth = lsystem ? lsystem->settings2D().lineWidth.get() : Settings2D::DEFAULT_LINE_WIDTH;
    // float lineWidth = globalLineWidth;
    std::string element = "";
    char curve = 0;
    std::list<Point2D> curvePoints;
    for (node = parent->leftmostChild();
            node != nullptr;
            node = node->right()) {
        draw = false;
        move = 0.0;
        if (node->isLeaf()) {
            values = node->content().values;
            std::string fillstr, fillopstr;
            if (fill) {
                fillstr = state.fillColor.rgb().toString();
                fillopstr = state.fillColor.alpha();
            } else {
                fillstr = "none";
                fillopstr = "1";
            }
            if (!inPath) {
                // svgContent += "<g fill=\"" + fillstr + "\">";
                element = "<path stroke=\"" + state.penColor.rgb().toString();
                element += "\" stroke-opacity=\"" + state.penColor.alpha();
                element += "\" stroke-width=\"" + std::to_string(state.lineWidth);
                element += "\" fill=\"" + fillstr;
                element += "\" fill-opacity=\"" + fillopstr;
                element += "\" d=\"M";
                element += state.pos.toString();
                inPath = true;
            }
            if (node->element() == 'F' || node->element() == 'G' ||
                    node->element() == 'f' || node->element() == 'g') {
                double sign = (node->element() == 'F' || node->element() == 'f') ? 1.0 : -1.0;
                draw = (node->element() == 'F' || node->element() == 'G') ? true : false;
                if (values == nullptr || values->size() == 0) {
                    move = sign;
                } else if(values->size() == 1) {
                    v[0] = values->front();
                    if (v[0].isInt())
                        move = static_cast<double>(sign*v[0].asInt());
                    if (v[0].isFloat())
                        move = v[0].asFloat()*sign;
                    // TODO else error
                } // TODO else error
                // command = (node->element() == 'F' || node->element() == 'G') ? "L" : "M";
            } else if (node->element() == 'h' || node->element() == 'v') {
                if (values == nullptr || values->size() == 0) {
                    move = 1;
                } else if(values->size() == 1) {
                    v[0] = values->front();
                    if (v[0].isInt())
                        move = static_cast<double>(v[0].asInt());
                    if (v[0].isFloat())
                        move = v[0].asFloat();
                    // TODO else error
                } // TODO else error
            } else if (node->element() == '+' || node->element() == '-') {
                double sign = node->element() == '+' ? 1.0 : -1.0;
                if (values == nullptr || values->size() == 0) {
                    state.dir += sign*(lsystem ? lsystem->settings2D().rotation.get() : Settings2D::DEFAULT_ROTATION);
                } else if(values->size() == 1) {
                    v[0] = values->front();
                    if (v[0].isInt())
                        state.dir += static_cast<float>(sign*v[0].asInt());
                    else if (v[0].isFloat())
                        state.dir += sign*v[0].asFloat();
                    // TODO else error
                } // TODO else error
            } else if (node->element() == 'c' || node->element() == 'n' ||
                    node->element() == 'l' || node->element() == 'P') {
                if (values != nullptr && (values->size() == 3 || values->size() == 4)) {
                    float r = 1.0, g = 1.0, b = 1.0, a = 1.0;
                    // if(values->size() == 1) {
                    //     v[0] = values->front();
                    //     r = ((v[0].asInt() & 0xFF0000)>>16) / 255.0;
                    //     g = ((v[0].asInt() & 0x00FF00)>> 8) / 255.0;
                    //     b = ((v[0].asInt() & 0x0000FF)    ) / 255.0;
                    //     a = 1.0;
                    // } else 
                    if (values->size() == 3 || values->size() == 4) {
                        v[0] = values->at(0);
                        v[1] = values->at(1);
                        v[2] = values->at(2);
                        a = 1.0;
                        if (values->size() == 4)
                            v[3] = values->at(3);
                        if (v[0].isInt() && v[1].isInt() && v[2].isInt()) {
                            r = v[0].asInt() / 255.0;
                            g = v[1].asInt() / 255.0;
                            b = v[2].asInt() / 255.0;
                            if (values->size() == 4) {
                                if (v[3].isInt())
                                    a = v[3].asInt() / 255.0;
                                else if (v[3].isFloat())
                                    a = v[3].asFloat();
                                // TODO else error
                            }
                        } else if (v[0].isFloat() && v[1].isFloat() && v[2].isFloat()) {
                            r = v[0].asFloat();
                            g = v[1].asFloat();
                            b = v[2].asFloat();
                            if (values->size() == 4) {
                                if (v[3].isFloat())
                                    a = v[3].asFloat();
                                // TODO else error
                            }
                        } else {
                            // TODO error
                        }
                    } else {
                        // TODO error
                    }
                    if (node->element() == 'c' || node->element() == 'n') {
                        state.penColor.r = r;
                        state.penColor.g = g;
                        state.penColor.b = b;
                        state.penColor.a = a;
                    }
                    if (node->element() == 'c' || node->element() == 'l' || node->element() == 'P') {
                        state.fillColor.r = r;
                        state.fillColor.g = g;
                        state.fillColor.b = b;
                        state.fillColor.a = a;
                    }
                    if (fill) {
                        // TODO error ¿cambiar el color dentro de un relleno?
                    } else {
                        endPath = true;
                    }
                    // std::cout << r << ", " << g << ", " << b << std::endl;
                    // if (draw) {
                    //     glEnd();
                    //     glBegin(GL_LINE_STRIP);
                    // }
                    // // glColor4f(state.fillColor.r, state.fillColor.g, state.fillColor.b, state.fillColor.a);
                    // glColor4f(state.penColor.r, state.penColor.g, state.penColor.b, state.penColor.a);
                    // std::cout << state.penColor.r << ", " << state.penColor.g << ", " << state.penColor.b << std::endl;
                }
            }
            if (node->element() == 'P') {
                if (values == nullptr || values->size() == 3 || values->size() == 4) {
                    if (fill) {
                        // TODO error
                    } else {
                        // Save points to fill a polygon with them later
                        // fill = new Shape2D(Shape2D::MODE_FILL);
                        fill = true;
                        endPath = true;
                    }
                }
            }
            // if (fill)
            //     fill->points->push_back(Point2D{state.x, state.y});
            if (node->element() == 'p') {
                if (values == nullptr) {
                    if (fill) {
                        // if (draw) {
                        //     glEnd();
                        // }
                        // glBegin(GL_POLYGON);
                        // glColor4f(state.fillColor.r, state.fillColor.g, state.fillColor.b, state.fillColor.a);
                        // // Fill a polygon with the saved points
                        // for (Point2D p : *fill)
                        //     glVertex2f(p.x, p.y);
                        // // fill->clear();
                        // glEnd();
                        // if (draw) {
                        //     glBegin(GL_LINE_STRIP);
                        //     glColor4f(state.penColor.r, state.penColor.g, state.penColor.b, state.penColor.a);
                        // }
                        // fill = nullptr;
                        fill = false;
                        endPath = true;
                    } else {
                        // TODO error
                    }
                }
            } else if (node->element() == 'w') {
                if (values != nullptr) {
                    if(values->size() == 0) {
                        state.lineWidth = globalLineWidth;
                        endPath = true;
                    } else if(values->size() == 1) {
                        if (values->at(0).isInt())
                            state.lineWidth = static_cast<float>(values->at(0).asInt());
                        else if (values->at(0).isFloat())
                            state.lineWidth = values->at(0).asFloat();
                        // TODO else error
                        if (fill) {
                            // TODO error ¿cambiar el ancho dentro de un relleno?
                        } else {
                            endPath = true;
                        }
                    } // TODO else error
                }
            } else if (node->element() == 'z' || node->element() == 's' ||
                    node->element() == 'q' || node->element() == 't') {
                if (values != nullptr) {
                    if (curve == 0) {
                        if (node->element() == 'z')
                            curve = 'C';
                        else if (node->element() == 's')
                            curve = 'S';
                        else if (node->element() == 'q')
                            curve = 'Q';
                        else if (node->element() == 't')
                            curve = 'T';
                        // if (!drawn)
                        //     curvePoints.push_back(state.pos);
                    } // TODO else error
                }
            } else if (node->element() == 'c') {
                if (values == nullptr || values->size() == 0 || values->size() == 1) {
                    float r = 0;
                    if(values == nullptr || values->size() == 0) {
                        r = 1.0;
                    } else if(values->size() == 1) {
                        if (values->at(0).isInt())
                            r = static_cast<float>(values->at(0).asInt());
                        else if (values->at(0).isFloat())
                            r = values->at(0).asFloat();
                        // TODO else error
                    } // TODO else error
                    svgContent += "<circle cx=\"" + std::to_string(state.pos.x);
                    svgContent += "\" cy=\"" + std::to_string(state.pos.y);
                    svgContent += "\" r=\"" + std::to_string(r);
                    svgContent += "\" stroke=\"" + state.penColor.toString();
                    svgContent += "\" stroke-width=\"" + std::to_string(state.lineWidth);
                    svgContent += "\" fill=\"" + fillstr + "\"/>\n";
                }
            }
            if (node->element() == 'Z') {
                if (values == nullptr) {
                    element += 'Z';
                    // if (!fill)
                    endPath = true;
                }
            }
            // if (!lastDraw && draw) {
            //     // glEnd();
            //     glBegin(GL_LINE_STRIP);
            //     glColor4f(state.penColor.r, state.penColor.g, state.penColor.b, state.penColor.a);
            //     glVertex2f(state.x, state.y);
            // } else if (lastDraw && !draw) {
            //     glEnd();
            //     // glBegin(GL_POINTS);
            // }
            if (move != 0) {
                if (node->element() == 'h') {
                    state.pos.x += move;
                } else if (node->element() == 'v') {
                    state.pos.y -= move;
                } else {
                    state.pos.x += move*std::cos(state.dir*PI/180);
                    state.pos.y += move*std::sin(-state.dir*PI/180);
                    if (state.pos.x < bounds.p0.x)
                        bounds.p0.x = state.pos.x;
                    if (state.pos.y < bounds.p0.y)
                        bounds.p0.y = state.pos.y;
                    if (state.pos.x > bounds.p1.x)
                        bounds.p1.x = state.pos.x;
                    if (state.pos.y > bounds.p1.y)
                        bounds.p1.y = state.pos.y;
                }
            }
            if (move != 0) {
                // glVertex2f(state.x, state.y);
                if (curve && draw) {
                    curvePoints.push_back(state.pos);
                    if ((curvePoints.size() == 1 && curve == 'T') || 
                            (curvePoints.size() == 2 && (curve == 'S' || curve == 'Q')) ||
                            (curvePoints.size() == 3 && curve == 'C')) {
                        element += curve;
                        element += curvePoints.front().toString();
                        curvePoints.pop_front();
                        for (Point2D p : curvePoints)
                            element += "," + p.toString();
                        curvePoints.clear();
                        curve = 0;
                        drawn = true;
                    }
                } else if (!curve) {
                    if (draw)
                        element += "L";
                    else
                        element += "M";
                    element += state.pos.toString();
                    if (draw || fill)
                        drawn = true;
                }
            }
            if (endPath) {
                if (inPath) {
                    element += "\" />\n";
                    // fill = false;
                    inPath = false;
                }
                if (drawn)
                    svgContent += element;
                element = "";
                curve = 0;
                curvePoints.clear();
                endPath = false;
                drawn = false;
            }
        } else {
            stack->push_back(std::make_pair(state, node));
        }
    }
    if (inPath && drawn) {
        element += "\"/>\n";
        svgContent += element;
    }
    // if (fill)
    //     glEnd(); //TODO error
    // if (draw)
    //     glEnd();
    for ( auto stackedElement : *stack) {
        svgContent += node2svg(stackedElement.second, stackedElement.first, bounds, lsystem);
    }
    delete stack;

    return svgContent;
}

