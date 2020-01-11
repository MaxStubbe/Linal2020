#include "Object3D.h"

Object3D::Object3D(Camera3D& camera, Vector3D position) : camera_(camera), position_(position)
{
}

Object3D::Object3D(Camera3D& camera, Vector3D position, std::vector<std::vector<Vector3D>> points) : camera_(camera) , position_(position)
{
	std::copy(points.begin(), points.end(), points_.begin());
}

void Object3D::draw(SDL_Renderer& renderer)
{
	for (auto& points : points_) {
		std::vector<SDL_Point> sdl_points;
		for (auto& point : points) {
			try {
				sdl_points.push_back(camera_.get_sdl_point(point + position_));
			}
			catch(const char* msg) {
				//cerr << msg << endl;
			}
		}

		if (sdl_points.size() >= 1) {
			sdl_points.push_back(sdl_points[0]);
			//Set the color.
			SDL_SetRenderDrawColor(&renderer, color_.r, color_.g, color_.b, SDL_ALPHA_OPAQUE);

			//Draw all the points.
			SDL_RenderDrawLines(&renderer, &sdl_points[0], 5);
		}
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
			auto temp = point - center_;
			point = (temp * matrix) + center_;
		}
	}
}
