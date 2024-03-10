#ifndef EQUILATERAL_TRIANGLE_H
#define EQUILATERAL_TRIANGLE_H

#include"Polygon.h"

class EquilateralTriangle : public Polygon_ {
public:
	EquilateralTriangle(Point src);
	void updateDest(int x, int y);
	void addVertices();
};

#endif