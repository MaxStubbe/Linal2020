#include "Camera3D.h"

Camera3D::Camera3D(Vector3D position)
{
}

SDL_Point Camera3D::get_sdl_point(Vector3D point)
{




	return SDL_Point();
}

Vector3D Camera3D::get_direction()
{
	return position_ - lookat_;
}
