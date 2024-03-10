#include "Square.h"

Square::Square(Point src):Polygon_(src){}

void Square::updateDest(int x, int y)
{
	SObject::updateDest(x, y);
	this->addVertices();
}

void Square::addVertices()
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

	this->points.push_back(this->src);
	this->points.push_back(Point(this->src.getX(), this->src.getY() + length * sY));
	this->points.push_back(Point(this->src.getX() + length * sX, this->src.getY() + length * sY));
	this->points.push_back(Point(this->src.getX() + length * sX, this->src.getY()));

}
