#ifndef __AidLine3D_h__
#define __AidLine3D_h__

#include "Object3D.h"

class AidLine3D : public Object3D
{
public:
	AidLine3D(Camera3D& camera, Vector3D p1, Vector3D p2);
	void update() override;
	void on_collision() override;
};

#endif