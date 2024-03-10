#ifndef EPENTAGON_H
#define EPENTAGON_H

#include"Polygon.h"

class EPentagon : public Polygon_ {
public:
	EPentagon(Point src);
	void updateDest(int x, int y);
	void addVertices();
};


#endif // !EPENTAGON_H
