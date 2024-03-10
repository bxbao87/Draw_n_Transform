#include"Program.h"
#include"RightAngledIsoscelesTriangle.h"
#include"EquilateralTriangle.h"
#include"Rectangle.h"
#include"Square.h"
#include"Circle.h"
#include"Ellipse.h"
#include"EPentagon.h"
#include"EHexagon.h"
#include"Arrow.h"
#include"Star.h"
#include"Plus.h"
#include"Minus.h"
#include"Multiplication.h"
#include"Division.h"
#include"Polygon.h"

Program::Program(int w, int h) {
    this->w = w;
    this->h = h;
    this->selecting = false;
    this->s = nullptr;
    this->background.initCanvas(w, h);
    this->tmp.initCanvas(w, h);
}

Program::~Program() {
    for (auto a : shapeList)
        delete a;
}

int Program::getWidth() {
    return this->w;
}

int Program::getHeight() {
    return this->h;
}

void Program::initShape(int num, Point src) {
    if (this->selecting)
        this->unselect(); 

    switch (num) {
    case 1:
        s = new Polygon_(src);
        break;
    case 2:
        s = new Line(src);
        //cout << "line" << endl;
        break;
    case 3:
        s = new Circle(src);
        //cout << "hinh tron" << endl;
        break;
    case 4:
        s = new RightAngledIsoscelesTriangle(src);
        //cout << "vuong can" << endl;
        break;
    case 5:
        s = new EquilateralTriangle(src);
        //cout << "deu" << endl;
        break;
    case 6:
        s = new Rectangle_(src);
        //cout << "hinh chu nhat" << endl;
        break;
    case 7:
        s = new Square(src);
        //cout << "hinh vuong" << endl;
        break;
    case 8:
        s = new EPentagon(src);
        //cout << "ngu giac deu" << endl;
        break;
    case 9:
        s = new EHexagon(src);
        //cout << "luc giac deu" << endl;
        break;
    case 10:
        s = new Arrow(src);
        //cout << "mui ten" << endl;
        break;
    case 11:
        s = new Star(src);
        //cout << "ngoi sao" << endl;
        break;
    case 12:
        //cout << "chon hinh" << endl;
        break;
    }

    /*
    for each shape add the src
    */
}

void Program::updateShape(int x, int y) { // call for mouse down motion
    this->s->updateDest(x, y);
    this->draw();
}


void Program::draw() { // call when mouse down motion after updateShape()
    if (this->s == nullptr)
        return;
    this->resetTmp();
    this->s->draw(this->tmp);
}

void Program::resetTmp() { // call after finishing 1 draw and motion
    this->tmp = this->background;
}

void Program::addShape() { // call when left mouse up, add s to shapeList
    this->shapeList.push_back(s);
    this->s->done();
    //cout << this->shapeList.size()-1 << endl;
    this->updateBackground();
}

void Program::updateBackground() {// call when add shape
    this->background = this->tmp;
}

void Program::flush()
{
    this->tmp.updateToConsoleWindow();
}

void Program::transform(unsigned char key)
{
    if (!this->selecting || this->s == nullptr)
        return;
    switch (key) {
    case 'l':
        this->s->rotate(this->background, +1);
        break;
    case 'r':
        this->s->rotate(this->background, -1);
        break;
    case '+':
        this->s->scale(this->background, 10);
        break;
    case '-':
        this->s->scale(this->background, -10);
        break;
    }
    this->resetTmp();
}

void Program::translate(int key) {
    if (!this->selecting || this->s == nullptr)
        return;
    switch (key) {
    case GLUT_KEY_UP:
        s->translate(this->background, 0, -1);
        break;
    case GLUT_KEY_DOWN:
        s->translate(this->background, 0, +1);
        break;
    case GLUT_KEY_LEFT:
        s->translate(this->background, -1, 0);
        break;
    case GLUT_KEY_RIGHT:
        s->translate(this->background, +1, 0);
        break;
    }
    this->resetTmp();
}

bool Program::checkInside(int x, int y)
{
    if (this->selecting)
        this->unselect();

    int sz = shapeList.size();
    for (int i = sz - 1; i >= 0; --i) {
        if (this->shapeList[i]->checkInside(x, y))
        {
            this->s = this->shapeList[i];
            this->select();
            return true;
        }
    }
    return false;
}

void Program::select()
{
    this->s->selected(this->background);
    this->selecting = true;
    this->resetTmp();
}

void Program::unselect()
{
    this->s->unselected(this->background);
    this->selecting = false;
    this->resetTmp();
}

void Program::clear()
{
    this->selecting = false;
    this->s = nullptr;
    this->background.initCanvas(w, h);
    this->tmp.initCanvas(w, h);
    for (auto a : this->shapeList)
        delete a;
    this->shapeList.clear();
}


