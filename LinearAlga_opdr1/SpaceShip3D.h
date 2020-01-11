#ifndef __SpaceShip3D_h__
#define __SpaceShip3D_h__

#include "Object3D.h"
#include "Scene3D.h"

class SpaceShip3D : public Object3D
{
private:

public:
	SpaceShip3D(Camera3D& camera, Vector3D position = Vector3D());
	void forward();
	void back();
	void up();
	void down();
	void left();
	void right();
	void rollleft();
	void rollright();
	void shoot(Scene3D* scene);
	void update() override;
};

#endif