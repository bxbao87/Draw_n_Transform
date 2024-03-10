#include "Ellipse.h"

Ellipse_::Ellipse_(Point src):SObject(src), transformMatrix(3,3)
{
	this->center = src;
	this->calculateAxisLength();
	vector<float> tmp = { 1.0,0.0,0.0, 0.0,1.0,0.0, 0.0,0.0,1.0 };
	this->transformMatrix.setMatrix(tmp);
}

void Ellipse_::calculateAxisLength()
{
	this->la = abs(this->center.getX() - dest.getX());
	this->lb = abs(this->center.getY() - dest.getY());
}

void Ellipse_::updateDest(int x, int y)
{
	SObject::updateDest(x, y);
	this->calculateAxisLength();
}

void Ellipse_::updateCanvas(Canvas &canvas, int val)
{
	int x = 0;
	int y = this->lb;
	
	int Dx = this->lb * this->lb; // b^2
	int Dy = this->la * this->la; // a^2

	// p1=b^2-ba^2+1/4*a^2
	float p1 = Dx - this->lb * Dy + Dy / 4;
	
	this->add4SymmetricPoints(canvas, x, y, val);
	while (Dx*x < Dy*y) {
		++x;
		if (p1 < 0) {
			p1 += Dx * (2 * x + 1);
		}
		else {
			--y;
			p1 += Dx * (2 * x + 1) - 2 * Dy * y;
		}
		this->add4SymmetricPoints(canvas, x, y, val);
	}

	float p2 = Dx * (x + 0.5) * (x + 0.5) + Dy * (y - 1.0) * (y - 1.0) - 1.0 * Dx * Dy;
	while (y > 0) {
		--y;
		if (p2 > 0) {
			p2 += -Dy * (2 * y - 1);
		}
		else {
			++x;
			p2 += -Dy * (2 * y - 1) + 2 * Dx * x;
		}
		this->add4SymmetricPoints(canvas, x, y, val);
	}

}

void Ellipse_::rotate(Canvas& canvas, int deg)
{
	undraw(canvas);
	float rdeg = 3.1415 * deg / 180.0;
	int xp = this->center.getX(), yp = this->center.getY();

	MRotate3x3 rot(rdeg);
	MTranslate3x3 tr1(-xp, -yp), tr2(xp, yp);
	this->transformMatrix = this->transformMatrix.multiply(tr1).multiply(rot).multiply(tr2);
	redraw(canvas);
}

void Ellipse_::translate(Canvas& canvas, int x, int y)
{
	undraw(canvas);
	this->center.setX(x + this->center.getX());
	this->center.setY(y + this->center.getY());
	redraw(canvas);
}

void Ellipse_::scale(Canvas& canvas, int mag)
{
	undraw(canvas);
	float s = (mag + 100.0) / 100.0;
	this->la = round(s * this->la);
	this->lb = round(s * this->lb);
	redraw(canvas);
}

void Ellipse_::add4SymmetricPoints(Canvas &canvas, int x, int y, int val)
{
	int xp = this->center.getX();
	int yp = this->center.getY();

	vector<Point> p(4);
	p[0] = Point(x + xp, y + yp);
	p[1] = Point(x + xp, -y + yp);
	p[2] = Point(-x + xp, -y + yp);
	p[3] = Point(-x + xp, y + yp);

	for (int i = 0; i < 4; ++i) {
		Matrix tmp = p[i].getPointMatrix().multiply(transformMatrix);
		canvas.setPixel(round(tmp.getX()), round(tmp.getY()), val);
	}/*
	canvas.setPixel(x + xp, y + yp, val);
	canvas.setPixel(x + xp, -y + yp, val);
	canvas.setPixel(-x + xp, -y + yp, val);
	canvas.setPixel(-x + xp, y + yp, val);*/
}

bool Ellipse_::checkInside(int x, int y)
{
	float dx = 1.0 * (this->center.getX() - x);
	float dy = 1.0 * (this->center.getY() - y);
	float xf = 1.0 * float(dx * dx) / float(la * la);
	float yf = 1.0 * float(dy * dy) / float(lb * lb);

	if (xf + yf <= 1) {
		return true;
	}
	return false;
}

