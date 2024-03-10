#include "Multiplication.h"

Multiplication::Multiplication(Point src) :Polygon_(src)
{
}

void Multiplication::updateDest(int x, int y)
{
	SObject::updateDest(x, y);
	this->addVertices();
}

void Multiplication::addVertices()
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
	float sixth = length / 6;
	int one6 = round(sixth);
	int two6 = round(2 * sixth);
	int three6 = round(3 * sixth);
	int four6 = round(4 * sixth);
	int five6 = round(5 * sixth);

	this->points.push_back(Point(this->src.getX(), this->src.getY() + one6 * sY));
	this->points.push_back(Point(this->src.getX() + one6 * sX, this->src.getY()));
	this->points.push_back(Point(this->src.getX() + three6 * sX, this->src.getY() + two6 * sY));
	this->points.push_back(Point(this->src.getX() + five6 * sX, this->src.getY()));
	this->points.push_back(Point(this->src.getX() + length * sX, this->src.getY() + one6 * sY));
	this->points.push_back(Point(this->src.getX() + four6 * sX, this->src.getY() + three6 * sY));

	this->points.push_back(Point(this->src.getX() + length * sX, this->src.getY() + five6 * sY));
	this->points.push_back(Point(this->src.getX() + five6 * sX, this->src.getY() + length * sY));
	this->points.push_back(Point(this->src.getX() + three6 * sX, this->src.getY() + four6 * sY));
	this->points.push_back(Point(this->src.getX() + one6 * sX, this->src.getY() + length * sY));
	this->points.push_back(Point(this->src.getX(), this->src.getY() + five6 * sY));
	this->points.push_back(Point(this->src.getX() + two6 * sX, this->src.getY() + three6 * sY));

	this->root = this->points;
}
