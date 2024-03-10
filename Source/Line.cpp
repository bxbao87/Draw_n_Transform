#include "Line.h"

Line::Line(Point s) :SObject(s), transformMatrix(3,3) {
	vector<float> tmp = { 1.0,0.0,0.0, 0.0,1.0,0.0, 0.0,0.0,1.0 };
	this->transformMatrix.setMatrix(tmp);
}

void Line::done()
{
	this->endpoint = this->dest;
}

void Line::updateCanvas(Canvas& canvas, int val)
{
	int Dx = this->dest.getX() - this->src.getX();
	int Dy = this->dest.getY() - this->src.getY();
	int step = abs(Dx) > abs(Dy) ? abs(Dx) : abs(Dy);
	float mX = 1.0 * Dx / step;
	float mY = 1.0 * Dy / step;

	float x = this->src.getX();
	float y = this->src.getY();

	canvas.setPixel(round(x), round(y), val);

	for (int k = 0; k < step; ++k) {
		x += mX;
		y += mY;
		
		canvas.setPixel(round(x), round(y), val);
	}
}

void Line::rotate(Canvas& canvas, int deg)
{
	undraw(canvas);
	float rdeg = 3.1415 * deg / 180.0;
	int xp = this->src.getX(), yp = this->src.getY();

	MRotate3x3 rot(rdeg);
	MTranslate3x3 tr1(-xp, -yp), tr2(xp, yp);
	this->transformMatrix = this->transformMatrix.multiply(tr1).multiply(rot).multiply(tr2);
	Matrix tmp = this->endpoint.getPointMatrix().multiply(transformMatrix);
	updateDest(round(tmp.getX()), round(tmp.getY()));
	redraw(canvas);
}

void Line::translate(Canvas& canvas, int x, int y)
{
	undraw(canvas);
	this->src.setX(x + this->src.getX());
	this->src.setY(y + this->src.getY());
	MTranslate3x3 tr(x, y);
	this->transformMatrix = this->transformMatrix.multiply(tr);
	Matrix tmp = this->endpoint.getPointMatrix().multiply(transformMatrix);
	updateDest(round(tmp.getX()), round(tmp.getY()));
	redraw(canvas);
}

void Line::scale(Canvas& canvas, int mag)
{
	undraw(canvas);
	float s = (mag + 100.0) / 100.0;

	MScale3x3 scal(s, s);
	MTranslate3x3 tr(this->src.getX() * (1 - s), this->src.getY() * (1 - s));
	this->transformMatrix = this->transformMatrix.multiply(scal).multiply(tr);
	Matrix tmp = this->endpoint.getPointMatrix().multiply(this->transformMatrix);
	this->updateDest(
		round(tmp.getX()),
		round(tmp.getY())
		);
	redraw(canvas);
}

bool Line::checkInside(int x, int y)
{
	int xSC = x - this->src.getX(), xSD = this->dest.getX() - this->src.getX();
	int ySC = y - this->src.getY(), ySD = this->dest.getY() - this->src.getY();
	
	int a = this->src.getX(), b = this->dest.getX(), c = x, d = ySC;
	if (!xSC)
	{
		a = this->src.getY();
		b = this->dest.getY();
		x = y;
		d = xSC;
	}
	if (!d) {
		if (c <= max(a, b) && c >= min(a, b))
			return true;
		else return false;
	}

	float k = float(xSD / xSC);
	if (k == float(ySD / ySC) && k >= 1) {
		return true;
	}
	return false;
}
