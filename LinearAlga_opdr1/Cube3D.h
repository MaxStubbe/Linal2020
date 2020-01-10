#ifndef __Cube3D_h__
#define __Cube3D_h__

#include "Object3D.h"

class Cube3D : public Object3D
{
public:
	Cube3D(Camera3D& camera, Vector3D position = Vector3D(), int size = 10);
	void update() override;
};

#endif