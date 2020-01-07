#ifndef __Scene_h__
#define __Scene_h__

#include <vector>
#include "Object2D.h"
#include "Camera.h"

class Scene
{
	private:
		std::vector<Object2D*> objects_;

		Camera camera_;

		SDL_Renderer& renderer_;

	public:
		Scene(SDL_Renderer& renderer);

		~Scene();

		void add_obect(Object2D* object);

		void draw();

		void update();

		Camera& getCamera() { return camera_; };

};


#endif
