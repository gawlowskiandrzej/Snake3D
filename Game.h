#ifndef GAME_H
#define GAME_H

#include "Model.h"
#include "Camera.h"
#include "Snake.h"

class Game {
	private:

		GLFWwindow* window;
		const char* title = "Snake3D";

		const int width = 1000;
		const int height = 720;

		// All game models
		std::vector<Model*> gameModels;
		// Snake object
		Snake* snake;
		// Camera object
		Camera* camera;
		// Base shaders
		ShaderProgram* lambert;

		// Basic callbacks
		static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
		static void windowResizeCallback(GLFWwindow* window, int width, int height);
		static void error_callback(int error, const char* description);
		static void mouse_callback(GLFWwindow* window, double xpos, double ypos);

		void renderLambertObjects();

		void init();

		void setAttribArrays(ShaderProgram* sp);
		void disableAttribArrays(ShaderProgram* sp);
		void setPerspective(ShaderProgram* sp);

	public:
		

		Game();
		
		// Window
		GLFWwindow* getWindow();

		// Model
		Model* getModel(int pos);
		void addModel(Model* model);

		int gameModelsCount();

		//Snake
		void addSnake(Snake* snake);

		//OpenGL
		void drawScene();
		void updateInput();

};
#endif