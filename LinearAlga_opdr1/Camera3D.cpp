#include "Camera3D.h"
#include "Basic_Matrices.h"


Camera3D::Camera3D(Vector3D position)
{
}

void Camera3D::set_matrix()
{
	//Calculate Camera Matrix
	Vector3D dir = get_direction().normalize();
	Vector3D right = up_.cross_product(dir).normalize();
	Vector3D up = dir.cross_product(right).normalize();
	float camera_matrix[4][4] = {
		{right.x,right.y,right.z,-right.dot_product(position_)},
		{up.x,up.y,up.z,-up.dot_product(position_)},
		{dir.x,dir.y,dir.z,-up.dot_product(position_)},
		{0,0,0,1}
	};
	cam_matrix = Matrix3D(camera_matrix);


	//Calculate Projection Matrix
	float near = 0.001f;
	float far = 10000.0f;
	float fov = 90.0f;
	float scale = near * tan(fov * 0.5f);

	//Projectie Matrix
	float projection_matrix[4][4] = {
		{scale,0,0,0},
		{0,scale,0,0},
		{0,0,((-far) / (far - near)),-1},
		{0,0,((-far * near) / (far - near)),0}
	};
	pro_matrix = Matrix3D(projection_matrix);
}

SDL_Point Camera3D::get_sdl_point(Vector3D point)
{
	//Screen Size
	float screenSize = 60.0f;

	//Haal punt langs camera matrix. => Orthographic 
	Vector3D ortho_point = point * cam_matrix;

	//Haal punt langs projectie matrix. => Perspectief
	Vector3D canvas_point = ortho_point;// *pro_matrix;

	//Naberekingen
	if (canvas_point.w != 0) {
		int x = (screenSize / 2) + ((canvas_point.x) / canvas_point.w) * (screenSize / canvas_point.w);

		int y = (screenSize / 2) + ((canvas_point.y) / canvas_point.w) * (screenSize / canvas_point.w);
		
		int z = -canvas_point.z;

		int w = 1;

		//test = Vector3D(x, y, z, w);

		//Vector3D ortho_point = test * cam_matrix;

		//return { (int)ortho_point.x,(int)ortho_point.y };
		return { (int)x,(int)y };
	}
	//Als hepunt niet getekent hoeft te worden.
	throw "No drawn needed";
}

Vector3D Camera3D::get_direction()
{
	return position_ - lookat_;
}

void Camera3D::move_x(float step)
{
	Vector3D dir = get_direction().normalize();//z
	Vector3D right = up_.cross_product(dir).normalize();//x
	Vector3D up = dir.cross_product(right).normalize();//y
	Matrix3D matrix = get_move_matrix_3d(right*step);

	lookat_ = lookat_ * matrix;
	position_ = position_ * matrix;
}

void Camera3D::move_y(float step)
{
	Vector3D dir = get_direction().normalize();//z
	Vector3D right = up_.cross_product(dir).normalize();//x
	Vector3D up = dir.cross_product(right).normalize();//y
	Matrix3D matrix = get_move_matrix_3d(up * step);

	lookat_ = lookat_ * matrix;
	position_ = position_ * matrix;
}

void Camera3D::move_z(float step)
{
	Vector3D dir = get_direction().normalize();//z
	Vector3D right = up_.cross_product(dir).normalize();//x
	Vector3D up = dir.cross_product(right).normalize();//y
	Matrix3D matrix = get_move_matrix_3d(dir * step);

	lookat_ = lookat_ * matrix;
	position_ = position_ * matrix;
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

//TODO: This one doesn't work well
void Camera3D::rotate_z(float degrees)
{
	Vector3D dir = get_direction().normalize();
	Vector3D right = up_.cross_product(dir).normalize();
	Vector3D up = dir.cross_product(right).normalize();

	Vector3D point = up_ - position_;//Translate lookat to be relative to origin.
	Matrix3D matrix = get_rotation_matrix_3d_axis(dir, degrees);

	up_ = (point * matrix) + position_;

}
