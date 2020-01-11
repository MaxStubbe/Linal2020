#include "Basic_Matrices.h"
#include <SDL_stdinc.h>
#include <cmath>
#include "Vector3D.h"

float degrees_to_radians(float degrees) {
	return degrees * M_PI / 180.0f;
}

float radians_to_degrees(float radians) {
	return radians * 180.0f / M_PI;
}

Matrix2D get_rotation_matrix_degrees(float degrees) {
	float matrix[3][3] = {
				{cos(degrees_to_radians(degrees)),-sin(degrees_to_radians(degrees)),0},
				{sin(degrees_to_radians(degrees)),cos(degrees_to_radians(degrees)),0},
				{0,0,1},
	};
	return Matrix2D(matrix);
}

Matrix3D get_scale_matrix_3d(float scale)
{
	return Matrix3D() * scale;
}

Matrix3D get_rotation_matrix_3d_x(float degrees)
{
	float rad = degrees_to_radians(degrees);
	float matrix[4][4] = {
				{1,0,0,0},
				{0,cos(rad),-sin(rad),0},
				{0,sin(rad),cos(rad),0},
				{0,0,0,1}
	};
	return Matrix3D(matrix);
}

Matrix3D get_rotation_matrix_3d_y(float degrees)
{
	float rad = degrees_to_radians(degrees);
	float matrix[4][4] = {
				{cos(rad),0,sin(rad),0},
				{0,1,0,0},
				{-sin(rad),0,cos(rad),0},
				{0,0,0,1}
	};
	return Matrix3D(matrix);
}

Matrix3D get_rotation_matrix_3d_z(float degrees)
{
	float rad = degrees_to_radians(degrees);
	float matrix[4][4] = {
				{cos(rad),-sin(rad),0,0},
				{sin(rad),cos(rad),0,0},
				{0,0,1,0},
				{0,0,0,1}
	};
	return Matrix3D(matrix);
}

Matrix3D get_rotation_matrix_3d_axis(Vector3D axis_, float degrees)
{
	Vector3D axis = axis_.normalize();
	float rad = degrees_to_radians(degrees);
	float matrix[4][4] = {
				{ (cos(rad)+((axis.x * axis.x)*(1-cos(rad)))), (((axis.x * axis.y)*(1 - cos(rad)))-(axis.z * sin(rad))), (((axis.x * axis.z)*(1-cos(rad)))+(axis.y*sin(rad))), 0},
				{ (((axis.y * axis.x) * (1 - cos(rad))) + (axis.z * sin(rad))),(cos(rad) + ((axis.y * axis.y) * (1 - cos(rad)))),(((axis.x * axis.z) * (1 - cos(rad))) - (axis.x * sin(rad))),0},
				{ (((axis.z * axis.x) * (1 - cos(rad))) - (axis.y * sin(rad))),(((axis.z * axis.y) * (1 - cos(rad))) + (axis.x * sin(rad))),(cos(rad) + ((axis.z * axis.z) * (1 - cos(rad)))),0},
				{0,0,0,1}
	};
	return Matrix3D(matrix);
}

Matrix3D get_move_matrix_3d(Vector3D position)
{
	float matrix[4][4] = {
				{1,0,0,position.x},
				{0,1,0,position.y},
				{0,0,1,position.z},
				{0,0,0,1}
	};
	return Matrix3D(matrix);
}

Matrix3D get_null_matrix_3d()
{
	float matrix[4][4] = {
		   {0,0,0,0},
		   {0,0,0,0},
		   {0,0,0,0},
		   {0,0,0,0}
	};
	return Matrix3D(matrix);
}
