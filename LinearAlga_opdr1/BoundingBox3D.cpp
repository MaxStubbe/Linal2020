#include "BoundingBox3D.h"

BoundingBox3D::BoundingBox3D(Object3D& object): object_(object)
{
}

bool BoundingBox3D::collides_with(const BoundingBox3D& other)
{
	return (
		object_.center_.distance(other.object_.center_) <= (radius_ + other.radius_)
		);
}
