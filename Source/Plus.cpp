#include "Plus.h"

Plus::Plus(Point src) :Polygon_(src)
{
}

void Plus::updateDest(int x, int y)
{
	SObject::updateDest(x, y);
	this->addVertices();
}

void Plus::addVertices()
{
	this->points.clear();
	int DX = this->dest.getX() - this->src.getX();
	int DY = this->dest.getY() - this->src.getY();

	if (DX == 0 || DY == 0)
	{
		this->points.push_back(this->src);
		this->points.push_back(this->dest);
		return;
	}

	int sX = DX / abs(DX);
	int sY = DY / abs(DY);
	int length = abs(DX) > abs(DY) ? abs(DY) : abs(DX);
	int one3 = round(length / 3);
	int two3 = round(2 * length / 3);

	this->points.push_back(Point(this->src.getX(), this->src.getY() + one3 * sY));
	this->points.push_back(Point(this->src.getX() + one3 * sX, this->src.getY() + one3 * sY));
	this->points.push_back(Point(this->src.getX() + one3 * sX, this->src.getY()));
	this->points.push_back(Point(this->src.getX() + two3 * sX, this->src.getY()));
	this->points.push_back(Point(this->src.getX() + two3 * sX, this->src.getY() + one3 * sY));
	this->points.push_back(Point(this->src.getX() + length * sX, this->src.getY() + one3 * sY));

	this->points.push_back(Point(this->src.getX() + length * sX, this->src.getY() + two3 * sY));
	this->points.push_back(Point(this->src.getX() + two3 * sX, this->src.getY() + two3 * sY));
	this->points.push_back(Point(this->src.getX() + two3 * sX, this->src.getY() + length * sY));
	this->points.push_back(Point(this->src.getX() + one3 * sX, this->src.getY() + length * sY));
	this->points.push_back(Point(this->src.getX() + one3 * sX, this->src.getY() + two3 * sY));
	this->points.push_back(Point(this->src.getX(), this->src.getY() + two3 * sY));

	this->root = this->points;
}