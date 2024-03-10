#include "Canvas.h"

void Canvas::initCanvas(int w, int h)
{
	this->w = w;
	this->h = h;
	vector<vector<int>> tmp(h, vector<int>(w, 0));
	this->canvas = tmp;
}

void Canvas::setPixel(int x, int y, int val)
{
	if (inViewPort(x, this->w) && inViewPort(y, this->h)) {
		this->canvas[y][x] += val;
	}
}


void Canvas::updateToConsoleWindow()
{
	glBegin(GL_POINTS);
	for (int i = 0; i < this->h; ++i) {
		for (int j = 0; j < this->w; ++j) {
			if (this->canvas[i][j] > 0)
				glColor3f(1.0f, 1.0f, 1.0f);
			else if (this->canvas[i][j] < 0)
				glColor3f(1.0f, 0.0f, 0.0f);
			else glColor3f(0.0f, 0.0f, 0.0f);
			glVertex2i(j, i);
		}
	}
	glEnd();
}
