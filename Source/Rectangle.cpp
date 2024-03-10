#include "Rectangle.h"

Rectangle_::Rectangle_(Point src):Polygon_(src){}


void Rectangle_::updateDest(int x, int y) {
	SObject::updateDest(x, y);
	this->addVertices();
}

void Rectangle_::addVertices()
{
	this->points.clear();
	this->points.push_back(this->src);
	this->points.push_back(Point(this->src.getX(), this->dest.getY()));
	this->points.push_back(Point(this->dest.getX(), this->dest.getY()));
	this->points.push_back(Point(this->dest.getX(), this->src.getY()));

}


