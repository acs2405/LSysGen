
#include "Drawer2D.h"

// #include "FreeImage.h"

#include <math.h>
#include <vector>
// #include <gl2ps.h>


#ifndef M_PI
#define M_PI std::atan(1)*4
#endif
// constexpr double pi() { return std::atan(1)*4; }



int main(int argc, char** argv) {
    if (argc < 2 || argc > 3) {
        std::cerr << "Usage: lsys2d FILE.lsd [N_ITERATIONS]" << std::endl;
        exit(1);
    }

    // g2D_prepare(argc, argv);

    lsysgen::LSystem<char>* lsystem = parseLSystemFromFile(argv[1]);

    if (lsystem == nullptr)
        exit(1);

    lsystem->prepare();

    if (argc == 3) {
        int n = std::stoi(argv[2]);
        // lsystem->iterations = n;
        lsystem->iterate(n);
    } else {
        lsystem->iterate();
    }

    // int i = 0;
    // for (lsysgen::ParseTreeNode<lsysgen::InstanceNodeContent, char>* iteration : *lsystem->encodedProgression) {
    //     std::cout << i++ << ": " << iteration->toString() << std::endl;
    // }
    // std::cout << lsystem->encodedProgression->back()->toString() << std::endl;

    lsysgen::Drawer2D drawer(lsystem);
    drawer.prepare(argc, argv);
    drawer.draw();

    return 0;
}



namespace lsysgen {

class Drawer2DDisplayer {
public:
    static Drawer2D* drawer;

    static void display() {drawer->display();}
    static void reshape(GLsizei width, GLsizei height) {drawer->reshape(width, height);}
    static void click(int button, int state, int x, int y) {drawer->click(button, state, x, y);}
    static void keyPressed(unsigned char key, int x, int y) {drawer->keyPressed(key, x, y);}
    static void specialKeyPressed(int key, int x, int y) {drawer->specialKeyPressed(key, x, y);}
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
    std::list<Point2D>* fillList = new std::list<Point2D>();
    for (node = parent->leftmostChild();
            node != nullptr;
            node = node->right()) {
        move = 0.0;
        if (node->isLeaf()) {
            if (node->element() == 'F' || node->element() == 'G' ||
                    node->element() == 'f' || node->element() == 'g') {
                double sign = (node->element() == 'F' || node->element() == 'f') ? 1.0 : -1.0;
                values = node->content().values;
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
                values = node->content().values;
                if (values == nullptr || values->size() == 0) {
                    state.dir += sign*(lsystem && !std::isnan(lsystem->rotation) ? lsystem->rotation : DEFAULT_ROTATION);
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
                values = node->content().values;
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
                    // std::cout << r << ", " << g << ", " << b << std::endl;
                    if (draw) {
                        glEnd();
                        glBegin(GL_LINE_STRIP);
                    }
                    // glColor4f(state.fillColor.r, state.fillColor.g, state.fillColor.b, state.fillColor.a);
                    glColor4f(state.penColor.r, state.penColor.g, state.penColor.b, state.penColor.a);
                    // std::cout << state.penColor.r << ", " << state.penColor.g << ", " << state.penColor.b << std::endl;
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
                fillList->push_back(Point2D{state.pos.x, state.pos.y});
            if (node->element() == 'p') {
                if (fill) {
                    if (draw) {
                        glEnd();
                    }
                    glBegin(GL_POLYGON);
                    glColor4f(state.fillColor.r, state.fillColor.g, state.fillColor.b, state.fillColor.a);
                    // Fill a polygon with the saved points
                    for (Point2D p : *fillList)
                        glVertex2f(p.x, p.y);
                    fillList->clear();
                    glEnd();
                    if (draw) {
                        glBegin(GL_LINE_STRIP);
                        glColor4f(state.penColor.r, state.penColor.g, state.penColor.b, state.penColor.a);
                    }
                    fill = false;
                } else {
                    // ERROR
                }
            }
            if (lastDraw == false && draw == true) {
                // glEnd();
                glBegin(GL_LINE_STRIP);
                glColor4f(state.penColor.r, state.penColor.g, state.penColor.b, state.penColor.a);
                glVertex2f(state.pos.x, state.pos.y);
            } else if (lastDraw == true && draw == false) {
                glEnd();
                // glBegin(GL_POINTS);
            }
            if (move > 0) {
                state.pos.x += move*std::cos(state.dir*M_PI/180);
                state.pos.y += move*std::sin(state.dir*M_PI/180);
                if (state.pos.x < bounds.x0)
                    bounds.x0 = state.pos.x;
                if (state.pos.y < bounds.y0)
                    bounds.y0 = state.pos.y;
                if (state.pos.x > bounds.x1)
                    bounds.x1 = state.pos.x;
                if (state.pos.y > bounds.y1)
                    bounds.y1 = state.pos.y;
                glVertex2f(state.pos.x, state.pos.y);
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

// void Drawer2D::saveVectorImage() {
//     FILE *fp = fopen("MyFile", "wb");
//     GLint buffsize = 0, state = GL2PS_OVERFLOW;
//     GLint viewport[4];

//     glGetIntegerv(GL_VIEWPORT, viewport);

//     while( state == GL2PS_OVERFLOW ){
//         buffsize += 1024*1024;
//         gl2psBeginPage ( "MyTitle", "MySoftware", viewport,
//                        GL2PS_EPS, GL2PS_BSP_SORT, GL2PS_SILENT |
//                        GL2PS_SIMPLE_LINE_OFFSET | GL2PS_NO_BLENDING |
//                        GL2PS_OCCLUSION_CULL | GL2PS_BEST_ROOT,
//                        GL_RGBA, 0, NULL, 0, 0, 0, buffsize,
//                        fp, "MyFile" );
//         ParseTreeNode<InstanceNodeContent, char>* node = lsystem->encodedProgression->back();
//         State2D state2d {0, 0, lsystem->initialHeading, 0, 0, 0};
//         this->drawBranch(node, state2d);
//         state = gl2psEndPage();
//     }

//     fclose(fp);
// }

// void saveImage() {
//     int width = 500, height = 500;
//     // Make the BYTE array, factor of 3 because it's RBG.
//     BYTE* pixels = new BYTE[3 * width * height];

//     glReadPixels(0, 0, width, height, GL_RGB, GL_UNSIGNED_BYTE, pixels);

//     // Convert to FreeImage format & save to file
//     FIBITMAP* image = FreeImage_ConvertFromRawBits(pixels, width, height, 3 * width, 24, 0x0000FF, 0xFF0000, 0x00FF00, false);
//     FreeImage_Save(FIF_BMP, image, "test.bmp", 0);

//     // Free resources
//     FreeImage_Unload(image);
//     delete [] pixels;
// }

void Drawer2D::click(int button, int state, int x, int y) {
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        this->lsystem->iterate(1);
    } else if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
        this->lsystem->iterate(-1);
    }
    bounds = {0, 0, 0, 0};
    // this->draw();
}
void Drawer2D::keyPressed(unsigned char key, int x, int y) {
    if (key == 'q') {
        exit(0);
    }
}
void Drawer2D::specialKeyPressed(int key, int x, int y) {
    if(key == GLUT_KEY_RIGHT) {
        this->lsystem->iterate(1);
    } else if(key == GLUT_KEY_LEFT) {
        this->lsystem->iterate(-1);
    }
    bounds = {0, 0, 0, 0};
    // this->draw();
}

/* Handler for window re-size event. Called back when the window first appears and
   whenever the window is re-sized with its new width and height */
void Drawer2D::reshape(GLsizei width, GLsizei height) {  // GLsizei for non-negative integer
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
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);         // Clear the color buffer (background)

    ParseTreeNode<InstanceNodeContent, char>* node = lsystem->current();
    State2D state;
    state.dir = lsystem->initialHeading;
    this->drawBranch(node, state);
 
    // // Draw a Red 1x1 Square centered at origin
    // glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
    //     glColor4f(1.0f, 0.0f, 0.0f, 0.1f); // Red
    //     glVertex2f(bounds.x0, bounds.y0);    // x, y
    //     glVertex2f(bounds.x1, bounds.y0);
    //     glVertex2f(bounds.x1, bounds.y1);
    //     glVertex2f(bounds.x0, bounds.y1);
    // glEnd();
    // state = {0, 0, lsystem->initialHeading, 0, 0, 0};
    // this->drawBranch(node, state);
 
    glFlush();  // Render now

    this->reshape(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));

    // if (bounds == (bounds)0)
    //     this->display();
}

void Drawer2D::prepare(int argc, char** argv) {
    Drawer2DDisplayer::drawer = this;
    glutInit(&argc, argv);                 // Initialize GLUT
    glutCreateWindow(this->lsystem->name().c_str()); // Create a window with the given title
    glutInitWindowSize(320, 320);   // Set the window's initial width & height
    glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
    glutIdleFunc(Drawer2DDisplayer::display); // Register display callback handler for window re-paint
    glutReshapeFunc(Drawer2DDisplayer::reshape);
    glutMouseFunc(Drawer2DDisplayer::click);
    glutKeyboardFunc(Drawer2DDisplayer::keyPressed);
    glutSpecialFunc(Drawer2DDisplayer::specialKeyPressed);
}

void Drawer2D::draw() {
    glutMainLoop();           // Enter the event-processing loop
}

}
