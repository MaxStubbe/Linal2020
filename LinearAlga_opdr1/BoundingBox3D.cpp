#include "BoundingBox3D.h"

BoundingBox3D::BoundingBox3D()
{
}

bool BoundingBox3D::collides_with(const BoundingBox3D& other)
{
	return (
		(p1.x <= other.p2.x && p2.x >= other.p1.x) &&
		(p1.y <= other.p2.y && p2.y >= other.p1.y) &&
		(p1.z <= other.p2.z && p2.z >= other.p1.z)
		);
}

void BoundingBox3D::set_max_point(Vector3D point)
{
	p2 = point;
}

void BoundingBox3D::set_min_point(Vector3D point)
{
	p1 = point;
}

void BoundingBox3D::set_collider(Vector3D center, float size)
{
	//update collider
	set_max_point(Vector3D(center.x + (size / 2), center.y + (size / 2), center.z + (size / 2)));
	set_min_point(Vector3D(center.x - (size / 2), center.y - (size / 2), center.z - (size / 2)));
}

