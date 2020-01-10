#ifndef __Cube2D_h__
#define __Cube2D_h__

#include "Object2D.h"

class Cube2D : public Object2D
{
public:
	Cube2D(Camera2D& camera, int size);
	void update() override;
};

#endif