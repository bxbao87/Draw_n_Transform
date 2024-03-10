#ifndef DIVISION_H
#define DIVISION_H

#include"Polygon.h"
#include "Circle.h"
#include "Rectangle.h"

class Division : public Polygon_ {
private:
	Circle c1, c2;
	Rectangle_ rect;
public:
	Division(Point src);
	void updateDest(int x, int y);
	void updateCanvas(Canvas& canvas, int val); 
	void rotate(Canvas& canvas, int deg);
	void translate(Canvas& canvas, int x, int y);
	void scale(Canvas& canvas, int mag);
	bool checkInside(int x, int y);
};

#endif // !DIVISION_H
