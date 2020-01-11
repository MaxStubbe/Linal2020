#ifndef __BASIC_MATRICES_h__
#define __BASIC_MATRICES_h__
#include "Matrix2D.h"
#include "Matrix3D.h"
#include "Vector3D.h"

float degrees_to_radians(float degrees);

float radians_to_degrees(float radians);

Matrix2D get_rotation_matrix_degrees(float degrees);

Matrix3D get_scale_matrix_3d(float scale);

Matrix3D get_rotation_matrix_3d_x(float degrees);

Matrix3D get_rotation_matrix_3d_y(float degrees);

Matrix3D get_rotation_matrix_3d_z(float degrees);

Matrix3D get_rotation_matrix_3d_axis(Vector3D axis, float degrees);

Matrix3D get_move_matrix_3d(Vector3D position);

Matrix3D get_null_matrix_3d();
#endif
