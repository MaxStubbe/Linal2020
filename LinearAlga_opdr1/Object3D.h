#ifndef __Object3D_h__
#define __Object3D_h__

#include <vector>
#include "Vector3D.h"
#include "Color.h"
#include "Camera3D.h"


class Object3D
{
protected:
	Camera3D& camera_;

	Vector3D position_;

	Vector3D center_;

	Vector3D scale_ = Vector3D(1,1,1);

	Vector3D rotation_ = Vector3D(0,0,0);

	std::vector<std::vector<Vector3D>> points_;

	Color color_ = Color{ 255,255,255 };
public:
	Object3D(Camera3D& camera, Vector3D position = Vector3D());

	Object3D(Camera3D& camera, Vector3D position, std::vector<std::vector<Vector3D>> points);

	void draw(SDL_Renderer& renderer);

	virtual void update() = 0;

	void set_color(Color color);

	void do_matrix(const Matrix3D& matrix);

	Vector3D get_forward();
};

#endif