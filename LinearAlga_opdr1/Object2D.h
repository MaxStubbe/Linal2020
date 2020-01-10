#ifndef __Object2D_h__
#define __Object2D_h__

#include <vector>
#include "Vector2D.h"
#include "Color.h"
#include "Matrix2D.h"
#include "Camera2D.h"

class Object2D
{
protected:
	Camera2D& camera_;

	std::vector<Vector2D> points_;

	Color color_ = Color{255,255,255};
public:
	Object2D(Camera2D& camera);

	Object2D(Camera2D& camera,std::vector<Vector2D> points);

	void draw(SDL_Renderer& renderer);

	virtual void update() = 0;

	void set_color(Color color);

	void do_matrix(const Matrix2D& matrix);

};
#endif

