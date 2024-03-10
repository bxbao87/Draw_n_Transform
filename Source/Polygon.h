#ifndef POLYGON_H
#define POLYGON_H

#include"Line.h"

class Polygon_ : public SObject {
protected:
	vector<Point> points;
	vector<Point> root;
	Matrix transformMatrix;
	Point centerPoint;

	bool condition(int x, int y, int x0, int y0, int x1, int y1);
	void calculateCenterPoint();

public:
	Polygon_(Point src);
	void done();
	virtual void updateCanvas(Canvas& canvas, int val);
	virtual void updateDest(int x, int y);
	virtual void rotate(Canvas& canvas, int deg);
	virtual void translate(Canvas& canvas, int x, int y);
	virtual void scale(Canvas& canvas, int mag); 
	virtual void addVertices();
	virtual bool checkInside(int x, int y);
};


#endif // !POLYGON_H
