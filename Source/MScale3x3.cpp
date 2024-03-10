#include "MScale3x3.h"

MScale3x3::MScale3x3(float sx, float sy):Matrix(3,3)
{
	vector<float> tmp= { sx,0,0, 0,sy,0, 0,0,1 };
	Matrix::setMatrix(tmp);
}
