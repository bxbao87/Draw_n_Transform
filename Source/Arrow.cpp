#include "Arrow.h"

Arrow::Arrow(Point src):Polygon_(src)
{
}

void Arrow::updateDest(int x, int y)
{
	SObject::updateDest(x, y);
	this->addVertices();
}

void Arrow::addVertices()
{
	this->points.clear();

	int dx = abs(this->src.getX() - this->dest.getX());
	int dy = abs(this->src.getY() - this->dest.getY());
	if ( dx == 0 || dy == 0)
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
	Point s(lX,lY), d(rX,hY);


	int quarterY = round(dy / 4);
	int two3rdX = round(dx * 2 / 3);

	this->points.push_back(Point(s.getX(), s.getY() + quarterY));
	this->points.push_back(Point(s.getX() + two3rdX, s.getY() + quarterY));
	this->points.push_back(Point(s.getX() + two3rdX, s.getY()));
	this->points.push_back(Point(d.getX(), s.getY() + round(dy / 2)));
	this->points.push_back(Point(s.getX() + two3rdX, d.getY()));
	this->points.push_back(Point(s.getX() + two3rdX, d.getY() - quarterY));
	this->points.push_back(Point(s.getX(), d.getY() - quarterY));

}
