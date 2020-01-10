#ifndef __Scene2D_h__
#define __Scene2D_h__

#include <vector>
#include "Object2D.h"
#include "Camera2D.h"

class Scene2D
{
	private:
		std::vector<Object2D*> objects_;

		Camera2D camera_;

		SDL_Renderer& renderer_;

	public:
		Scene2D(SDL_Renderer& renderer);

		~Scene2D();

		void add_obect(Object2D* object);

		void draw();

		void update();

		Camera2D& getCamera() { return camera_; };

};


#endif
