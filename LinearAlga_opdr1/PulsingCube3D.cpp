#include "PulsingCube3D.h"
#include "Basic_Matrices.h"

PulsingCube3D::PulsingCube3D(Camera3D& camera, Vector3D position, int size, int pulse_speed) : Object3D(camera, position), pulse_speed_(pulse_speed)
{
	center_ = Vector3D(size/2.0,size/2.0,size/2.0);

	std::vector<Vector3D> front = {
		Vector3D(0, 0, 0),
		Vector3D(size, 0, 0),
		Vector3D(size, size , 0),
		Vector3D(0, size, 0)
	};
	points_.push_back(front);

	std::vector<Vector3D> back = {
		Vector3D(0, 0, size),
		Vector3D(size, 0, size),
		Vector3D(size, size , size),
		Vector3D(0, size, size)
	};
	points_.push_back(back);

	std::vector<Vector3D> left = {
		Vector3D(0, 0, size),
		Vector3D(0, 0, 0),
		Vector3D(0, size, 0),
		Vector3D(0, size, size)
	};
	points_.push_back(left);

	std::vector<Vector3D> right = {
		Vector3D(size, 0, size),
		Vector3D(size, 0, 0),
		Vector3D(size, size, 0),
		Vector3D(size, size, size)
	};
	points_.push_back(right);

	std::vector<Vector3D> top = {
		Vector3D(0, 0, size),
		Vector3D(size, 0, size),
		Vector3D(size, 0, 0),
		Vector3D(0, 0, 0)
	};
	points_.push_back(top);

	std::vector<Vector3D> bottom = {
		Vector3D(0, size, size),
		Vector3D(size, size, size),
		Vector3D(size, size, 0),
		Vector3D(0, size, 0)
	};
	points_.push_back(bottom);

	scale_up_ = false;
}

void PulsingCube3D::update()
{
	if (!pulse_timer_.is_running()) {
		pulse_timer_.start();
	}

	if (pulse_timer_.get_ticks() >= pulse_speed_) {
		if (scale_up_) {
			current_scale_ = current_scale_ + Vector3D(0.01,0.01,0.01);
		}
		else {
			current_scale_ = current_scale_ - Vector3D(0.01, 0.01, 0.01);
		}
		scale_ = current_scale_;
		pulse_timer_.reset();
	}

	if (current_scale_.x >= 1 || current_scale_.x <= 0.1) {
		scale_up_ = !scale_up_;
	}
}
