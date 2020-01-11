#include "Camera3D.h"
#include "Basic_Matrices.h"


Camera3D::Camera3D(Vector3D position)
{
}

void Camera3D::set_matrix()
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
	cam_matrix = Matrix3D(matrix);
}

SDL_Point Camera3D::get_sdl_point(Vector3D point)
{
	float screenSize = 100.0f;
	float near = 0.1f;
	float far = 1000.0f;
	float fov = 90.0f;
	float scale = near * tan(degrees_to_radians(fov) * 0.5f);
	float matrix[4][4] = {
		{scale,0,0,0},
		{0,scale,0,0},
		{0,0,((-far)/(far-near)),-1},
		{0,0,((-far*near)/(far-near)),0}
	};
	auto temp = point * cam_matrix;

	//naberekeningen
	if (temp.w > 0) {
		int x = (screenSize / 2) + ((temp.x + 1.0f) / temp.w) * screenSize * 0.5;

		int y = (screenSize / 2) + ((temp.y + 1.0f) / temp.w) * screenSize * 0.5;;
		return { x,y };
	}
	return { 0,0 };
}

Vector3D Camera3D::get_direction()
{
	return position_ - lookat_;
}

void Camera3D::rotate_x(float degrees)
{
	Vector3D dir = get_direction().normalize();
	Vector3D right = up_.cross_product(dir).normalize();
	Vector3D up = dir.cross_product(right).normalize();
	//move the points to the origin
	Vector3D point = lookat_ - position_;//Translate lookat to be relative to origin.
	Matrix3D matrix = get_rotation_matrix_3d_axis(up, degrees);

	lookat_ = (point * matrix) + position_;
}

void Camera3D::rotate_y(float degrees)
{
	Vector3D dir = get_direction().normalize();
	Vector3D right = up_.cross_product(dir).normalize();
	Vector3D up = dir.cross_product(right).normalize();

	Vector3D point = lookat_ - position_;//Translate lookat to be relative to origin.
	Matrix3D matrix = get_rotation_matrix_3d_axis(right, degrees);

	lookat_ = (point * matrix) + position_;
}

void Camera3D::rotate_z(float degrees)
{
	Vector3D dir = get_direction().normalize();
	Vector3D right = up_.cross_product(dir).normalize();
	Vector3D up = dir.cross_product(right).normalize();

	Vector3D point = up_ - position_;//Translate lookat to be relative to origin.
	Matrix3D matrix = get_rotation_matrix_3d_axis(dir, degrees);

	up_ = (point * matrix) + position_;

}
