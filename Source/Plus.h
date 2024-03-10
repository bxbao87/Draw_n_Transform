#ifndef PLUS_H
#define PLUS_H

#include"Polygon.h"

class Plus :public Polygon_ {
public:
	Plus(Point src);
	void updateDest(int x, int y);
	void addVertices();
};


#endif // !PLUS_H
