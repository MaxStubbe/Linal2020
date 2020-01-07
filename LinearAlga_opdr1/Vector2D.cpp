#include "Vector2D.h"

Vector2D::Vector2D() {
	this->x = 0;
	this->y = 0;
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

Vector2D Vector2D::operator*(const float scalair) {
	Vector2D vec;
	vec.x = x * scalair;
	vec.y = y * scalair;
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
