#include "Division.h"

Division::Division(Point src) :Polygon_(src) {
	
}

void Division::updateDest(int x, int y)
{
	SObject::updateDest(x, y);
}

void Division::updateCanvas(Canvas& canvas, int val)
{
	int dx = abs(this->src.getX() - this->dest.getX());
	int dy = abs(this->src.getY() - this->dest.getY());
	if (dx == 0 || dy == 0)
	{
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
	Point s(lX, lY), d(rX, hY);


	float eighthY = dy / 8;
	int halfX = round(dx / 2);
	int thirdX = round(dx / 3);

	Circle c1(Point(s.getX() + halfX, s.getY() + round(eighthY)));
	c1.updateDest(s.getX() + halfX, s.getY() + round(2 * eighthY));
	c1.updateCanvas(canvas, val);
	this->c1 = c1;

	Circle c2(Point(s.getX() + halfX, d.getY() - round(eighthY)));
	c2.updateDest(s.getX() + halfX, d.getY() - round(2 * eighthY));
	c2.updateCanvas(canvas, val);
	this->c2 = c2;

	Rectangle_ rect(Point(s.getX() + thirdX, s.getY() + round(3 * eighthY)));
	rect.updateDest(d.getX() - thirdX, d.getY() - round(3 * eighthY));
	rect.updateCanvas(canvas, val);
	this->rect = rect;
}

void Division::rotate(Canvas& canvas, int deg)
{
}

void Division::translate(Canvas& canvas, int x, int y)
{
	undraw(canvas);
	this->src.setX(x + this->src.getX());
	this->src.setY(y + this->src.getY());
	this->updateDest(x + this->dest.getX(), y + this->dest.getY());
	redraw(canvas);
}

void Division::scale(Canvas& canvas, int mag)
{
	undraw(canvas);
	float s = (mag + 100.0) / 100.0;
	/*this->src.setX(round(s * this->src.getX()));
	this->src.setY(round(s * this->src.getY()));
	*/
	this->updateDest(
		round(s * this->dest.getX() + (1 - s) * this->src.getX()),
		round(s * this->dest.getY() + (1 - s) * this->src.getY())
	);
	redraw(canvas);
}

bool Division::checkInside(int x, int y)
{
	if (this->c1.checkInside(x, y) || this->c2.checkInside(x, y) || this->rect.checkInside(x, y))
		return true;
	return false;
}
