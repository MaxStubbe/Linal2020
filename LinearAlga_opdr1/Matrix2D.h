#ifndef __Matrix2D_h__
#define __Matrix2D_h__

//#include "Vector2D.h"

class Matrix2D
{
public:
	float matrix_[3][3] = {
		{1,0,0},
		{0,1,0},
		{0,0,1}
	};
	Matrix2D();
	Matrix2D(float matrix[3][3]);
	Matrix2D operator+(const Matrix2D& other);
	Matrix2D operator-(const Matrix2D& other);
	Matrix2D operator*(const Matrix2D& other);
	Matrix2D operator*(const float& scalar);
	Matrix2D operator/(const float& scalar);
	float* operator[](int index);
};

#endif
