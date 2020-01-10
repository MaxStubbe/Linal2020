#include "Object3D.h"

Object3D::Object3D()
{
}

Object3D::Object3D(std::vector<Vector3D> points)
{
	std::copy(points.begin(), points.end(), points_.begin());
}

void Object3D::draw(SDL_Renderer& renderer)
{
	////convert points_ to sdl_points
	//std::vector<SDL_Point> sdl_points;
	//for (auto& point : points_) {
	//	sdl_points.push_back(point.get_sdl_point());
	//}
	//sdl_points.push_back(points_[0].get_sdl_point());

	////Set the color.
	//SDL_SetRenderDrawColor(&renderer, color_.r, color_.g, color_.b, SDL_ALPHA_OPAQUE);

	////Draw all the points.
	//SDL_RenderDrawLines(&renderer, &sdl_points[0], 5);
}

void Object3D::set_color(Color color)
{
	color_ = color;
}

void Object3D::do_matrix(const Matrix3D& matrix)
{
	for (auto& point : points_) {
		point = point * matrix;
	}
}
