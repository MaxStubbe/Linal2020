#ifndef __SpaceShip3D_h__
#define __SpaceShip3D_h__

#include "Object3D.h"

class SpaceShip3D : public Object3D
{
private:

public:
	SpaceShip3D(Camera3D& camera, Vector3D position = Vector3D());
	void forward();
	void back();
	void left();
	void right();
	void rollleft();
	void rollright();
	void update() override;
};

#endif