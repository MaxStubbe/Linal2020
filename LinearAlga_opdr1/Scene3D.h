#ifndef __Scene3D_h__
#define __Scene3D_h__

#include <vector>
#include "Object3D.h"
#include "Camera3D.h"

class Scene3D
{
private:
	std::vector<Object3D*> objects_;

	Camera3D camera_;

	SDL_Renderer& renderer_;

public:
	Scene3D(SDL_Renderer& renderer);

	~Scene3D();

	void add_obect(Object3D* object);

	void draw();

	void update();

	Camera3D& getCamera() { return camera_; };
};

#endif