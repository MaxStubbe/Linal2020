#ifndef __Vector2D_h__
#define __Vector2D_h__

#include <cmath>
#include <SDL.h>
#include <SDL_main.h>
#include "Matrix.h"
#include "Camera.h"

class Vector2D
{
public:

	float x;
	float y;
	const int WINDOWWIDTH = 640;
	const int WINDOWHEIGHT = 480;

	Vector2D() {
		this->x = 0;
		this->y = 0;
	};
	Vector2D(float x1, float y1) {
		this->x = x1;
		this->y = y1;
	};
	SDL_Point getPoint(Camera* camera) {
		return { (int)this->x + camera->x , camera->y - (int)this->y };
		//return { (int) this->x + (WINDOWWIDTH/2) , (WINDOWHEIGHT/2) - (int) this->y };
	};
	Vector2D operator+(const Vector2D& other)
	{
		Vector2D vec;
		vec.x = x + other.x;
		vec.y = y + other.y;
		return vec;
	};
	Vector2D operator-(const Vector2D& other)
	{
		Vector2D vec;
		vec.x = x - other.x;
		vec.y = y - other.y;
		return vec;
	};
	Vector2D operator*(const float scalair) {
		Vector2D vec;
		vec.x = x * scalair;
		vec.y = y * scalair;
		return vec;
	};
	Vector2D operator*(const Matrix& other)
	{
		float newX;
		float newY;

		if (other.collumns >= 1) {
			newX = ((other.x[0] * x) + (other.x[1] * y));
			newY = ((other.y[0] * x) + (other.y[1] * y));
			if (other.collumns > 2) {
				newX += (x * other.x[2]);
				newY += (y * other.y[2]);
			}

			return Vector2D(newX, newY);
		}
		else {
			throw "Matrix and Vector can't multiply";
		}
	};
};

#endif