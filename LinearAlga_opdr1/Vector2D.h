#ifndef __Vector2D_h__
#define __Vector2D_h__

#include <cmath>
#include <SDL.h>
#include <SDL_main.h>
#include "Camera.h"
#include "Matrix2D.h"

class Vector2D
{
public:
	float x;
	float y;
	Vector2D();
	Vector2D(float x1, float y1);
	Vector2D(const Vector2D& p2);
	SDL_Point get_sdl_point();
	Vector2D operator+(const Vector2D& other);
	Vector2D operator-(const Vector2D& other);
	Vector2D operator*(const float scalair);	
	Vector2D operator*(const Matrix2D& other);
};

#endif