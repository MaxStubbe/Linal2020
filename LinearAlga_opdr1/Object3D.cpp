#include "Object3D.h"

Object3D::Object3D(Camera3D& camera) : camera_(camera)
{
}

Object3D::Object3D(Camera3D& camera, std::vector<std::vector<Vector3D>> points) : camera_(camera)
{
	std::copy(points.begin(), points.end(), points_.begin());//TODO: check of dit goed gaat.
}

void Object3D::draw(SDL_Renderer& renderer)
{
	for (auto& points : points_) {
		std::vector<SDL_Point> sdl_points;
		for (auto& point : points) {
			sdl_points.push_back(camera_.get_sdl_point(point));
		}
		sdl_points.push_back(camera_.get_sdl_point(points[0]));

		//Set the color.
		SDL_SetRenderDrawColor(&renderer, color_.r, color_.g, color_.b, SDL_ALPHA_OPAQUE);

		//Draw all the points.
		SDL_RenderDrawLines(&renderer, &sdl_points[0], 5);
	}
}

void Object3D::set_color(Color color)
{
	color_ = color;
}

void Object3D::do_matrix(const Matrix3D& matrix)
{
	for (auto& points : points_) {
		for (auto& point : points) {
			point = point * matrix;
		}
	}
}
