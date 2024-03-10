#include"SObject.h"

SObject::SObject(Point s)
{
	this->src = s;
	this->dest = s;
}

void SObject::done()
{
}

void SObject::updateDest(int x, int y)
{
	this->dest.setX(x);
	this->dest.setY(y);
}

void SObject::draw(Canvas& canvas) {
	updateCanvas(canvas, 1);
}

void SObject::undraw(Canvas& canvas)
{
	//undraw -> là xóa selected và xóa cái draw
	updateCanvas(canvas, 999);
}

void SObject::redraw(Canvas& canvas)
{
	updateCanvas(canvas, -999);
}

void SObject::selected(Canvas& canvas)
{
	updateCanvas(canvas, -1000);
}

void SObject::unselected(Canvas& canvas)
{
	updateCanvas(canvas, +1000);
}

void SObject::updateCanvas(Canvas& canvas, int val)
{
}

void SObject::rotate(Canvas& canvas, int deg)
{
}

void SObject::translate(Canvas& canvas, int x, int y)
{
}

void SObject::scale(Canvas& canvas, int mag)
{
}

bool SObject::checkInside(int x, int y)
{
	return false;
}


