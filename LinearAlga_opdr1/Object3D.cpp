#include "Object3D.h"
#include "Basic_Matrices.h"

Object3D::Object3D(Camera3D& camera, Vector3D position) : camera_(camera), position_(position)
{
}

Object3D::Object3D(Camera3D& camera, Vector3D position, std::vector<std::vector<Vector3D>> points) : camera_(camera) , position_(position)
{
	std::copy(points.begin(), points.end(), points_.begin());
}

void Object3D::draw(SDL_Renderer& renderer)
{
	Matrix3D rot_x_mat = get_rotation_matrix_3d_axis(Vector3D(1, 0, 0), rotation_.x);

	Matrix3D rot_y_mat = get_rotation_matrix_3d_axis(Vector3D(0, 1, 0), rotation_.y);

	Matrix3D rot_z_mat = get_rotation_matrix_3d_axis(Vector3D(0, 0, 1), rotation_.z);

	Matrix3D scale_mat = get_scale_matrix_3d(scale_);

	for (auto& points : points_) {
		std::vector<SDL_Point> sdl_points;
		for (auto& point : points) {

			//Point to origin
			Vector3D origin_point = point - center_;

			//X rotation
			Vector3D rotated_point = origin_point * rot_x_mat;

			//Y Rotation
			rotated_point = rotated_point * rot_y_mat;

			//Z Rotation
			rotated_point = rotated_point * rot_z_mat;
			
			//Scale point.
			Vector3D scaled_point = rotated_point * scale_mat;

			//Transform point.
			Vector3D transformed_point = scaled_point + position_ + center_;

			try {
				sdl_points.push_back(camera_.get_sdl_point(transformed_point));
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

Vector3D Object3D::get_forward()
{
	Vector3D origin_point = Vector3D(1,0,0);

	//X rotation
	Vector3D rotated_point = origin_point * get_rotation_matrix_3d_axis(Vector3D(1, 0, 0), rotation_.x);

	//Y Rotation
	rotated_point = rotated_point * get_rotation_matrix_3d_axis(Vector3D(0, 1, 0), rotation_.y);

	//Z Rotation
	rotated_point = rotated_point * get_rotation_matrix_3d_axis(Vector3D(0, 0, 1), rotation_.z);

	return rotated_point;
}

bool Object3D::collides_with(const Object3D& other)
{
	return false;
}
