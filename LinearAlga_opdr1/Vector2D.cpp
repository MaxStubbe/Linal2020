#include "Vector2D.h"

Vector2D::Vector2D() {
	x = 0;
	y = 0;
}

Vector2D::Vector2D(float x1, float y1) {
	x = x1;
	y = y1;
}

Vector2D::Vector2D(const Vector2D& p2) {
	x = p2.x;
	y = p2.y;
}

SDL_Point Vector2D::get_sdl_point() {
	return { (int)x , (int)y };
}

Vector2D Vector2D::normalize()
{
	Vector2D vec;
	float mag = magnitude();
	vec.x = x / mag;
	vec.y = y / mag;
	return vec;
}

float Vector2D::magnitude()
{
	return sqrt(((x * x) + (y * y)));
}

float Vector2D::dot_product(const Vector2D& other)
{
	return ((x * other.x) + (y * other.y));
}

Vector2D Vector2D::operator+(const Vector2D& other)
{
	Vector2D vec;
	vec.x = x + other.x;
	vec.y = y + other.y;
	return vec;
}

Vector2D Vector2D::operator-(const Vector2D& other)
{
	Vector2D vec;
	vec.x = x - other.x;
	vec.y = y - other.y;
	return vec;
}

Vector2D Vector2D::operator*(const float scalar) {
	Vector2D vec;
	vec.x = x * scalar;
	vec.y = y * scalar;
	return vec;
}

Vector2D Vector2D::operator*(const Matrix2D& other)
{
	float other_vector[3] = { x, y, 1 };
	float vector_[3] = { 0,0,0 };
	//For each row
	for (int row = 0; row < 3; ++row) {
		for (int size = 0; size < 3; ++size) {
			vector_[row] += (other.matrix_[row][size] * other_vector[size]);
		}
	}
	return Vector2D(vector_[0], vector_[1]);
}
