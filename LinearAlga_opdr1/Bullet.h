#ifndef __PulsingCube3D_h__
#define __PulsingCube3D_h__

#include "Object3D.h"
#include "Timer.h"
#include "Scene3D.h"

class Bullet : public Object3D
{
private:
	Timer timer_ = Timer();
	float speed_;
	Scene3D* scene_;
	int time_ = 0;


public:
	Bullet(Scene3D* scene, Vector3D position, Vector3D rotation, float size = 1, float speed_ = 0.5);
	void update() override;
};

#endif


