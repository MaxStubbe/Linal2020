#ifndef __Object2D_h__
#define __Object2D_h__

#include <vector>
#include "Vector2D.h"
#include "Color.h"
#include "Matrix2D.h"

class Object2D
{
protected:
	std::vector<Vector2D> points_;

	Color color_ = Color{255,255,255};
public:
	Object2D();

	Object2D(std::vector<Vector2D> points);

	void draw(SDL_Renderer& renderer);

	virtual void update() = 0;

	void set_color(Color color);

	void do_matrix(const Matrix2D& matrix);

};
#endif

