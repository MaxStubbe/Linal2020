#include "Object2D.h"

Object2D::Object2D(Camera2D& camera) : camera_(camera)
{
}

Object2D::Object2D(Camera2D& camera, std::vector<Vector2D> points) : camera_(camera)
{
	std::copy(points.begin(),points.end() , points_.begin());
}

void Object2D::draw(SDL_Renderer& renderer)
{
	//convert points_ to sdl_points
	std::vector<SDL_Point> sdl_points;
	for (auto& point : points_) {
		sdl_points.push_back(camera_.get_sdl_point(point));
	}
	sdl_points.push_back(camera_.get_sdl_point(points_[0]));

	//Set the color.
	SDL_SetRenderDrawColor(&renderer, color_.r, color_.g, color_.b, SDL_ALPHA_OPAQUE);

	//Draw all the points.
	SDL_RenderDrawLines(&renderer, &sdl_points[0], 5);
}

void Object2D::set_color(Color color)
{
	color_ = color;
}

void Object2D::do_matrix(const Matrix2D& matrix)
{
	for (auto& point : points_) {
		point = point * matrix;
	}
}
