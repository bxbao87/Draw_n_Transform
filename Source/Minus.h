#ifndef MINUS_H
#define MINUS_H

#include"Polygon.h"

class Minus :public Polygon_ {
public:
	Minus(Point src);
	void updateDest(int x, int y);
	void addVertices();
};


#endif // !MINUS_H
