#include "Camera.h"
#include <SDL_rect.h>

Camera::Camera(int width, int height)
{
	SCREEN_WIDTH = width;
	SCREEN_HEIGHT = height;
	zoom = 1;
	x = SCREEN_WIDTH / 2;
	y = SCREEN_HEIGHT / 2;
}

void Camera::setZoom(float value)
{
	zoom = 1;
}

void Camera::update()
{
	x = SCREEN_WIDTH / 2;  //((SCREEN_WIDTH * zoom) - SCREEN_WIDTH / 2);
	y = SCREEN_HEIGHT / 2; //((SCREEN_HEIGHT * zoom) - SCREEN_HEIGHT / 2);
}

float Camera::getZoom()
{
	return zoom;
}
