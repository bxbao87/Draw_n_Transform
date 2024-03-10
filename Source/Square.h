#ifndef SQUARE_H
#define SQUARE_H

#include"Polygon.h"

class Square : public Polygon_ {
public:
	Square(Point src);
	void updateDest(int x, int y);
	void addVertices();
};



#endif // !SQUARE_H
