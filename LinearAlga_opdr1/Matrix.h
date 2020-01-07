#ifndef __Matrix_h__
#define __Matrix_h__

#include <vector>

class Vector2D;

class Matrix
{
public:
	float rows;
	float collumns;
	std::vector<float> x;
	std::vector<float> y;
	std::vector<float> z;
	std::vector<float> w;
	std::vector<std::vector<float>> matrix;
	Matrix(std::vector<float> x, std::vector<float> y);
	Matrix(std::vector<float> x, std::vector<float> y, std::vector<float> z);
	Matrix(std::vector<float> x, std::vector<float> y, std::vector<float> z, std::vector<float> w);
	Matrix operator+(const Matrix& other);
	Matrix operator-(const Matrix& other);
	Matrix operator*(const Matrix& other);
	Vector2D operator*(const Vector2D& other);
};

#endif