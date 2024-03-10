#include "Matrix.h"

Matrix::Matrix(int r=3, int c=3) {
	this->row = r;
	this->col = c;
	this->mat.resize(r*c);
	for (int i = 0; i < r * c; ++i)
		this->mat[i] = 0;
}

bool Matrix::setMatrix(vector<float> nums)
{
	if (nums.size() == this->row * this->col) {
		this->mat = nums;
		return true;
	}
	return false;
}

Matrix Matrix::multiply(Matrix matA)
{
	if (this->col == matA.row) {
		Matrix res(this->row, matA.col);

		for (int i = 0; i < this->row; ++i) {
			for (int j = 0; j < matA.col; ++j) {
				for (int k = 0; k < this->col; ++k) {
					res.mat[i * this->col + j] +=
						this->mat[i * this->col + k] * matA.mat[j + k * matA.col];
				}
			}
		}
		return res;
	}
	return *this;
}


float Matrix::getX()
{
	return this->mat[0];
}


float Matrix::getY()
{
	return this->mat[1];
}
