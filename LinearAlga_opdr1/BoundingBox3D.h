#ifndef __BoundingBox3D_h__
#define __BoundingBox3D_h__

#include "Object3D.h"

class BoundingBox3D
{
	Object3D& object_;
	float radius_;
public:
	BoundingBox3D(Object3D& object);
	bool collides_with(const BoundingBox3D& other);
};

#endif