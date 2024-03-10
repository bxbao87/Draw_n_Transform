#ifndef PROGRAM_H
#define PRGORAM_H

#include"Polygon.h"

class Program {
private:
	int w, h;
	bool selecting;
	SObject* s;
	vector<SObject*> shapeList;
	Canvas background;
	Canvas tmp;

	void updateBackground(); // call when add shape
	void resetTmp(); // call after finishing draw

public:
	Program(int w = 640, int h = 480);
	~Program();
	int getWidth();
	int getHeight();
	void initShape(int num, Point src);
	void updateShape(int x, int y);
	void draw();
	void addShape();
	void flush();
	void transform(unsigned char key);
	void translate(int key);
	bool checkInside(int x, int y);
	void select();
	void unselect();
	void clear();
};


#endif // !PROGRAM_H
