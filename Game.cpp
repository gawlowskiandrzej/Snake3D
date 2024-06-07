#include "Game.h"

// Wychycenie naci�ni�cia przycisku
void Game::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (action == GLFW_PRESS) {
		if (key == GLFW_KEY_ESCAPE) glfwSetWindowShouldClose(window, GL_TRUE);
	}
}

void Game::windowResizeCallback(GLFWwindow* window, int width, int height)
{
	if (height == 0) return;
	//aspectRatio = (float)((float)width / (float)height);
	glViewport(0, 0, width, height);
}

void Game::error_callback(int error, const char* description){ fputs(description, stderr); }

void Game::mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
	if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT))
	{
		double offsetx = xpos - Camera::lastCameraPosx;
		double offsety = ypos - Camera::lastCameraPosy;

		Camera::angle_x += (float)(offsety * -SENSITIVITY);
		Camera::angle_y += (float)(offsetx * SENSITIVITY);
	}
	Camera::lastCameraPosx = xpos;
	Camera::lastCameraPosy = ypos;
}

void Game::renderLambertObjects()
{
	this->lambert->use();

	this->setPerspective(this->lambert);

	this->setAttribArrays(this->lambert);

	for(Model* model : this->gameModels)
	{
		model->sendToShader(this->lambert);
		model->activeTexture(this->lambert);

		glDrawArrays(GL_TRIANGLES, 0, model->getCount());
	}

	this->snake->renderSnakeBody(this->lambert);

	this->disableAttribArrays(this->lambert);
}

void Game::init()
{
	glClearColor(0, 0, 0, 1);
	glEnable(GL_DEPTH_TEST);
	glfwSetWindowSizeCallback(this->window, this->windowResizeCallback);
	glfwSetKeyCallback(this->window, keyCallback);
	glfwSetCursorPosCallback(window, Game::mouse_callback);

	// Define base shaders
	this->lambert = new ShaderProgram("v_simplest.glsl", NULL, "f_simplest.glsl");
}

void Game::setAttribArrays(ShaderProgram* sp)
{
	glEnableVertexAttribArray(sp->a("vertex"));
	glEnableVertexAttribArray(sp->a("texCoord"));
	//glEnableVertexAttribArray(sp->a("normal"));
}

void Game::disableAttribArrays(ShaderProgram* sp)
{
	glDisableVertexAttribArray(sp->a("vertex"));
	glDisableVertexAttribArray(sp->a("texCoord"));
	//glDisableVertexAttribArray(sp->a("normal"));
}

void Game::setPerspective(ShaderProgram* sp)
{
	glUniformMatrix4fv(sp->u("P"), 1, false, glm::value_ptr(this->camera->getPositionMatrix()));
	glUniformMatrix4fv(sp->u("V"), 1, false, glm::value_ptr(this->camera->getViewMatrix()));
}

Game::Game()
{
	//aspectRatio = 1.0f;
	this->camera = new Camera();

	glfwSetErrorCallback(error_callback);//Zarejestruj procedur� obs�ugi b��d�w

	if (!glfwInit()) { //Zainicjuj bibliotek� GLFW
		fprintf(stderr, "Nie mo�na zainicjowa� GLFW.\n");
		exit(EXIT_FAILURE);
	}

	this->window = glfwCreateWindow(this->width, this->height, this->title, NULL, NULL);  //Utw�rz okno 500x500 o tytule "OpenGL" i kontekst OpenGL.

	if (!this->window) //Je�eli okna nie uda�o si� utworzy�, to zamknij program
	{
		fprintf(stderr, "Nie mo�na utworzy� okna.\n");
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	glfwMakeContextCurrent(this->window); //Od tego momentu kontekst okna staje si� aktywny i polecenia OpenGL b�d� dotyczy� w�a�nie jego.
	glfwSwapInterval(1); //Czekaj na 1 powr�t plamki przed pokazaniem ukrytego bufora

	if (glewInit() != GLEW_OK) { //Zainicjuj bibliotek� GLEW
		fprintf(stderr, "Nie mo�na zainicjowa� GLEW.\n");
		exit(EXIT_FAILURE);
	}

	init();
}

GLFWwindow* Game::getWindow() { return this->window; }

Model* Game::getModel(int pos) { return gameModels.at(pos); }

void Game::addModel(Model* model) { gameModels.push_back(model); }

void Game::applyAnimation()
{
	mat4 appleModelMat = apple->getModelMatrix();
	//printf("apple pos z: %.2f\n", appleModelMat[3][2]);
	if (appleModelMat[3][2] < -1.5f || appleModelMat[3][2] > -1.1f)
	{
		animationSpeed *= -1;
	}
	appleModelMat[3][2] += animationSpeed;
	apple->setModelMatrix(appleModelMat);
	this->apple->rotate(rotationSpeed, vec3(0, 1, 0));
}

int Game::gameModelsCount() { return gameModels.size(); }

void Game::addSnake(Snake* snake) { this->snake = snake; }

void Game::drawScene()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	this->camera->updateCameraPos(0);

	renderLambertObjects();

	applyAnimation();

	glfwSwapBuffers(this->window);
}

void Game::updateInput()
{
	glfwPollEvents();

	if (glfwGetKey(this->window, GLFW_KEY_A) == GLFW_PRESS) { if (this->snake->angle > 0) { this->snake->angle *= -1; }  this->snake->move(this->snake->getLength() - 1, this->apple); }
	else if (glfwGetKey(this->window, GLFW_KEY_D) == GLFW_PRESS) { if (this->snake->angle < 0) { this->snake->angle *= -1; } this->snake->move(this->snake->getLength() - 1, this->apple); }
	else if (glfwGetKey(this->window, GLFW_KEY_ESCAPE) == GLFW_PRESS) glfwSetWindowShouldClose(this->window, GL_TRUE);


	 if (glfwGetKey(this->window, GLFW_KEY_UP) == GLFW_PRESS) this->camera->cameraSpeed = CAMERA_SPEED;
	 else if (glfwGetKey(this->window, GLFW_KEY_DOWN) == GLFW_PRESS) this->camera->cameraSpeed = -CAMERA_SPEED;
	 else if (glfwGetKey(this->window, GLFW_KEY_RIGHT) == GLFW_PRESS) this->camera->speed_x = CAMERA_SPEED;
	 else if (glfwGetKey(this->window, GLFW_KEY_LEFT) == GLFW_PRESS) this->camera->speed_x = -CAMERA_SPEED;

	else { this->camera->cameraSpeed = 0; this->camera->speed_x = 0; }

	std::this_thread::sleep_for(std::chrono::milliseconds(10));
}
