#ifndef __BoundingBox3D_h__
#define __BoundingBox3D_h__

#include "Vector3D.h"

class BoundingBox3D
{
protected:
	Vector3D p1;
	Vector3D p2;
public:
	BoundingBox3D();
	bool collides_with(const BoundingBox3D& other);
	void set_max_point(Vector3D point);
	void set_min_point(Vector3D point);
	void set_collider(Vector3D center, float size);
};

#endif