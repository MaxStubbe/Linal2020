#ifndef __Cube3D_h__
#define __Cube3D_h__

#include "Object3D.h"

class Cube3D : public Object3D
{
public:
	Cube3D(Camera3D& camera, int size);
	void update() override;
};

#endif