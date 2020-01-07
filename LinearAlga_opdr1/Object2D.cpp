#include "Object2D.h"

Object2D::Object2D()
{
}

Object2D::Object2D(std::vector<Vector2D> points)
{
	//copy all points from points into points_.
	std::copy(points.begin(),points.end() , points_.begin());
}

void Object2D::draw(SDL_Renderer& renderer)
{
	//convert points_ to sdl_points
	std::vector<SDL_Point> sdl_points;
	for (auto& point : points_) {
		sdl_points.push_back(point.get_sdl_point());
	}
	sdl_points.push_back(points_[0].get_sdl_point());

	//Set the color.
	SDL_SetRenderDrawColor(&renderer, color_.r, color_.g, color_.b, SDL_ALPHA_OPAQUE);

	//Draw all the points.
	SDL_RenderDrawLines(&renderer, &sdl_points[0], 5);
}

void Object2D::set_color(Color color)
{
	//Set the color of this object.
	color_ = color;
}

void Object2D::do_matrix(const Matrix2D& matrix)
{
	for (auto& point : points_) {
		point = point * matrix;
	}
}
