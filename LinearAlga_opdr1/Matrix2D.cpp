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
			//Add
			matrix[i][j] = matrix_[i][j] + other.matrix_[i][j];
		}
	}
	return matrix;
}

Matrix2D Matrix2D::operator-(const Matrix2D& other)
{
	Matrix2D matrix;
	//For each row
	for (int i = 0; i < 3; ++i) {
		//For each item in the row
		for (int j = 0; j < 3; ++j) {
			//Subtract.
			matrix[i][j] = matrix_[i][j] - other.matrix_[i][j];
		}
	}
	return matrix;
}

Matrix2D Matrix2D::operator*(const Matrix2D& other)
{
	Matrix2D matrix;
	/*
	( A1, B1, C1 )   ( 1A, 2A, 3A )   ( (A1*1A + B1*1B + C1*1C), (A1*2A + B1*2B + C1*2C), (A1*3A + B1*3B + C1*3C) )
	( A2, B2, C2 ) * ( 1B, 2B, 3B ) = ( (A2*1A + B2*1B + C2*1C), (A2*2A + B2*2B + C2*2C), (A2*3A + B2*3B + C2*3C) )
	( A3, B3, C3 )   ( 1C, 2C, 3C )   ( (A3*1A + B3*1B + C3*1C), (A3*2A + B3*2B + C3*2C), (A3*3A + B3*3B + C3*3C) )
	*/

	//For each row
	for (int row = 0; row < 3; ++row) {

		//For each item in the row
		for (int collum = 0; collum < 3; ++collum) {

			for (int size = 0; size < 3; ++size) {
				matrix[row][collum] += (matrix_[row][size] * other.matrix_[size][collum]);
			}
		}
	}
	return matrix;
}

Matrix2D Matrix2D::operator*(const float& scalar)
{
	Matrix2D matrix;
	//For each row
	for (int i = 0; i < 3; ++i) {
		//For each item in the row
		for (int j = 0; j < 3; ++j) {
			//Multiply.
			matrix[i][j] = matrix_[i][j] * scalar;
		}
	}
	return matrix;
}

Matrix2D Matrix2D::operator/(const float& scalar)
{
	Matrix2D matrix;
	//For each row
	for (int i = 0; i < 3; ++i) {
		//For each item in the row
		for (int j = 0; j < 3; ++j) {
			//Divide.
			matrix[i][j] = matrix_[i][j] / scalar;
		}
	}
	return matrix;
}

float* Matrix2D::operator[](int index)
{
	return matrix_[index];
}
