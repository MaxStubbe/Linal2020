#ifndef __AidLine3D_h__
#define __AidLine3D_h__

#include "Object3D.h"

class AidLine3D : public Object3D
{
public:
	AidLine3D(Camera3D& camera);
	void update() override;
};

#endif