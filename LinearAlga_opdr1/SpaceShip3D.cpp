#include "SpaceShip3D.h"
#include "Basic_Matrices.h"
#include "Scene3D.h"
#include "Bullet.h"
#include <iostream>

SpaceShip3D::SpaceShip3D(Camera3D& camera, Vector3D position) : Object3D(camera, position)
{
	size_ = 1;

	color_.b = 0;
	color_.g = 0;
	color_.r = 255;

	int size = 1;

	rotation_.z = 180;

	center_ = Vector3D(size / 2.0, size / 2.0, size / 2.0);

	//Nose
	std::vector<Vector3D> nose_l = {
		Vector3D(size, 0, size),
		Vector3D(size, size, size),
		Vector3D(size+size, size / 2.0f , size / 2.0f)
	};
	points_.push_back(nose_l);

	std::vector<Vector3D> nose_r = {
		Vector3D(size, 0, 0),
		Vector3D(size, size, 0),
		Vector3D(size + size, size / 2.0f , size / 2.0f)
	};
	points_.push_back(nose_r);

	//Top Finn
	std::vector<Vector3D> fin = {
		Vector3D(size, size, size / 2.0f),
		Vector3D(0, size, size / 2.0f),
		Vector3D(0, size + (size / 2.0f), size / 2.0f),
		Vector3D(size, size + (size / 2.0f), size / 2.0f)
	};
	points_.push_back(fin);

	//Right Wing
	std::vector<Vector3D> wing_r = {
		Vector3D(size, size / 2.0f, 0),
		Vector3D(0, size / 2.0f, 0),
		Vector3D(0, size / 2.0f, -size)
	};
	points_.push_back(wing_r);

	//Right Wing
	std::vector<Vector3D> wing_l = {
		Vector3D(size, size / 2.0f, size),
		Vector3D(0, size / 2.0f, size),
		Vector3D(0, size / 2.0f, size+size)
	};
	points_.push_back(wing_l);

	//Body
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
	//position_ = position_ +  (get_forward() * 0.2);
	velocity_.x = velocity_.x + 0.002;
	if (velocity_.magnitude() > 1) {
		velocity_.x = 1;
	}
}

void SpaceShip3D::back()
{
	//position_ = position_ + (get_forward() * -0.2);
	velocity_.x = velocity_.x - 0.002;
	if (velocity_.magnitude() < 0) {
		velocity_ = Vector3D(0, 0, 0);
	}
}

void SpaceShip3D::up()
{
	rotation_.z += 5;
	rotation_.z = fmod(rotation_.z,360.0f);
	//do_rotation(get_rotation_matrix_3d_axis(Vector3D(0, 0, 1), 5));
}

void SpaceShip3D::down()
{
	rotation_.z -= 5;
	rotation_.z = fmod(rotation_.z, 360.0f);
	//do_rotation(get_rotation_matrix_3d_axis(Vector3D(0, 0, 1), -5));
}

void SpaceShip3D::left()
{
	rotation_.y += 5;
	rotation_.y = fmod(rotation_.y, 360.0f);
	//do_rotation(get_rotation_matrix_3d_axis(Vector3D(0, 1, 0), 5));
}

void SpaceShip3D::right()
{
	rotation_.y -= 5;
	rotation_.y = fmod(rotation_.y, 360.0f);
	//do_rotation(get_rotation_matrix_3d_axis(Vector3D(0, 1, 0), -5));
}

void SpaceShip3D::rollleft()
{
	rotation_.x += 5;
	rotation_.x = fmod(rotation_.x, 360.0f);
	//do_rotation(get_rotation_matrix_3d_axis(Vector3D(1, 0, 0), 5));
}

void SpaceShip3D::rollright()
{
	rotation_.x -= 5;
	rotation_.x = fmod(rotation_.x, 360.0f);
	//do_rotation(get_rotation_matrix_3d_axis(Vector3D(1, 0, 0), -5));
}

void SpaceShip3D::shoot(Scene3D* scene)
{
	Bullet* bullet = new Bullet(scene, position_+center_+(get_forward()), rotation_, 0.1, 0.01);
	bullet->set_color(blue());
	bullet->add_force(velocity_);
	scene->add_object(bullet);
}

void SpaceShip3D::update()
{
	collider_.set_collider(center_ + position_, size_);
}

void SpaceShip3D::on_collision()
{
	std::cout << "Collision!";
}
