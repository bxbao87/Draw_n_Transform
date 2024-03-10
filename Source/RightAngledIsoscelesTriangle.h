#ifndef RIGHT_ANGLED_ISOSCELES_TRIANGLE
#define RIGHT_ANGLED_ISOSCELES_TRIANGLE

#include"Polygon.h"

class RightAngledIsoscelesTriangle : public Polygon_ {
public:
	RightAngledIsoscelesTriangle(Point src);
	void updateDest(int x, int y);
	void addVertices();
};

#endif // !RIGHT_ANGLED_ISOSCELES_TRIANGLE
