#include "Matrix2D.h"
#include <iostream>

Matrix2D::Matrix2D()
{
}

Matrix2D Matrix2D::operator+(const Matrix2D& other)
{
	Matrix2D matrix;
	//For each row
	for (int i = 0; i < 3; ++i) {
		//For each item in the row
		for (int j = 0; j < 3; ++j) {
			matrix[i][j] = this[i][j] + other[i][j];
		}
	}


	return matrix;
}

Matrix2D Matrix2D::operator-(const Matrix2D& other)
{
	return Matrix2D();
}

Matrix2D Matrix2D::operator*(const Matrix2D& other)
{
	return Matrix2D();
}

float* Matrix2D::operator[](int index)
{
	return matrix_[index];
}
