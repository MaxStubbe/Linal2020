#ifndef __Camera3D_h__
#define __Camera3D_h__

#include "Vector3D.h"

class Camera3D
{
public:
	Vector3D position_;

	Vector3D lookat_;

	Vector3D up_ = Vector3D(0, 1, 0);

	Matrix3D cam_matrix;

	Camera3D(Vector3D position);

	void set_matrix();

	SDL_Point get_sdl_point(Vector3D point);

	Vector3D get_direction();
};

#endif