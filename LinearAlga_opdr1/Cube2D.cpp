#include "Cube2D.h"

Cube2D::Cube2D(Camera2D& camera, int size) : Object2D(camera)
{
	points_.push_back(Vector2D(0, 0));
	points_.push_back(Vector2D(0, size));
	points_.push_back(Vector2D(size, size));
	points_.push_back(Vector2D(size, 0));
}

void Cube2D::update()
{

}
