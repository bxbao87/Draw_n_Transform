#include "MRotate3x3.h"

MRotate3x3::MRotate3x3(float deg):Matrix(3,3)
{
	vector<float> tmp = { 
		cosf(deg),sinf(deg),0, 
		-sinf(deg),cosf(deg),0, 
		0,0,1 };
	Matrix::setMatrix(tmp);
}
