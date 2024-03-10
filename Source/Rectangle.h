#ifndef RECTANGLE_H
#define RECTANGLE_H

#include"Polygon.h"

class Rectangle_ :public Polygon_ {
public:
	Rectangle_(Point src=Point(0,0));
	void updateDest(int x, int y);
	void addVertices();
};



#endif // !RECTANGLE_H
