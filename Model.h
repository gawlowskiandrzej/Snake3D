#ifndef MODEL_H
#define MODEL_H

#include "objloader.h"

class Model {
	private:
		OBJModel objModel;
		float* vertexPosition = nullptr;
		float* vertexTexCoord = nullptr;
		float* vertexNormal = nullptr;
		

		mat4 modelMatrix = mat4(1.0f);
		GLuint* texture = new GLuint();

	public:

		int vertexCount = 0;

		Model(float* vertexPosition, float* vertexTexCoord, float* vertexNormal, unsigned int vertexCount);
		Model(const char* filePath, const char* texturePath, float scale = 1, float translate = 0, float translate2 = 0);
		void setModelMatrix(mat4 modelMatrix);
		mat4 getModelMatrix();

		void rotate(float rotation, vec3 axis);
		void scale(vec3 scale);
		void translate(vec3 translate);

		void readTextureFromPng(const char* filePath);
		void readObj(const char* filePath, float scale, float translatee, float translate2);

		void sendToShader(ShaderProgram* sp);
		void activeTexture(ShaderProgram* sp);

		float* getPosition();
		float* getTexCoords();
		float* getNormals();
		int getCount();
};


#endif