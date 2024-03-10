#ifndef CIRCLE_H
#define CIRCLE_H

#include "SObject.h"

class Circle :public SObject {
private:
	Point center;
	int rad;

	void calculateRadius();
public:
	Circle(Point src=Point(0,0));
	void updateDest(int x, int y);
	void updateCanvas(Canvas& canvas, int val);
	void rotate(Canvas& canvas, int deg);
	void translate(Canvas& canvas, int x, int y);
	void scale(Canvas& canvas, int mag); 
	void add8SymmetricPoints(Canvas &canvas, int x, int y, int val);
	bool checkInside(int x, int y);
};



#endif // !CIRCLE_H
