#include "Camera.h"

double Camera::lastCameraPosx = 0.0f;
double Camera::lastCameraPosy = 0.0f;
float Camera::angle_x = 0.0f;
float Camera::angle_y = 0.0f;

mat4 Camera::getViewMatrix() { return this->V; }

mat4 Camera::getPositionMatrix() { return this->P; }

void Camera::updateCameraPos(double pressingTime)
{
	mat4 Mc = rotate(mat4(1.0f),Camera::angle_y, vec3(0, 1, 0));
	Mc = rotate(Mc, Camera::angle_x, vec3(1, 0, 0));

	vec4 dir_ = Mc * vec4(0, 0, 1, 0);
	this->Dirvec = vec3(dir_);

	vec3 mdir = normalize(vec3(this->Dirvec.x, this->Dirvec.y, this->Dirvec.z));

	vec3 right = normalize(cross(mdir, vec3(0, 1, 0)));

	this->CameraPos += this->cameraSpeed * mdir;

	this->CameraPos += this->speed_x * right;

	// Update view camera matrix
	this->V = lookAt(this->CameraPos, this->CameraPos + this->Dirvec, glm::vec3(0.0f, 1.0f, 0.0f));

}

