#ifndef __Vector3D_h__
#define __Vector3D_h__

#include <cmath>
#include <SDL.h>
#include <SDL_main.h>
#include "Matrix3D.h"

class Vector3D
{
public:

	float x;
	float y;
	float z;
	Vector3D();
	Vector3D(float x1, float y1, float z1);
	Vector3D(const Vector3D& p2);
	SDL_Point get_sdl_point();
	Vector3D operator+(const Vector3D& other);
	Vector3D operator-(const Vector3D& other);
	Vector3D operator*(const float scalar);
	Vector3D operator*(const Matrix3D& other);
};

#endif