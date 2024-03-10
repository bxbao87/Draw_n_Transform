#include "Minus.h"

Minus::Minus(Point src) :Polygon_(src) {}


void Minus::updateDest(int x, int y) {
	SObject::updateDest(x, y);
	this->addVertices();
}

void Minus::addVertices()
{
	this->points.clear();


	int dx = abs(this->src.getX() - this->dest.getX());
	int dy = abs(this->src.getY() - this->dest.getY());
	if (dx == 0 || dy == 0)
	{
		this->points.push_back(this->src);
		this->points.push_back(this->dest);
		return;
	}

	int lX = this->src.getX(), rX = lX;
	int lY = this->src.getY(), hY = lY;
	if (lX > this->dest.getX())
		lX = this->dest.getX();
	else rX = this->dest.getX();

	if (lY > this->dest.getY())
		lY = this->dest.getY();
	else hY = this->dest.getY();
	Point s(lX+dx/3, lY+dy/3), d(rX-dx/3, hY-dy/3);

	this->points.push_back(s);
	this->points.push_back(Point(s.getX(), d.getY()));
	this->points.push_back(Point(d.getX(), d.getY()));
	this->points.push_back(Point(d.getX(), s.getY()));

	this->root = this->points;
}


