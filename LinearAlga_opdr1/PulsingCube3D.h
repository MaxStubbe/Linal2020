#ifndef __PulsingCube3D_h__
#define __PulsingCube3D_h__

#include "Object3D.h"
#include "Timer.h"

class PulsingCube3D : public Object3D
{
private:
	Timer pulse_timer_ = Timer();
	Timer change_timer_ = Timer();
	int pulse_speed_;
	int change_interval_;
	bool scale_up_;
	Matrix3D matrix_;


public:
	PulsingCube3D(Camera3D& camera, Vector3D position = Vector3D(), int size = 10, int pulse_speed = 50, int change_interval = 500);
	void update() override;
};

#endif