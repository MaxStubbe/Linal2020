#ifndef __Object3D_h__
#define __Object3D_h__

#include <vector>
#include "Vector3D.h"
#include "Color.h"
#include "Camera3D.h"
#include "BoundingBox3D.h"


class Object3D
{
protected:

	Camera3D& camera_;

	Vector3D position_;

	Vector3D scale_ = Vector3D(1,1,1);

	BoundingBox3D collider_;

	float size_;

	std::vector<std::vector<Vector3D>> points_;

	Color color_ = Color{ 255,255,255 };
public:
	Vector3D center_;

	Vector3D rotation_ = Vector3D(0, 0, 0);

	Vector3D forward_ = Vector3D(1, 0, 0);

	Vector3D up_ = Vector3D(0, 1, 0);

	Vector3D right_ = Vector3D(0, 0, 1);

	Object3D(Camera3D& camera, Vector3D position = Vector3D());

	Object3D(Camera3D& camera, Vector3D position, std::vector<std::vector<Vector3D>> points);

	void draw(SDL_Renderer& renderer);

	virtual void update() = 0;

	void set_color(Color color);

	void do_matrix(const Matrix3D& matrix);

	void do_rotation(const Matrix3D& matrix);

	Vector3D get_forward();

	bool collides_with(const Object3D& other);

	float get_radius() const;

	virtual void on_collision() = 0;
};

#endif