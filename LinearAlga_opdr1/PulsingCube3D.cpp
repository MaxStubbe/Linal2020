#include "PulsingCube3D.h"
#include "Basic_Matrices.h"

PulsingCube3D::PulsingCube3D(Camera3D& camera, Vector3D position, int size, int pulse_speed, int change_interval) : Object3D(camera, position), pulse_speed_(pulse_speed), change_interval_(change_interval)
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

	matrix_ = get_scale_matrix_3d(0.9);
	scale_up_ = false;
}

void PulsingCube3D::update()
{
	do_matrix(get_rotation_matrix_3d_axis(Vector3D(1, 0, 0), 0.1));
	/*if (!pulse_timer_.is_running()) {
		pulse_timer_.start();
	}
	if (!change_timer_.is_running()) {
		change_timer_.start();
	}


	if (pulse_timer_.get_ticks() >= pulse_speed_) {
		do_matrix(matrix_);
		pulse_timer_.reset();
	}

	if (change_timer_.get_ticks() >= change_interval_) {
		if (scale_up_) {
			matrix_ = get_scale_matrix_3d(0.9);
			scale_up_ = false;
		}
		else {
			matrix_ = get_scale_matrix_3d(1.1);
			scale_up_ = true;
		}
		change_timer_.reset();
	}*/
}
