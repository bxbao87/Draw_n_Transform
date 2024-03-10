#include "Circle.h"

Circle::Circle(Point src):SObject(src)
{
	this->center = src;
	this->calculateRadius();
}


void Circle::calculateRadius() {
	this->rad = this->center.distance(this->dest);
}

void Circle::updateDest(int x, int y)
{
	SObject::updateDest(x, y);
	this->calculateRadius();
}

void Circle::updateCanvas(Canvas &canvas, int val)
{
	int x = 0;
	int y = this->rad;

	
	int p = 1 - this->rad;

	this->add8SymmetricPoints(canvas, x, y, val);
	while (x<y) {
		++x;
		if (p < 0) {
			p += 2 * x + 1;
		}
		else {
			--y;
			p += 2 * x + 1 - 2 * y;
		}
		this->add8SymmetricPoints(canvas, x, y, val);
	}

}

void Circle::rotate(Canvas& canvas, int deg)
{
	// do nothing because circle rotation is the same.
}

void Circle::translate(Canvas& canvas, int x, int y)
{
	undraw(canvas);
	this->center.setX(x + this->center.getX());
	this->center.setY(y + this->center.getY());
	redraw(canvas);
}

void Circle::scale(Canvas& canvas, int mag)
{
	undraw(canvas);
	float s = (mag + 100.0) / 100.0;
	this->rad = round(s * this->rad);
	redraw(canvas);
}

void Circle::add8SymmetricPoints(Canvas &canvas, int x, int y, int val)
{
	int xp = this->center.getX();
	int yp = this->center.getY();

	canvas.setPixel(x + xp, y + yp, val);
	canvas.setPixel(x + xp, -y + yp, val);
	canvas.setPixel(-x + xp, -y + yp, val);
	canvas.setPixel(-x + xp, y + yp, val);
	
	canvas.setPixel(y + xp, x + yp, val);
	canvas.setPixel(y + xp, -x + yp, val);
	canvas.setPixel(-y + xp, -x + yp, val);
	canvas.setPixel(-y + xp, x + yp, val);
}

bool Circle::checkInside(int x, int y)
{
	if (this->center.distance(Point(x, y)) <= this->rad) {
		return true;
	}
	return false;
}
