#include "Star.h"

Star::Star(Point src) :Polygon_(src) {}

void Star::updateDest(int x, int y)
{
	SObject::updateDest(x, y);
	this->addVertices();
}


void Star::addVertices() {

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
	int halfLength = round(length / 2);
	
	// dont use half-length for more precise
	int yCor1 = round(length / (2.0 * tanf((54.0 / 180.0) * 3.14159))); 
	float side = length / (2.0 * sinf((54.0 / 180.0) * 3.14159));
	int xCor = round(cosf((72 / 180.0) * 3.14159) * side);
	int yCor2 = round(sinf((72 / 180.0) * 3.14159) * side);

	int newY = 0;
	if (sY < 0)
		newY = yCor1 + yCor2;
	Point s(this->src.getX(), this->src.getY() + newY * sY);

	Point
		p1(s.getX() + sX * halfLength, s.getY()),
		p2(s.getX() + sX * (halfLength + round(xCor / 2)), s.getY() + yCor1),

		p3(s.getX() + sX * length, s.getY() + yCor1),
		p4(s.getX() + sX * (halfLength + round((length - 2 * xCor) / 4)), s.getY() + yCor2),

		p5(s.getX() + sX * (length - xCor), s.getY() + (yCor1 + yCor2)),
		p6(s.getX() + sX * halfLength, s.getY() + 2 * yCor1),

		p7(s.getX() + sX * xCor, s.getY() + (yCor1 + yCor2)),
		p8(s.getX() + sX * (halfLength - round((length - 2 * xCor) / 4)), s.getY() + yCor2),

		p9(s.getX(), s.getY() + yCor1),
		p10(s.getX() + sX * (halfLength - round(xCor / 2)), s.getY() + yCor1);

	this->points.push_back(p1);
	this->points.push_back(p2);
	this->points.push_back(p3);
	this->points.push_back(p4);
	this->points.push_back(p5); 
	this->points.push_back(p6);
	this->points.push_back(p7);
	this->points.push_back(p8);
	this->points.push_back(p9);
	this->points.push_back(p10);

}
