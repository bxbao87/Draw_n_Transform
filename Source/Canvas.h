#ifndef CANVAS_H
#define CANVAS_H

#include"Point.h"

static bool inViewPort(int v, int range) {
	if (v >= 0 && v < range)
		return true;
	return false;
}

class Canvas {
private:
	vector<vector<int>> canvas;
	int w, h;

public:
	void initCanvas(int w, int h);
	void setPixel(int x, int y, int val=1);
	void updateToConsoleWindow();
};



#endif // !CANVAS_H
