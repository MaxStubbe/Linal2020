#include "Matrix3D.h"

float* Matrix3D::operator[](int index)
{
	return matrix_[index];
}

Matrix3D Matrix3D::inverse()
{
	//TODO
	return Matrix3D();
}

Matrix3D::Matrix3D()
{
}

Matrix3D::Matrix3D(float matrix[4][4])
{
	for (int row = 0; row < 4; ++row) {
		for (int collum = 0; collum < 4; ++collum) {
			matrix_[row][collum] = matrix[row][collum];
		}
	}
}

Matrix3D Matrix3D::operator+(const Matrix3D& other)
{
	Matrix3D matrix;
	//For each row
	for (int i = 0; i < 4; ++i) {
		//For each item in the row
		for (int j = 0; j < 4; ++j) {
			//Add
			matrix[i][j] = matrix_[i][j] + other.matrix_[i][j];
		}
	}
	return matrix;
}

Matrix3D Matrix3D::operator-(const Matrix3D& other)
{
	Matrix3D matrix;
	//For each row
	for (int i = 0; i < 4; ++i) {
		//For each item in the row
		for (int j = 0; j < 4; ++j) {
			//Subtract.
			matrix[i][j] = matrix_[i][j] - other.matrix_[i][j];
		}
	}
	return matrix;
}

Matrix3D Matrix3D::operator*(const Matrix3D& other)
{
	Matrix3D matrix;
	//For each row
	for (int row = 0; row < 4; ++row) {

		//For each item in the row
		for (int collum = 0; collum < 4; ++collum) {

			for (int size = 0; size < 4; ++size) {
				matrix[row][collum] += (matrix_[row][size] * other.matrix_[size][collum]);
			}
		}
	}
	return matrix;
}

Matrix3D Matrix3D::operator*(const float& scalar)
{
	Matrix3D matrix;
	//For each row
	for (int i = 0; i < 4; ++i) {
		//For each item in the row
		for (int j = 0; j < 4; ++j) {
			//Multiply.
			matrix[i][j] = matrix_[i][j] * scalar;
		}
	}
	return matrix;
}

Matrix3D Matrix3D::operator/(const float& scalar)
{
	Matrix3D matrix;
	//For each row
	for (int i = 0; i < 4; ++i) {
		//For each item in the row
		for (int j = 0; j < 4; ++j) {
			//Divide.
			matrix[i][j] = matrix_[i][j] / scalar;
		}
	}
	return matrix;
}
