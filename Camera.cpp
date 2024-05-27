#include "Camera.h"

mat4 Camera::getViewMatrix() { return this->V; }

mat4 Camera::getPositionMatrix() { return this->P; }
