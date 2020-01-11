#include "AidLine3D.h"

AidLine3D::AidLine3D(Camera3D& camera,Vector3D p1, Vector3D p2) : Object3D(camera,Vector3D())
{
	std::vector<Vector3D> line = {
		Vector3D(p1.x, p1.y, p1.z),
		Vector3D(p2.x, p2.y, p2.z)
	};
	points_.push_back(line);
}

void AidLine3D::update()
{
}
