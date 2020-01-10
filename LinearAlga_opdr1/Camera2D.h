#ifndef __Camera2D_h__
#define __Camera2D_h__

#include "Vector2D.h"

class Camera2D {
public:
	Vector2D position_;

	Camera2D(Vector2D position);

	SDL_Point get_sdl_point(Vector2D point);
};

#endif

