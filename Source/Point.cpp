#include "Point.h"

Point::Point(int x, int y)
{
	this->x = x;
	this->y = y;
}

int Point::distance(Point p)
{
	long x = (p.x - this->x);
	long y = (p.y - this->y);
	return round(sqrt(x * x + y * y));
}

int Point::getX() {
	return this->x;
}

int Point::getY() {
	return this->y;
}

void Point::setX(int x)
{
	this->x = x;
}

void Point::setY(int y)
{
	this->y = y;
}

Matrix Point::getPointMatrix()
{
	vector<float> tmp{ float(this->x),float(this->y),1 };
	Matrix ret(1, 3);
	ret.setMatrix(tmp);
	return ret;
}
