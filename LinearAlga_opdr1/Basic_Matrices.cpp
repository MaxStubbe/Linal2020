#include "Basic_Matrices.h"
#include <SDL_stdinc.h>
#include <cmath>

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