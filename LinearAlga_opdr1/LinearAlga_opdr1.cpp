#include <iostream>
#include <SDL.h>
#include <SDL_main.h>
#include "Vector2D.h"
#include "Matrix.h"
#include <cmath>
#include "Camera.h"
#include <string>
#include "Scene.h"
#include "Cube2D.h"

//void drawOnGraph(SDL_Renderer* renderer, Camera* camera, float scale, float posx, float posy, float rot) {
//
//	float rotation =  M_PI * rot;
//
//	Matrix scaleMatrix = Matrix({ scale,0 }, { 0,scale }) ;
//	Matrix translationMatrix1 = Matrix({ 1,0,-posx }, { 0,1,-posy }, { 0,0,1 });
//	Matrix translationMatrix2 = Matrix({ 1,0,posx }, { 0,1,posy }, { 0,0,1 });
//	Matrix rotationMatrix = Matrix({ cos(rotation), -sin(rotation), 0 }, { sin(rotation), cos(rotation), 0 }, { 0 , 0, 1 });
//
//	const int WINDOWWIDTH = 640;
//	const int WINDOWHEIGHT = 480;
//	SDL_RenderDrawLine(renderer, camera->x, 0, camera->x, WINDOWHEIGHT);
//	SDL_RenderDrawLine(renderer, 0, camera->y, WINDOWWIDTH, camera->y);
//
//	/*Vector2D a = translationMatrix2 * Vector2D(10, 10);
//	Vector2D b = translationMatrix2 * Vector2D(40, 10);
//	Vector2D c = translationMatrix2 * Vector2D(40, 40);
//	Vector2D d = translationMatrix2 * Vector2D(10, 40);*/
//
//	Vector2D a = (rotationMatrix * (scaleMatrix * (translationMatrix2 * Vector2D(10, 10))));
//	Vector2D b = (rotationMatrix * (scaleMatrix * (translationMatrix2 * Vector2D(40, 10))));
//	Vector2D c = (rotationMatrix * (scaleMatrix * (translationMatrix2 * Vector2D(40, 40))));
//	Vector2D d = (rotationMatrix * (scaleMatrix * (translationMatrix2 * Vector2D(10, 40))));
//
//	SDL_Point points[5] = {
//		a.get_sdl_point(), b.get_sdl_point(),c.get_sdl_point(),d.get_sdl_point(), a.get_sdl_point()
//	};
//
//	SDL_RenderDrawLines(renderer, points, 5);
//}

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

			//Scene
			Scene scene = Scene(*renderer);
			Cube2D* cube = new Cube2D(50);
			scene.add_obect(cube);

			//Event handler
			SDL_Event event;

			Matrix2D scale_times_two_matrix = Matrix2D() * 2;

			Matrix2D scale_times_half_matrix = Matrix2D() / 2;

			float degrees = 1;

			float radians = degrees * M_PI / 180;

			float matrix[3][3] = {
				{cos(radians),-sin(radians),0},
				{sin(radians),cos(radians),0},
				{0,0,1},
			};

			float matrix2[3][3] = {
				{cos(-radians),-sin(-radians),0},
				{sin(-radians),cos(-radians),0},
				{0,0,1},
			};

			Matrix2D rotate_right_matrix = Matrix2D(matrix);

			Matrix2D rotate_left_matrix = Matrix2D(matrix2);

			//While application is running
			while (!quit)
			{
				SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
				SDL_RenderClear(renderer);
				
				scene.draw();

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
							if (key == "F") {
								cube->do_matrix(scale_times_two_matrix);
							}
							if (key == "G") {
								cube->do_matrix(scale_times_half_matrix);
							}
							if (key == "R") {
								cube->do_matrix(rotate_right_matrix);
							}
							if (key == "T") {
								cube->do_matrix(rotate_left_matrix);
							}
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
