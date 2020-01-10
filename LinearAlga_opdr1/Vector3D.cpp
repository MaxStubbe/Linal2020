#include "Vector3D.h"

Vector3D::Vector3D()
{
	x = 0;
	y = 0;
	z = 0;
}

Vector3D::Vector3D(float x1, float y1, float z1)
{
	x = x1;
	y = y1;
	z = z1;
}

Vector3D::Vector3D(const Vector3D& p2)
{
	x = p2.x;
	y = p2.y;
	z = p2.z;
}

SDL_Point Vector3D::get_sdl_point()
{
	throw "Not Implementeded";
	return SDL_Point();
}

Vector3D Vector3D::operator+(const Vector3D& other)
{
	Vector3D vec;
	vec.x = x + other.x;
	vec.y = y + other.y;
	vec.z = z + other.z;
	return vec;
}

Vector3D Vector3D::operator-(const Vector3D& other)
{
	Vector3D vec;
	vec.x = x - other.x;
	vec.y = y - other.y;
	vec.z = z - other.z;
	return vec;
}

Vector3D Vector3D::operator*(const float scalar)
{
	Vector3D vec;
	vec.x = x * scalar;
	vec.y = y * scalar;
	vec.z = z * scalar;
	return vec;
}

Vector3D Vector3D::operator*(const Matrix3D& other)
{
	float other_vector[4] = { x, y,z, 1 };
	float vector_[4] = { 0,0,0,0 };
	//For each row
	for (int row = 0; row < 4; ++row) {
		for (int size = 0; size < 4; ++size) {
			vector_[row] += (other.matrix_[row][size] * other_vector[size]);
		}
	}
	return Vector3D(vector_[0], vector_[1],vector_[2]);
}
