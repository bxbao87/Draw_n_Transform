#include "EquilateralTriangle.h"

EquilateralTriangle::EquilateralTriangle(Point src):Polygon_(src){}

void EquilateralTriangle::updateDest(int x, int y)
{
	SObject::updateDest(x, y);
	this->addVertices();
}


void EquilateralTriangle::addVertices() {
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
	int height = round((sqrt(3) / 2.0) * length);

	int newY = 0;
	if (sY < 0)
		newY = height;
	Point s(this->src.getX(), this->src.getY() + newY * sY);

	Point p1(s.getX() + sX * round(length / 2), s.getY()),
		p2(s.getX(), s.getY() + height),
		p3(s.getX() + sX * length, s.getY() + height);

	this->points.push_back(p1);
	this->points.push_back(p2);
	this->points.push_back(p3);

}
