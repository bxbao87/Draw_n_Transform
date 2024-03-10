#ifndef MULTIPLICATION_H
#define MULTIPLICATION_H

#include"Polygon.h"

class Multiplication : public Polygon_ {
public:
	Multiplication(Point src);
	void updateDest(int x, int y);
	void addVertices();
};



#endif // !MULTIPLICATION_H
