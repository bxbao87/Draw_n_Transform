#include"Program.h"

static int menu_id;
static int triangleMenuID, quadrangleMenuID,
regularPolygonMenuID, othersMenuID;

const int POLYGON = 1;
const int LINE = 2;
const int CIRCLE = 3;
const int R_ISO_TRIANGLE = 4;
const int EQUIL_TRIANGLE = 5;
const int RECTANGLE = 6;
const int SQUARE = 7;
const int EQUIL_PENTAGON = 8;
const int EQUIL_HEXAGON = 9;
const int ARROW = 10;
const int STAR = 11;

const int CHOOSE = 12;
const int CLEAR = 13;
const int EXIT = 14;

Program program;
int num = -1;
bool drawing = false;
bool freedrawing = false;
bool transforming = false;
bool done = false;

void menu(int val) {
    num = val;
    switch (num) {
    case POLYGON:
        freedrawing = true;
        drawing = true;
        transforming = false;
        break;
    case CHOOSE:
        freedrawing = false;
        drawing = false;
        transforming = true;
        break;
    case CLEAR:
        num = -1;
        program.clear();
        glutPostRedisplay();
        break;
    case EXIT:
        glutLeaveMainLoop();
        break;
    default:
        freedrawing = false;
        drawing = true;
        transforming = false;
        break;
    }
}

void createMenu() {
    triangleMenuID = glutCreateMenu(menu);
    glutAddMenuEntry("RIGHT ISOSCELES", R_ISO_TRIANGLE);
    glutAddMenuEntry("EQUILATERAL", EQUIL_TRIANGLE);

    quadrangleMenuID = glutCreateMenu(menu);
    glutAddMenuEntry("RECTANGLE", RECTANGLE);
    glutAddMenuEntry("SQUARE", SQUARE);

    regularPolygonMenuID = glutCreateMenu(menu);
    glutAddMenuEntry("EQUILATERAL PENTAGON", EQUIL_PENTAGON);
    glutAddMenuEntry("EQUILATERAL HEXAGON", EQUIL_HEXAGON);

    othersMenuID = glutCreateMenu(menu);
    glutAddMenuEntry("ARROW", ARROW);
    glutAddMenuEntry("STAR", STAR);

    menu_id = glutCreateMenu(menu);
    glutAddMenuEntry("POLYGON", POLYGON);
    glutAddMenuEntry("LINE", LINE);
    glutAddMenuEntry("CIRCLE", CIRCLE);
    glutAddSubMenu("TRIANGLE", triangleMenuID);
    glutAddSubMenu("QUADRANGLE", quadrangleMenuID);
    glutAddSubMenu("REGULAR POLYGON", regularPolygonMenuID);
    glutAddSubMenu("OTHERS", othersMenuID);
    glutAddMenuEntry("CHOOSE", CHOOSE);
    glutAddMenuEntry("CLEAR", CLEAR);
    glutAddMenuEntry("EXIT", EXIT);

    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void display() {
    program.flush();
    glFlush();
}

void mouse(int button, int state, int x, int y) {
    if (num == -1)
        return;
    if (button == GLUT_LEFT_BUTTON) {
        if (state == GLUT_DOWN) {
            if(drawing) {
                program.initShape(num, Point(x, y));
                done = false;
                if (freedrawing)
                {
                    drawing = false;
                    glutDetachMenu(GLUT_RIGHT_BUTTON);
                }
            }
            else if (transforming) {
                program.checkInside(x,y);
            }
            else if (freedrawing) {
                program.updateShape(x, y);
            }
        }
        else if(state == GLUT_UP && drawing && !done){
            program.addShape();
            done = true;
        }
    }
    else if (button == GLUT_RIGHT_BUTTON && freedrawing) {
        if (!drawing && !done)
        {
            program.addShape();
            done = true;
            drawing = true;
        }
        glutAttachMenu(GLUT_RIGHT_BUTTON);
    }
}

void motion(int x, int y) {
    if (num == -1)
        return;
    if (inViewPort(x, program.getWidth()) && inViewPort(y, program.getHeight())) {
        if (drawing && !done) {
            program.updateShape(x, y);
            glutPostRedisplay();
        }
    }
}

void keyChar(unsigned char key, int x, int y) {
    if (transforming) {
        program.transform(key);
        glutPostRedisplay();
    }
}

void keySpecial(int key, int x, int y) {
    if (transforming) {
        program.translate(key);
        glutPostRedisplay();
    }
}

int main(int argc, char** argv) {
    int w = program.getWidth();
    int h = program.getHeight();

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(w, h);
    glutCreateWindow("Draw and Transform");
    gluOrtho2D(0.0, w, h, 0.0);
    glClearColor(0.0, 0.0, 0.0, 0.0);

    createMenu();
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutKeyboardFunc(keyChar);
    glutSpecialFunc(keySpecial);
    glutMainLoop();

    return 0;
}