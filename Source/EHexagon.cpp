#include "EHexagon.h"

EHexagon::EHexagon(Point src):Polygon_(src){}

void EHexagon::updateDest(int x, int y)
{
	SObject::updateDest(x, y);
	this->addVertices();
}


void EHexagon::addVertices() {
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
	int yCor = round(length / (2 * tanf((60.0/180.0)*3.14159)));
	int side = round(length / sqrt(3));
	
	Point s = this->src;
	Point 
		p1(s.getX() + sX * round(length / 2), s.getY()),
		p2(s.getX() + sX * length, s.getY() + sY * yCor),
		p3(s.getX() + sX * length, s.getY() + sY * (yCor + side)),
		p4(s.getX() + sX * round(length / 2), s.getY() + 2 * sY * side),
		p5(s.getX(), s.getY() + sY * (yCor + side)),
		p6(s.getX(), s.getY() + sY * yCor);

	this->points.push_back(p1);
	this->points.push_back(p2);
	this->points.push_back(p3); 
	this->points.push_back(p4);
	this->points.push_back(p5);
	this->points.push_back(p6);

}
