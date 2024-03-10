#include "MTranslate3x3.h"

MTranslate3x3::MTranslate3x3(float x, float y):Matrix(3,3)
{
	vector<float> tmp = { 1.0,0.0,0.0, 0.0,1.0,0.0, x,y,1.0 };
	Matrix::setMatrix(tmp);
}
