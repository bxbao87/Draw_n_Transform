#ifndef LINE_H
#define LINE_H

#include"SObject.h"

class Line : public SObject {
private:
	Point endpoint;
	Matrix transformMatrix;
public:
	Line(Point s);
	void done();
	void updateCanvas(Canvas& canvas, int val);
	void rotate(Canvas& canvas, int deg);
	void translate(Canvas& canvas, int x, int y);
	void scale(Canvas& canvas, int mag);
	bool checkInside(int x, int y);
};


#endif // !LINE_H

