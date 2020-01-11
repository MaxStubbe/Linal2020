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
#include "AidLine3D.h"

/*
Knockout Criterea: 1/1
Code/Matrices: 1/1
Bewegen Schip: 1.5/1.5 ALS DRAAIEN NETJES WERKT anders 0.68
Kogels afschieten 1.05/1.5 ALS VECTOR ALS MATRIX TELT DAN 1,5
Pulserend doel: 1.5/1.5
Doel Raken: 0.7/1 
Unit Tests: 0.7/1
Camera in 3D Wereld: 0.5/0.5
Overig: 0/1

Waarschijnlijk: 7.95/10 
Worst case nu: 7.13/10
*/

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

			//Add Animated Cube
			PulsingCube3D* cube3d = new PulsingCube3D(scene3d.getCamera(), Vector3D(-5, 0, 0),1,10);
			scene3d.add_object(cube3d);

			//Set Camera Position
			scene3d.getCamera().position_.x = -50;
			scene3d.getCamera().position_.y = 0;
			scene3d.getCamera().position_.z = 0;

			//Add Cubes
			Cube3D* cube_blue = new Cube3D(scene3d.getCamera(), Vector3D(5, 0, 0), 1);
			cube_blue->set_color(blue());
			scene3d.add_object(cube_blue);

			/*Cube3D* cube_yellow = new Cube3D(scene3d.getCamera(), Vector3D(-5, 0, 0), 1);
			cube_yellow->set_color(yellow());
			scene3d.add_object(cube_yellow);*/

			Cube3D* cube_cyan = new Cube3D(scene3d.getCamera(), Vector3D(0, 5, 0), 1);
			cube_cyan->set_color(cyan());
			cube_cyan->rotation_.z = 90;
			scene3d.add_object(cube_cyan);

			Cube3D* cube_pink = new Cube3D(scene3d.getCamera(), Vector3D(0, -5, 0), 1);
			cube_pink->set_color(pink());
			cube_pink->rotation_.y = 90;
			scene3d.add_object(cube_pink);

			Cube3D* cube_orange = new Cube3D(scene3d.getCamera(), Vector3D(0, 0, 5), 1);
			cube_orange->set_color(orange());
			scene3d.add_object(cube_orange);

			Cube3D* cube_lime = new Cube3D(scene3d.getCamera(), Vector3D(0, 0, -5), 1);
			cube_lime->set_color(lime());
			scene3d.add_object(cube_lime);

			//Add spaceship
			SpaceShip3D* ship = new SpaceShip3D(scene3d.getCamera(), Vector3D());
			scene3d.add_object(ship);

			//Add AidLine
			/*AidLine3D* line_x = new AidLine3D(scene3d.getCamera(),Vector3D(500,0,0), Vector3D(-500,0,0));
			scene3d.add_object(line_x);

			AidLine3D* line_y = new AidLine3D(scene3d.getCamera(), Vector3D(0,500,0), Vector3D(0,-500, 0));
			scene3d.add_object(line_y);

			AidLine3D* line_z = new AidLine3D(scene3d.getCamera(), Vector3D(0, 0, 500), Vector3D(0, 0, -500));
			scene3d.add_object(line_z);*/

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

							if (key == "Left") {
								scene3d.getCamera().move_x(-1);
							}
							if (key == "Up") {
								scene3d.getCamera().move_y(-1);
							}
							if (key == "Down") {
								scene3d.getCamera().move_y(1);
							}
							if (key == "Right") {
								scene3d.getCamera().move_x(1);
							}
							if (key == "PageUp") {
								scene3d.getCamera().move_z(-1);
							}
							if (key == "PageDown") {
								scene3d.getCamera().move_z(1);
							}

							if (key == "J") {//turn up
								scene3d.getCamera().rotate_x(1);
							}
							if (key == "L") {//turn down
								scene3d.getCamera().rotate_x(-1);
							}

							if (key == "K") {//turn left
								scene3d.getCamera().rotate_y(1);
							}
							if (key == "I") {//turn right
								scene3d.getCamera().rotate_y(-1);
							}

							if (key == "O") {//roll left
								scene3d.getCamera().rotate_z(1);
							}
							if (key == "U") {//roll right
								scene3d.getCamera().rotate_z(-1);
							}

							
							if (key == "Left Shift") {//forward
								ship->forward();
							}
							if (key == "Left Ctrl") {//back
								ship->back();
							}
							if (key == "Space") {//forward
								ship->shoot(&scene3d);
							}
							if (key == "W") {//up
								ship->up();
							}
							if (key == "S") {//down
								ship->down();
							}
							if (key == "A") {//left
								ship->left();
							}
							if (key == "D") {//right
								ship->right();
							}
							if (key == "Q") {//rollleft
								ship->rollleft();
							}
							if (key == "E") {//rollright
								ship->rollright();
							}

							if (key == "X") {
								scene3d.getCamera().position_ = Vector3D(0,0,0);
								scene3d.getCamera().lookat_ = Vector3D(1,0,0);
							}
							if (key == "Y") {
								scene3d.getCamera().position_ = Vector3D(0, 0, 0);
								scene3d.getCamera().lookat_ = Vector3D(0.00001, 1, 0);
							}
							if (key == "Z") {
								scene3d.getCamera().position_ = Vector3D(0, 0, 0);
								scene3d.getCamera().lookat_ = Vector3D(0, 0, 1);
							}
							if (key == "T") {
								scene3d.getCamera().position_ = Vector3D(-36, 15, 22);
								scene3d.getCamera().lookat_ = Vector3D(0.5, -7, -5.5);
							}
							if (key == "F") {
								scene3d.getCamera().position_ = Vector3D(25, 0, 0);
								scene3d.getCamera().lookat_ = Vector3D(50, 0, 0);
							}

							if (key == "P") {
								scene3d.getCamera().perspective_ = !scene3d.getCamera().perspective_;
							}

							if (key == "M") {
								cube_pink->rotation_.y += 5;
							}


							/*std::cout << "Camera Lookat " << (scene3d.getCamera().lookat_) << "\n";

							std::cout << "Camera Position " << (scene3d.getCamera().position_) << "\n";

							std::cout << "Camera Up " << (scene3d.getCamera().up_) << "\n";*/

							std::cout << "Rotation: " << ship->rotation_ << "\n";

							float dot = Vector3D(1, 0, 0).dot_product(ship->forward_);
							float angle = acos(dot);
							std::cout << "Forward: " << ship->forward_ << "\n";
							std::cout << "Angle: " << radians_to_degrees(angle) << "\n";

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
