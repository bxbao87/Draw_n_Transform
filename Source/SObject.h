#ifndef SOBJECT_H
#define SOBJECT_H

#include"Canvas.h"
#include"Matrix.h"
#include"MTranslate3x3.h"
#include"MScale3x3.h"
#include"MRotate3x3.h"

class SObject {
protected:
	Point src, dest;
public:
	SObject(Point s);
	virtual void done();
	virtual void updateDest(int x, int y);
	virtual void draw(Canvas& canvas);
	virtual void undraw(Canvas& canvas);
	virtual void redraw(Canvas& canvas);
	virtual void selected(Canvas& canvas);
	virtual void unselected(Canvas& canvas);
	virtual void updateCanvas(Canvas& canvas, int val);
	virtual void rotate(Canvas& canvas, int deg);
	virtual void translate(Canvas& canvas, int x, int y);
	virtual void scale(Canvas& canvas, int mag);
	virtual bool checkInside(int x, int y);
};


#endif // !SOBJECT_H
