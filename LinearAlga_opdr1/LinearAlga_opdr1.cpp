#include <iostream>
#include <SDL.h>
#include <SDL_main.h>
#include "Vector2D.h"
#include <cmath>
#include "Camera2D.h"
#include <string>
#include "Scene2D.h"
#include "Cube2D.h"
#include "Basic_Matrices.h"
#include "Scene3D.h"
#include "Cube3D.h"
#include "PulsingCube3D.h"
#include "SpaceShip3D.h"

int main(int argc, char* args[])
{
	if (SDL_Init(SDL_INIT_VIDEO) == 0) {
		SDL_Window* window = NULL;
		SDL_Renderer* renderer = NULL;
		int WINDOWWIDTH = 600;
		int WINDOWHEIGHT = 600;
		float scale = 1;
		float posx = 0;
		float posy = 0;
		float rot = 0;
		if (SDL_CreateWindowAndRenderer(WINDOWWIDTH, WINDOWHEIGHT, 0, &window, &renderer) == 0) {
			//Main loop flag
			bool quit = false;

			//Scene3D
			Scene3D scene3d = Scene3D(*renderer);
			PulsingCube3D* cube3d = new PulsingCube3D(scene3d.getCamera(), Vector3D(),1);
			scene3d.add_obect(cube3d);
			Cube3D* cube3d2 = new Cube3D(scene3d.getCamera(), Vector3D(5,0,0),1);
			scene3d.add_obect(cube3d2);
			scene3d.getCamera().position_.x = -750;
			scene3d.getCamera().position_.y = -750;
			scene3d.getCamera().position_.z = -750;

			//Add spaceship
			SpaceShip3D* ship = new SpaceShip3D(scene3d.getCamera(), Vector3D());
			scene3d.add_obect(ship);


			//Event handler
			SDL_Event event;

			Matrix3D scale_times_two_matrix = Matrix3D() * 2;

			Matrix3D scale_times_half_matrix = Matrix3D() / 2;


			scene3d.getCamera().set_matrix();


			//While application is running
			while (!quit)
			{
				SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
				SDL_RenderClear(renderer);
				scene3d.update();
				scene3d.getCamera().set_matrix();
				scene3d.draw();

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
								cube3d->do_matrix(scale_times_two_matrix);
							}
							if (key == "G") {
								cube3d->do_matrix(scale_times_half_matrix);
							}
							/*if (key == "R") {
								cube3d->do_matrix(rotate_right_matrix);
							}
							if (key == "T") {
								cube3d->do_matrix(rotate_left_matrix);
							}*/

							if (key == "W") {
								scene3d.getCamera().position_.y -= 1;
							}
							if (key == "S") {
								scene3d.getCamera().position_.y += 1;
							}
							if (key == "A") {
								scene3d.getCamera().position_.x -= 1;
							}
							if (key == "D") {
								scene3d.getCamera().position_.x += 1;
							}

							if (key == "Q") {
								scene3d.getCamera().lookat_.z -= 1;
							}
							if (key == "E") {
								scene3d.getCamera().lookat_.z += 1;
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
