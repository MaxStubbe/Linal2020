#ifndef __Vector3D_h__
#define __Vector3D_h__

#include <cmath>
#include <SDL.h>
#include <SDL_main.h>
#include "Matrix.h"

class Vector3D
{
public:

	float x;
	float y;
	float z;
	const int WINDOWWIDTH = 640;
	const int WINDOWHEIGHT = 480;

	Vector3D() {
		this->x = 0;
		this->y = 0;
		this->z = 0;
	};
	Vector3D(float x1, float y1, float z1 = 1) {
		this->x = x1;
		this->y = y1;
		this->z = z1;
	};
	Vector3D operator+(const Vector3D& other)
	{
		Vector3D vec;
		vec.x = x + other.x;
		vec.y = y + other.y;
		vec.z = z + other.z;
		return vec;
	};
	Vector3D operator-(const Vector3D& other)
	{
		Vector3D vec;
		vec.x = x - other.x;
		vec.y = y - other.y;
		vec.z = z - other.z;
		return vec;
	};
	Vector3D operator*(const float scalair) {
		Vector3D vec;
		vec.x = x * scalair;
		vec.y = y * scalair;
		vec.z = z * scalair;
		return vec;
	};
	Vector3D operator*(const Matrix& other)
	{
		float newX;
		float newY;
		float newZ;

		if (other.collumns >= 2) {
			newX = ((other.x[0] * x) + (other.x[1] * y));
			newY = ((other.y[0] * x) + (other.y[1] * y));
			newZ = ((other.z[0] * x) + (other.z[1] * y));
			if (other.collumns > 3) {
				newX += (x * other.x[2]);
				newY += (y * other.y[2]);
				newZ += (z * other.z[2]);
			}

			return Vector3D(newX, newY, newZ);
		}
		else {
			throw "Matrix and Vector can't multiply";
		}
	};
};

#endif