#include "Camera3D.h"

Camera3D::Camera3D(Vector3D position)
{
}

SDL_Point Camera3D::get_sdl_point(Vector3D point)
{
	Vector3D dir = get_direction().normalize();
	Vector3D right = up_.cross_product(dir).normalize();
	Vector3D up = dir.cross_product(right).normalize();
	float matrix[4][4] = {
		{right.x,right.y,right.z,-right.dot_product(position_)},
		{up.x,up.y,up.z,-up.dot_product(position_)},
		{dir.x,dir.y,dir.z,-up.dot_product(position_)},
		{0,0,0,1}
	};
	Matrix3D cam_matrix = Matrix3D(matrix);


	return {(int)(0),(int)(0)};
}

Vector3D Camera3D::get_direction()
{
	return position_ - lookat_;
}
