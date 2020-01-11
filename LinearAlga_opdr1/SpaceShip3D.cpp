#include "SpaceShip3D.h"
#include "Basic_Matrices.h"

SpaceShip3D::SpaceShip3D(Camera3D& camera, Vector3D position) : Object3D(camera, position)
{
	color_.b = 0;
	color_.g = 0;
	color_.r = 255;

	int size = 1;

	center_ = Vector3D(size / 2.0, size / 2.0, size / 2.0);

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

void SpaceShip3D::forward()
{
	position_ = position_ +  (get_forward() * -0.2);
}

void SpaceShip3D::back()
{
	position_ = position_ + (get_forward() * 0.2);
}

void SpaceShip3D::up()
{
	rotation_.z += 5;
}

void SpaceShip3D::down()
{
	rotation_.z -= 5;
}

void SpaceShip3D::left()
{
	rotation_.y += 5;
}

void SpaceShip3D::right()
{
	rotation_.y -= 5;
}

void SpaceShip3D::rollleft()
{
	rotation_.x += 5;
}

void SpaceShip3D::rollright()
{
	rotation_.x -= 5;
}

void SpaceShip3D::shoot()
{
}

void SpaceShip3D::update()
{
}
