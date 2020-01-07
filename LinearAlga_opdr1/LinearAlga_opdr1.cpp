#include <iostream>
#include <SDL.h>
#include <SDL_main.h>
#include "Vector2D.h"
#include "Matrix.h"
#include <cmath>
#include "Camera.h"
#include <string>

void drawOnGraph(SDL_Renderer* renderer, Camera* camera, float scale, float posx, float posy, float rot) {

	float rotation =  M_PI * rot;

	Matrix scaleMatrix = Matrix({ scale,0 }, { 0,scale }) ;
	Matrix translationMatrix1 = Matrix({ 1,0,-posx }, { 0,1,-posy }, { 0,0,1 });
	Matrix translationMatrix2 = Matrix({ 1,0,posx }, { 0,1,posy }, { 0,0,1 });
	Matrix rotationMatrix = Matrix({ cos(rotation), -sin(rotation), 0 }, { sin(rotation), cos(rotation), 0 }, { 0 , 0, 1 });

	const int WINDOWWIDTH = 640;
	const int WINDOWHEIGHT = 480;
	SDL_RenderDrawLine(renderer, camera->x, 0, camera->x, WINDOWHEIGHT);
	SDL_RenderDrawLine(renderer, 0, camera->y, WINDOWWIDTH, camera->y);

	/*Vector2D a = translationMatrix2 * Vector2D(10, 10);
	Vector2D b = translationMatrix2 * Vector2D(40, 10);
	Vector2D c = translationMatrix2 * Vector2D(40, 40);
	Vector2D d = translationMatrix2 * Vector2D(10, 40);*/

	Vector2D a = (rotationMatrix * (scaleMatrix * (translationMatrix2 * Vector2D(10, 10))));
	Vector2D b = (rotationMatrix * (scaleMatrix * (translationMatrix2 * Vector2D(40, 10))));
	Vector2D c = (rotationMatrix * (scaleMatrix * (translationMatrix2 * Vector2D(40, 40))));
	Vector2D d = (rotationMatrix * (scaleMatrix * (translationMatrix2 * Vector2D(10, 40))));

	SDL_Point points[5] = {
		a.getPoint(camera), b.getPoint(camera),c.getPoint(camera),d.getPoint(camera), a.getPoint(camera)
	};

	SDL_RenderDrawLines(renderer, points, 5);
}

int main(int argc, char* args[])
{
	if (SDL_Init(SDL_INIT_VIDEO) == 0) {
		SDL_Window* window = NULL;
		SDL_Renderer* renderer = NULL;
		int WINDOWWIDTH = 640;
		int WINDOWHEIGHT = 480;
		float scale = 1;
		float posx = 0;
		float posy = 0;
		float rot = 0;
		if (SDL_CreateWindowAndRenderer(WINDOWWIDTH, WINDOWHEIGHT, 0, &window, &renderer) == 0) {
			//Main loop flag
			bool quit = false;

			//Event handler
			SDL_Event event;

			//While application is running
			while (!quit)
			{
				SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
				SDL_RenderClear(renderer);

				SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);

				Camera* camera = new Camera(WINDOWWIDTH, WINDOWHEIGHT);
				for (int i = 0; i < 10; i++) {
					drawOnGraph(renderer, camera, scale + i, posx, posy, rot);
					drawOnGraph(renderer, camera, -scale - i,  -posx, -posy, rot);
				}

				SDL_RenderPresent(renderer);
				//Handle events on queue
				while (SDL_PollEvent(&event) != 0)
				{
					switch (event.type) {
						case SDL_QUIT:
							quit = true;
						case SDL_KEYDOWN:
						{
							std::string key(SDL_GetKeyName(event.key.keysym.sym));

							if (key == "W") {
								WINDOWHEIGHT -= 5;
							}
							if (key == "A") {
								WINDOWWIDTH -= 5;
							}
							if (key == "S") {
								WINDOWHEIGHT += 5;
							}
							if (key == "D") {
								WINDOWWIDTH += 5;
							}

							if (key == "K") {
								scale += 0.5;
							}
							if (key == "J") {
								scale -= 0.5;
							}

							if (key == "X") {
								rot += 0.25;
							}
							if (key == "Z") {
								rot -= 0.25;
							}

							if (key == "Up") {
								posy += 1;
							}
							if (key == "Left") {
								posx -= 1;
							}
							if (key == "Down") {
								posy -= 1;
							}
							if (key == "Right") {
								posx += 1;
							}

							
							std::cout << key << std::endl;
							break;
						}
					}
				}
			}

			if (renderer) {
				SDL_DestroyRenderer(renderer);
			}
			if (window) {
				SDL_DestroyWindow(window);
			}
		}
	}
	return 1;
}


