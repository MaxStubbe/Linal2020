#include "Camera2D.h"
#include <SDL_rect.h>

Camera2D::Camera2D(Vector2D position)
{
	position_ = position;
}

SDL_Point Camera2D::get_sdl_point(Vector2D point)
{
	return { 
		(int)(point.x - position_.x), 
		(int)(point.y - position_.y) 
	};
}
