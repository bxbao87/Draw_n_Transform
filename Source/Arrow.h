#ifndef ARROW_H
#define ARROW_H

#include"Polygon.h"

class Arrow : public Polygon_{
public:
	Arrow(Point src);
	void updateDest(int x, int y);
	void addVertices();

};



#endif // !ARROW_H
