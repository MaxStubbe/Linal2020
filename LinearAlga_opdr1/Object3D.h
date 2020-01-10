#ifndef __Object3D_h__
#define __Object3D_h__

#include <vector>
#include "Vector3D.h"
#include "Color.h"


class Object3D
{
protected:
	std::vector<Vector3D> points_;

	Color color_ = Color{ 255,255,255 };
public:
	Object3D();

	Object3D(std::vector<Vector3D> points);

	void draw(SDL_Renderer& renderer);

	virtual void update() = 0;

	void set_color(Color color);

	void do_matrix(const Matrix3D& matrix);
};

#endif