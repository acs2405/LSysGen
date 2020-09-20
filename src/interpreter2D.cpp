
#include "interpreter2D.h"


#include <cmath>
// #include <format>


// DEFAULT_INITIAL_HEADING = 0;
// DEFAULT_ROTATION = 12;

Point2D::Point2D(float x, float y): x(x), y(y) {};
Point2D::Point2D(): x(0), y(0) {};

std::string Point2D::toString() const {
    char buf[200];
    sprintf(buf, "%.2f %.2f ", x, y);
    return buf;
    // return std::format("{0:.2} {1:.2} ", x, y);
}

Color::Color(float r, float g, float b, float a): r(r), g(g), b(b), a(a) {}
Color::Color(): r(0.0), g(0.0), b(0.0), a(1.0) {}

std::string Color::toString() const {
    char buf[25];
    sprintf(buf, "#%02X%02X%02X", static_cast<int>(255*r), static_cast<int>(255*g), static_cast<int>(255*b));
    return buf;
    // return std::format("#{0:02X}{1:02X}{2:02X}", static_cast<int>(255*r), static_cast<int>(255*g), static_cast<int>(255*b));
}

State2D::State2D(): pos(), dir(0.0), penColor(Color()), fillColor(Color()) {}

Bounds2D::Bounds2D(): p0(), p1() {}

// Shape2D::Shape2D(): points(), mode(Shape2D::MODE_STROKE) {};
// Shape2D::Shape2D(int mode): points(), mode(mode) {};


std::string node2svg(ParseTreeNode<InstanceNodeContent, char>* parent, LSystem<char>* lsystem) {
    State2D initialState;
    Bounds2D bounds;
    initialState.dir = lsystem ? lsystem->initialHeading : DEFAULT_INITIAL_HEADING;
    std::string svgContent = node2svg(parent, initialState, bounds, lsystem);
    float marginProportion = 0.05;
    float boundsWidth = bounds.p1.x - bounds.p0.x,
        boundsHeight = bounds.p1.y - bounds.p0.y;
    // if (boundsWidth == 0.0)
    //     boundsWidth = 1.0;
    // if (boundsHeight == 0.0)
    //     boundsHeight = 1.0;
    float desiredWidth = 500.0, desiredHeight = desiredWidth*(boundsHeight+2)/(boundsWidth+2);
    float margin = std::max(boundsWidth, boundsHeight) * marginProportion + 1;
    std::string svg = "<svg width=\"" + std::to_string(desiredWidth);
    svg += "\" height=\"" + std::to_string(desiredHeight);
    svg += "\" xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\">\n";
    // svg += "<rect width=\"100%\" height=\"100%\" fill=\"white\" />\n";
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

std::string node2svg(ParseTreeNode<InstanceNodeContent, char>* parent, State2D& state, Bounds2D &bounds, LSystem<char>* lsystem) {
    std::string svgContent = "";

    auto stack = new std::list<std::pair<State2D, ParseTreeNode<InstanceNodeContent, char>*>>();
    // glBegin(GL_POINTS);
    ParseTreeNode<InstanceNodeContent, char>* node;
    std::vector<Value>* values;
    Value v[3];
    double move;
    bool draw = false, endPath = false, inPath = false;
    // std::string command = "";
    // bool fill = false;
    // std::list<Point2D>* fillList = new std::list<Point2D>();
    bool fill = false;
    for (node = parent->leftmostChild();
            node != nullptr;
            node = node->right()) {
        move = 0.0;
        if (node->isLeaf()) {
            if (!inPath) {
                std::string fillstr;
                if (fill) {
                    fillstr = state.fillColor.toString();
                } else {
                    fillstr = "none";
                }
                svgContent += "<path stroke=\"" + state.penColor.toString();
                // float lineLength = lsystem && lsystem->lineLength > 0 ? lsystem->lineLength : DEFAULT_LINE_LENGTH;
                float lineWidth = lsystem && lsystem->lineWidth > 0 ? lsystem->lineWidth : DEFAULT_LINE_WIDTH;
                svgContent += "\" stroke-width=\"" + std::to_string(lineWidth);
                svgContent += "\" fill=\"" + fillstr + "\" d=\"M";
                svgContent += state.pos.toString();
                inPath = true;
            }
            if (node->element() == 'F' || node->element() == 'G' ||
                    node->element() == 'f' || node->element() == 'g') {
                double sign = (node->element() == 'F' || node->element() == 'f') ? 1.0 : -1.0;
                values = node->content()->values;
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
                draw = (node->element() == 'F' || node->element() == 'G') ? true : false;
                // command = (node->element() == 'F' || node->element() == 'G') ? "L" : "M";
            } else if (node->element() == '+' || node->element() == '-') {
                double sign = node->element() == '+' ? 1.0 : -1.0;
                values = node->content()->values;
                if (values == nullptr || values->size() == 0) {
                    state.dir += lsystem ? sign*lsystem->rotation : DEFAULT_ROTATION;
                } else if(values->size() == 1) {
                    v[0] = values->front();
                    if (v[0].isInt())
                        state.dir += static_cast<double>(sign*v[0].asInt());
                    else if (v[0].isFloat())
                        state.dir += sign*v[0].asFloat();
                    // TODO else error
                } // TODO else error
            } else if (node->element() == 'c' || node->element() == 'n' ||
                    node->element() == 'l') {
                values = node->content()->values;
                if (values != nullptr) {
                    float r = 1.0, g = 1.0, b = 1.0, a = 1.0;
                    if(values->size() == 1) {
                        v[0] = values->front();
                        r = ((v[0].asInt() & 0xFF0000)>>16) / 255.0;
                        g = ((v[0].asInt() & 0x00FF00)>> 8) / 255.0;
                        b = ((v[0].asInt() & 0x0000FF)    ) / 255.0;
                        a = 1.0;
                    } else if (values->size() == 3) {
                        v[0] = values->at(0);
                        v[1] = values->at(1);
                        v[2] = values->at(2);
                        if (v[0].isInt() && v[1].isInt() && v[2].isInt()) {
                            r = v[0].asInt() / 255.0;
                            g = v[1].asInt() / 255.0;
                            b = v[2].asInt() / 255.0;
                        } else if (v[0].isFloat() && v[1].isFloat() && v[2].isFloat()) {
                            r = v[0].asFloat();
                            g = v[1].asFloat();
                            b = v[2].asFloat();
                        } else {
                            // TODO error
                        }
                        a = 1.0;
                    } else {
                        // TODO error
                    }
                    if (node->element() == 'c' || node->element() == 'n') {
                        state.penColor.r = r;
                        state.penColor.g = g;
                        state.penColor.b = b;
                        state.penColor.a = a;
                    }
                    if (node->element() == 'c' || node->element() == 'l') {
                        state.fillColor.r = r;
                        state.fillColor.g = g;
                        state.fillColor.b = b;
                        state.fillColor.a = a;
                    }
                    if (fill) {
                        // TODO ¿cambiar el color dentro de un relleno?
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
            } else if (node->element() == 'P') {
                if (fill) {
                    // TODO error
                } else {
                    // Save points to fill a polygon with them later
                    // fill = new Shape2D(Shape2D::MODE_FILL);
                    fill = true;
                    endPath = true;
                }
            }
            // if (fill)
            //     fill->points->push_back(Point2D{state.x, state.y});
            if (node->element() == 'p') {
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
            // if (!lastDraw && draw) {
            //     // glEnd();
            //     glBegin(GL_LINE_STRIP);
            //     glColor4f(state.penColor.r, state.penColor.g, state.penColor.b, state.penColor.a);
            //     glVertex2f(state.x, state.y);
            // } else if (lastDraw && !draw) {
            //     glEnd();
            //     // glBegin(GL_POINTS);
            // }
            if (move > 0) {
                state.pos.x += move*std::cos(state.dir*M_PI/180);
                state.pos.y += move*std::sin(-state.dir*M_PI/180);
                if (state.pos.x < bounds.p0.x)
                    bounds.p0.x = state.pos.x;
                if (state.pos.y < bounds.p0.y)
                    bounds.p0.y = state.pos.y;
                if (state.pos.x > bounds.p1.x)
                    bounds.p1.x = state.pos.x;
                if (state.pos.y > bounds.p1.y)
                    bounds.p1.y = state.pos.y;
            }
            if (endPath) {
                if (inPath) {
                    svgContent += "\" />\n";
                    inPath = false;
                }
                endPath = false;
            }
            // if (!inPath) {
            //     std::string fillstr;
            //     if (fill) {
            //         fillstr = state.fillColor.toString();
            //     } else {
            //         fillstr = "none";
            //     }
            //     svgContent += "<path stroke=\"" + state.penColor.toString();
            //     svgContent += "\" fill=\"" + fillstr + "\" d=\"";
            //     inPath = true;
            // }
            if (move > 0) {
                // glVertex2f(state.x, state.y);
                if (draw)
                    svgContent += "L";
                else
                    svgContent += "M";
                svgContent += state.pos.toString();
            }
        } else {
            stack->push_back(std::make_pair(state, node));
        }
    }
    if (inPath) {
        svgContent += "\" />\n";
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
