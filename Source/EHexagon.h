#ifndef EHEXAGON_H
#define EHEXAGON_H

#include"Polygon.h"

class EHexagon : public Polygon_ {
public:
	EHexagon(Point src);
	void updateDest(int x, int y);
	void addVertices();
};


#endif // !EHEXAGON_H
