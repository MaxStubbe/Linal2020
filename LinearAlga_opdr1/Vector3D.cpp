#include "Vector3D.h"

Vector3D::Vector3D()
{
	x = 0;
	y = 0;
	z = 0;
	w = 1;
}

Vector3D::Vector3D(float x1, float y1, float z1, float w1)
{
	x = x1;
	y = y1;
	z = z1;
	w = w1;
}

Vector3D::Vector3D(const Vector3D& p2)
{
	x = p2.x;
	y = p2.y;
	z = p2.z;
	w = p2.w;
}

Vector3D Vector3D::normalize()
{
	Vector3D vec;
	float mag = magnitude();
	vec.x = x / mag;
	vec.y = y / mag;
	vec.z = z / mag;
	return vec;
}

float Vector3D::magnitude()
{
	return sqrt(((x * x) + (y * y) + (z * z)));
}

Vector3D Vector3D::cross_product(const Vector3D& other)
{
	Vector3D vec;
	vec.x = ((y * other.z) - (z * other.y));
	vec.y = ((z * other.x) - (x * other.z));
	vec.z = ((x * other.y) - (y * other.x));
	return vec;
}

float Vector3D::dot_product(const Vector3D& other)
{
	return ((x * other.x) + (y * other.y) + (z * other.z));
}

Vector3D Vector3D::operator+(const Vector3D& other)
{
	Vector3D vec;
	vec.x = x + other.x;
	vec.y = y + other.y;
	vec.z = z + other.z;
	return vec;
}

bool Vector3D::operator==(const Vector3D& other)
{
	return (
		x == other.x &&
		y == other.y &&
		z == other.z &&
		w == other.w
		);
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

Vector3D Vector3D::operator/(const float scalar)
{
	Vector3D vec;
	vec.x = x / scalar;
	vec.y = y / scalar;
	vec.z = z / scalar;
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
	return Vector3D(vector_[0], vector_[1],vector_[2], vector_[3]);
}

Vector3D Vector3D::flip()
{
	return Vector3D(-x,-y,-z,-w);
}

float Vector3D::distance(const Vector3D& other)
{
	return sqrt((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y) + (z - other.z) * (z - other.z));
}

std::ostream& operator<<(std::ostream& os, const Vector3D& vector)
{
	os << " [ " << vector.x << " | " << vector.y << " | " << vector.z << " | " << vector.w << " ] ";
	return os;
}
