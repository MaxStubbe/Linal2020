#include "AidLine3D.h"

AidLine3D::AidLine3D(Camera3D& camera) : Object3D(camera,Vector3D())
{
	color_.b = 0;
	color_.g = 255;
	color_.r = 0;

	std::vector<Vector3D> front = {
		Vector3D(-100, 0, 0),
		Vector3D(100, 0, 0)
	};
	points_.push_back(front);

	std::vector<Vector3D> back = {
		Vector3D(0, -100, 0),
		Vector3D(0, 100, 0)
	};
	points_.push_back(back);

	std::vector<Vector3D> left = {
		Vector3D(0, 0, -100),
		Vector3D(0, 0, 100)
	};
	points_.push_back(left);

}

void AidLine3D::update()
{
}
