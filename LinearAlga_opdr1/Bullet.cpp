#include "Bullet.h"
#include "Scene3D.h"

Bullet::Bullet(Scene3D* scene, Vector3D position, Vector3D rotation, float size, float speed_) : Object3D(scene->getCamera(), position), speed_(speed_), scene_(scene)
{
	center_ = Vector3D(size / 2.0, size / 2.0, size / 2.0);
	rotation_ = rotation;

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
}

void Bullet::update()
{
	position_ = position_ + (get_forward() * -speed_);

	if (!timer_.is_running()) {
		timer_.start();
	}

	if (timer_.get_ticks() >= 1000) {
		scene_->delete_object(this);
	}

	collider_.set_collider(center_ + position_, size_);
}

void Bullet::on_collision() {

}
