#ifndef __Object2D_h__
#define __Object2D_h__

#include <vector>
#include "Vector2D.h"
#include "Color.h"
#include "Matrix2D.h"

class Object2D
{
private:
	std::vector<Vector2D> points_;

	Matrix2D scale_matrix;

	Color color_ = Color{255,255,255};
public:
	Object2D(std::vector<Vector2D> points);

	void draw(SDL_Renderer& renderer);

	virtual void update() = 0;

	void set_color(Color color);

};
#endif

