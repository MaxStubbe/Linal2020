#ifndef __Camera_h__
#define __Camera_h__

class Camera {
	int SCREEN_WIDTH;
	int SCREEN_HEIGHT;

public:
	int x;
	int y;
	float zoom;

	Camera(int width, int height);
	void setZoom(float value);
	void update();
	float getZoom();

};

#endif

