#ifndef STAR_H
#define STAR_H

#include"Polygon.h"

class Star : public Polygon_ {
public:
	Star(Point src);
	void updateDest(int x, int y);
	void addVertices();
};




#endif // !STAR_H
