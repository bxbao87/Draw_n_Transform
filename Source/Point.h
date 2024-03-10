#ifndef POINT_H
#define POINT_H


#include"Matrix.h"

class Point {
private:
	int x, y;
public:
	Point(int x = 0, int y = 0);
	int distance(Point p);
	int getX();
	int getY();
	void setX(int x);
	void setY(int y);
	Matrix getPointMatrix();
};

#endif // !POINT_H
