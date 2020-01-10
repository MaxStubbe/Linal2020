#ifndef __Matrix3D_h__
#define __Matrix3D_h__
class Matrix3D
{
public:
	float matrix_[4][4] = {
		{1,0,0,0},
		{0,1,0,0},
		{0,0,1,0},
		{0,0,0,1}
	};
	Matrix3D();
	Matrix3D(float matrix[4][4]);
	Matrix3D operator+(const Matrix3D& other);
	Matrix3D operator-(const Matrix3D& other);
	Matrix3D operator*(const Matrix3D& other);
	Matrix3D operator*(const float& scalar);
	Matrix3D operator/(const float& scalar);
	float* operator[](int index);
};

#endif