#ifndef __SpaceShip3D_h__
#define __SpaceShip3D_h__

#include "Object3D.h"

class SpaceShip3D : public Object3D
{
private:

public:
	SpaceShip3D(Camera3D& camera, Vector3D position = Vector3D());
	void update() override;
};

#endif