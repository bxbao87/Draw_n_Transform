#ifndef MATRIX_H
#define MATRIX_H

#include<iostream>
#include<math.h>
#include<cmath>
#include<GL\glew.h>
#include<GL\freeglut.h>
#include<Windows.h>
#include<vector>
using namespace std;

class Matrix {
protected:
	int row, col;
	vector<float> mat;

public:
	Matrix(int r, int c);
	bool setMatrix(vector<float> nums);
	Matrix multiply(Matrix matA);
	float getX();
	float getY();
};


#endif // !MATRIX_H
