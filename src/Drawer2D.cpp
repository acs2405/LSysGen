
#include "Drawer2D.h"

#include <math.h>
#include <vector>


namespace lsysgen {

// constexpr double pi() { return std::atan(1)*4; }

class Drawer2DDisplayer {
public:
    static Drawer2D* drawer;

    static void display() {drawer->display();}
};
Drawer2D* Drawer2DDisplayer::drawer = nullptr;

Drawer2D::Drawer2D(LSystem<char>* lsystem): lsystem(lsystem) {}

struct {float x0; float y0; float x1; float y1;} bounds {0, 0, 0, 0};

void Drawer2D::drawBranch(ParseTreeNode<InstanceNodeContent, char>* parent, State2D& state) {
    auto stack = new std::list<std::pair<State2D, ParseTreeNode<InstanceNodeContent, char>*>>();
    // glBegin(GL_POINTS);
    ParseTreeNode<InstanceNodeContent, char>* node;
    std::vector<Value>* values;
    Value v[3];
    double move;
    bool draw = false, lastDraw = false;
    bool fill = false;
    float pen_r=0.0, pen_g=0.0, pen_b=0.0, pen_a=1.0;
    float fill_r=0.0, fill_g=0.0, fill_b=0.0, fill_a=1.0;
    std::list<Point2D>* fillList = new std::list<Point2D>();
    for (node = parent->leftmostChild();
            node != nullptr;
            node = node->right()) {
        move = 0.0;
        if (node->isLeaf()) {
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
            } else if (node->element() == '+' || node->element() == '-') {
                double sign = node->element() == '+' ? 1.0 : -1.0;
                values = node->content()->values;
                if (values == nullptr || values->size() == 0) {
                    state.dir += sign*lsystem->rotation;
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
                float r = 1.0, g = 1.0, b = 1.0, a = 1.0;
                if (values != nullptr) {
                    if(values->size() == 1) {
                        v[0] = values->front();
                        r = ((v[0].asInt() & 0xFF0000)>>16) / 255.0;
                        g = ((v[0].asInt() & 0x00FF00)>> 8) / 255.0;
                        b = ((v[0].asInt() & 0x0000FF)    ) / 255.0;
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
                    } else {
                        // TODO error
                    }
                    if (node->element() == 'c' || node->element() == 'n') {
                        pen_r = r;
                        pen_g = g;
                        pen_b = b;
                        pen_a = a;
                    }
                    if (node->element() == 'c' || node->element() == 'l') {
                        fill_r = r;
                        fill_g = g;
                        fill_b = b;
                        fill_a = a;
                    }
                    // std::cout << r << ", " << g << ", " << b << std::endl;
                    if (draw) {
                        glEnd();
                        glBegin(GL_LINE_STRIP);
                    }
                    // glColor4f(fill_r, fill_g, fill_b, fill_a);
                    glColor4f(pen_r, pen_g, pen_b, pen_a);
                }
            } else if (node->element() == 'P') {
                if (fill) {
                    //ERROR
                } else {
                    // Save points to fill a polygon with them later
                    fill = true;
                }
            }
            if (fill)
                fillList->push_back(Point2D{state.x, state.y});
            if (node->element() == 'p') {
                if (fill) {
                    if (draw) {
                        glEnd();
                    }
                    glBegin(GL_POLYGON);
                    glColor4f(fill_r, fill_g, fill_b, fill_a);
                    // Fill a polygon with the saved points
                    for (Point2D p : *fillList)
                        glVertex2f(p.x, p.y);
                    fillList->clear();
                    glEnd();
                    if (draw) {
                        glBegin(GL_LINE_STRIP);
                        glColor4f(pen_r, pen_g, pen_b, pen_a);
                    }
                    fill = false;
                } else {
                    // ERROR
                }
            }
            if (lastDraw == false && draw == true) {
                // glEnd();
                glBegin(GL_LINE_STRIP);
                glColor4f(pen_r, pen_g, pen_b, pen_a);
                glVertex2f(state.x, state.y);
            } else if (lastDraw == true && draw == false) {
                glEnd();
                // glBegin(GL_POINTS);
            }
            if (move > 0) {
                state.x += move*std::cos(state.dir*M_PI/180);
                state.y += move*std::sin(state.dir*M_PI/180);
                if (state.x < bounds.x0)
                    bounds.x0 = state.x;
                if (state.y < bounds.y0)
                    bounds.y0 = state.y;
                if (state.x > bounds.x1)
                    bounds.x1 = state.x;
                if (state.y > bounds.y1)
                    bounds.y1 = state.y;
                glVertex2f(state.x, state.y);
            }
            lastDraw = draw;
        } else {
            stack->push_back(std::make_pair(state, node));
        }
    }
    if (fill)
        glEnd(); //TODO error
    if (draw)
        glEnd();
    for ( auto stackedElement : *stack) {
        this->drawBranch(stackedElement.second, stackedElement.first);
    }
    delete fillList;
    delete stack;
}

/* Handler for window re-size event. Called back when the window first appears and
   whenever the window is re-sized with its new width and height */
void reshape(GLsizei width, GLsizei height) {  // GLsizei for non-negative integer
    // Compute aspect ratio of the new window
    if (height == 0) height = 1;                // To prevent divide by 0

    // Set the viewport to cover the new window
    glViewport(0, 0, width, height);


    // Set the aspect ratio of the clipping area to match the viewport
    glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
    glLoadIdentity();

    float diffx = bounds.x1 - bounds.x0;
    float diffy = bounds.y1 - bounds.y0;
    float cx = 0*(bounds.x1 + bounds.x0)/2;
    float cy = 0*(bounds.y1 + bounds.y0)/2;
    float maxSegment = std::max(diffx, diffy);
    float margin = 0.05 * maxSegment;
    // float figureAspect = (diffx + 2*margin) / (diffy + 2*margin);
    float figureAspect = (diffx) / (diffy);

    GLfloat innerAspect = (GLfloat)(width - 2*margin) / (GLfloat)(height - 2*margin);
    GLfloat outerAspect = (GLfloat)(width) / (GLfloat)(height);
    // if (height - 2*margin < 0)
    //     std::cout << height - 2*margin << std::endl;
    // float maxAspect = std::max(innerAspect, figureAspect);
    // float minAspect = std::min(innerAspect, figureAspect);
    if (innerAspect >= figureAspect) {
    // if (width >= height) {
        // aspect >= 1, set the height from -1 to 1, with larger width
        // std::cout << height - 2*margin << std::endl;
        gluOrtho2D((bounds.x0 - (maxSegment-diffx)/2 - margin - cx)*outerAspect, (bounds.x1 + (maxSegment-diffx)/2 + margin - cx)*outerAspect, (bounds.y0 - (maxSegment-diffy)/2 - margin - cy), (bounds.y1 + (maxSegment-diffy)/2 + margin - cy));
    } else {
        // aspect < 1, set the width to -1 to 1, with larger height
        gluOrtho2D((bounds.x0 - (maxSegment-diffx)/2 - margin - cx), (bounds.x1 + (maxSegment-diffx)/2 + margin - cx), (bounds.y0 - (maxSegment-diffy)/2 - margin - cy)/outerAspect, (bounds.y1 + (maxSegment-diffy)/2 + margin - cy)/outerAspect);
    }
}

void Drawer2D::display() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)

    ParseTreeNode<InstanceNodeContent, char>* node = lsystem->encodedProgression->back();
    State2D state {0, 0, lsystem->initialHeading, 0, 0, 0};
    this->drawBranch(node, state);
    state = {0, 0, lsystem->initialHeading, 0, 0, 0};
 
    // // Draw a Red 1x1 Square centered at origin
    // glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
    //     glColor4f(1.0f, 0.0f, 0.0f, 0.1f); // Red
    //     glVertex2f(bounds.x0, bounds.y0);    // x, y
    //     glVertex2f(bounds.x1, bounds.y0);
    //     glVertex2f(bounds.x1, bounds.y1);
    //     glVertex2f(bounds.x0, bounds.y1);
    // glEnd();
    // this->drawBranch(node, state);
 
    glFlush();  // Render now

    reshape(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));

    // if (bounds == (bounds)0)
    //     this->display();
}

void Drawer2D::prepare(int argc, char** argv) {
    Drawer2DDisplayer::drawer = this;
    glutInit(&argc, argv);                 // Initialize GLUT
    glutCreateWindow("OpenGL Setup Test"); // Create a window with the given title
    glutInitWindowSize(320, 320);   // Set the window's initial width & height
    glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
    glutIdleFunc(Drawer2DDisplayer::display); // Register display callback handler for window re-paint
    glutReshapeFunc(reshape);       // Register callback handler for window re-size event
}

void Drawer2D::draw() {
    glutMainLoop();           // Enter the event-processing loop
}

}
