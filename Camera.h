#ifndef CAMERA_H
#define CAMERA_H

#include "libraries.h"

class Camera {
	private:
		// Camera matrices
		mat4 V = mat4(1.0f);
		mat4 P = perspective(radians(FOV), ASPECT_RATIO, NEAR_PLANE, FAR_PLANE);

	public:
		mat4 getViewMatrix();
		mat4 getPositionMatrix();
};

#endif // CAMERA_H

