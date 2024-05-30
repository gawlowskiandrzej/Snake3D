#ifndef CAMERA_H
#define CAMERA_H

#include "libraries.h"

class Camera {
	private:
		// Camera matrices
		mat4 V = mat4(1.0f);
		vec3 CameraPos = vec3(0, 0, -5);
		mat4 P = perspective(radians(FOV), ASPECT_RATIO, NEAR_PLANE, FAR_PLANE);
		vec3 Dirvec = vec3(0, 0, 1);
		

	public:
		mat4 getViewMatrix();
		mat4 getPositionMatrix();
		void updateCameraPos(double pressingTime);
		float cameraSpeed = 0;
		static float angle_x, angle_y;
		float speed_x = 0;
		static double lastCameraPosx, lastCameraPosy;
};

#endif // CAMERA_H

