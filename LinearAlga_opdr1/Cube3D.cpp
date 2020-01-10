#include "Cube3D.h"

Cube3D::Cube3D(Camera3D& camera, int size) : Object3D(camera)
{
	//Side 1: front
	std::vector<Vector3D> side_1 = {
		Vector3D(0, 0, 0),
		Vector3D(0, size, 0),
		Vector3D(size, size , 0),
		Vector3D(size, 0, 0)
	};
	points_.push_back(side_1);

	//Side 2: top
	std::vector<Vector3D> side_2 = {
		Vector3D(0, 0, 0),
		Vector3D(0, size, 0),
		Vector3D(0, size , size),
		Vector3D(0, 0, size)
	};
	points_.push_back(side_2);
}

void Cube3D::update()
{

}