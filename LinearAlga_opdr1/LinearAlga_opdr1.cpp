#include <iostream>
#include <SDL.h>
#include <SDL_main.h>
#include "Vector2D.h"
#include <cmath>
#include "Camera2D.h"
#include <string>
#include "Scene.h"
#include "Cube2D.h"
#include "Basic_Matrices.h"

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
			Cube2D* cube = new Cube2D(scene.getCamera() ,50);
			scene.add_obect(cube);

			//Event handler
			SDL_Event event;

			Matrix2D scale_times_two_matrix = Matrix2D() * 2;

			Matrix2D scale_times_half_matrix = Matrix2D() / 2;

			Matrix2D rotate_right_matrix = get_rotation_matrix_degrees(1);

			Matrix2D rotate_left_matrix = get_rotation_matrix_degrees(-1);

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

							if (key == "W") {
								scene.getCamera().position_.y -= 1;
							}
							if (key == "S") {
								scene.getCamera().position_.y += 1;
							}
							if (key == "A") {
								scene.getCamera().position_.x -= 1;
							}
							if (key == "D") {
								scene.getCamera().position_.x += 1;
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
