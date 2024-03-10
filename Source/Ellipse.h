#ifndef ELLIPSE_H
#define ELLIPSE_H

#include"SObject.h"

class Ellipse_ : public SObject {
private:
	Point center;
	int la, lb;
	Matrix transformMatrix;
	void calculateAxisLength();
public:
	Ellipse_(Point src=Point(0,0));
	void updateDest(int x, int y);
	void updateCanvas(Canvas& canvas, int val);
	void rotate(Canvas& canvas, int deg);
	void translate(Canvas& canvas, int x, int y);
	void scale(Canvas& canvas, int mag);
	void add4SymmetricPoints(Canvas &canvas, int x, int y, int val);
	bool checkInside(int x, int y);
};


#endif // !ELLIPSE_H
