#include"Polygon.h"

Polygon_::Polygon_(Point src) :SObject(src),transformMatrix(3,3) {
	this->addVertices();
	vector<float> tmp = { 1.0,0.0,0.0, 0.0,1.0,0.0, 0.0,0.0,1.0 };
	this->transformMatrix.setMatrix(tmp);
}

void Polygon_::done()
{
	this->root = this->points;
	this->calculateCenterPoint();
}

void Polygon_::updateDest(int x, int y)
{
	SObject::updateDest(x, y);
	this->addVertices();
}

void Polygon_::updateCanvas(Canvas& canvas, int val) {
	/*
		line ko thuộc shape
		shape draw = line
		truyền canvas, tọa độ cho line
		line cập nhật canvas

	*/

	int sz = this->points.size();

	for (int i = 0; i < sz; ++i) {
		Line line(this->points[i % sz]);
		line.updateDest(this->points[(i + 1) % sz].getX(), this->points[(i + 1) % sz].getY());
		line.updateCanvas(canvas, val);
	}
}

void Polygon_::rotate(Canvas& canvas, int deg)
{
	int sz = this->points.size();
	if (sz > 0) {
		undraw(canvas);
		
		float rdeg = 3.1415 * deg / 180.0;

		MRotate3x3 rot(rdeg);
		MTranslate3x3 tr1(-this->centerPoint.getX(), -this->centerPoint.getY()),
			tr2(this->centerPoint.getX(), this->centerPoint.getY());

		this->transformMatrix = this->transformMatrix.multiply(tr1).multiply(rot).multiply(tr2);
		
		for (int i = 0; i < sz; ++i) {
			Matrix tmp = this->root[i].getPointMatrix().multiply(this->transformMatrix);
			this->points[i].setX(round(tmp.getX()));
			this->points[i].setY(round(tmp.getY()));
		}

		redraw(canvas);
	}
}

void Polygon_::translate(Canvas& canvas, int x, int y)
{
	int sz = this->points.size();
	if (sz > 0) {
		undraw(canvas);

		MTranslate3x3 tr(x,y);
		this->transformMatrix = this->transformMatrix.multiply(tr);

		for (int i = 0; i < sz; ++i) {
			Matrix tmp = this->root[i].getPointMatrix().multiply(this->transformMatrix);
			this->points[i].setX(tmp.getX());
			this->points[i].setY(tmp.getY());
		}
		this->calculateCenterPoint();
		redraw(canvas);
	}
}

void Polygon_::scale(Canvas& canvas, int mag)
{
	int sz = this->root.size();
	if (sz > 0) {
		undraw(canvas);
		float s = (mag + 100.0) / 100.0;

		MScale3x3 scal(s,s);
		MTranslate3x3 tr(this->centerPoint.getX()*(1.0-s), this->centerPoint.getY()*(1.0-s));
		this->transformMatrix = this->transformMatrix.multiply(scal).multiply(tr);

		for (int i = 0; i < sz; ++i) {
			Matrix tmp = this->root[i].getPointMatrix().multiply(this->transformMatrix);
			this->points[i].setX(tmp.getX());
			this->points[i].setY(tmp.getY());
		}
		redraw(canvas);
	}
}

void Polygon_::addVertices()
{
	this->points.push_back(this->dest);
	//this->root.push_back(this->dest);
}

void Polygon_::calculateCenterPoint() 
{
	int x = 0, y = 0;
	int sz = this->points.size();
	for (int i = 0; i < sz; ++i) {
		x += this->points[i].getX();
		y += this->points[i].getY();
	}
	x = round(1.0 * x / sz);
	y = round(1.0 * y / sz);
	this->centerPoint.setX(x);
	this->centerPoint.setY(y);
}

bool Polygon_::condition(int x, int y, int x0, int y0, int x1, int y1) {
	int dx = x0 - x1;
	int dy = y1 - y0;
	if (y0 > y1) {
		dx *= -1;
		dy *= -1;
	}
	if (((y < y0) != (y < y1))) {
		if (((dx == 0) && x <= x0) || (x - x0) * dy + dx * (y - y0) <= 0)
			return true;
	}
	return false;
}

bool Polygon_::checkInside(int x, int y)
{
	bool res = false;
	int sz = this->points.size();
	int j = sz - 1;
	int i = 0;
	int x1, x0 = this->points[j].getX();
	int y1, y0 = this->points[j].getY();
	for (; i < sz; ++i) {
		x1 = this->points[i].getX();
		y1 = this->points[i].getY();
		if (condition(x,y,x0,y0,x1,y1))
		{
			res = !res;
		}
		x0 = x1;
		y0 = y1;
	}
	return res;
}


