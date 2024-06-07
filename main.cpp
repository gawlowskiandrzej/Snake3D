/*
Niniejszy program jest wolnym oprogramowaniem; mo�esz go
rozprowadza� dalej i / lub modyfikowa� na warunkach Powszechnej
Licencji Publicznej GNU, wydanej przez Fundacj� Wolnego
Oprogramowania - wed�ug wersji 2 tej Licencji lub(wed�ug twojego
wyboru) kt�rej� z p�niejszych wersji.

Niniejszy program rozpowszechniany jest z nadziej�, i� b�dzie on
u�yteczny - jednak BEZ JAKIEJKOLWIEK GWARANCJI, nawet domy�lnej
gwarancji PRZYDATNO�CI HANDLOWEJ albo PRZYDATNO�CI DO OKRE�LONYCH
ZASTOSOWA�.W celu uzyskania bli�szych informacji si�gnij do
Powszechnej Licencji Publicznej GNU.

Z pewno�ci� wraz z niniejszym programem otrzyma�e� te� egzemplarz
Powszechnej Licencji Publicznej GNU(GNU General Public License);
je�li nie - napisz do Free Software Foundation, Inc., 59 Temple
Place, Fifth Floor, Boston, MA  02110 - 1301  USA
*/

#include "Game.h"
#include "MyFloor.h"
#include "myWall.h"

int main(void)
{
	Game* game = new Game();

	Model* apple = new Model("./objFiles/apple.obj", "./textures/apple.png");
	
	//apple->rotate(-90, vec3(1, 0, 0));
	apple->translate(vec3(1.5, 0, -1.3));
	apple->scale(vec3(5, 5, 5));
	game->apple = apple;
	game->addModel(apple);

	Model* floor = new Model(myFloorVertices, myFloorTexCoords, nullptr,myFloorVertexCount);

	floor->readTextureFromPng("./textures/grass2.png");
	floor->scale(vec3(3.3f, 3.3f, 1.0f));

	Model* snakeHead = new Model("./objFiles/Sun.obj", "./textures/snakeHead.png", 0.08, 3);

	snakeHead->translate(vec3(0.4, 0.4, -1.3));
	snakeHead->rotate(90, vec3(1, 0, 0));
	snakeHead->scale(vec3(1.2, 1.2, 1.2));

	Model* snakeBodyFrag = new Model("./objFiles/snakeBody.obj", "./textures/snakeBody.png", 0.07, -4, 3);

	snakeBodyFrag->translate(vec3(0.4, 0.51, -1.3));
	snakeBodyFrag->scale(vec3(1.2, 1.2, 1.2));

	Model* fence = new Model(myWallVertices, myWallTexCoords, nullptr, myWallVertexCount);

	fence->translate(vec3(0, 0, -1.3));
	fence->scale(vec3(3.3, 3.3, 1));
	fence->readTextureFromPng("./textures/fence.png");
	

	game->addModel(floor);
	game->addModel(fence);
	

	Snake* snakeBody = new Snake(snakeHead,snakeBodyFrag, 5);
	game->addSnake(snakeBody);

	printf("Resources loaded... starting app loop.");

	mat4 appleMat = apple->getModelMatrix();
	appleMat[3][0] = (rand() % 6) - 2.8f;
	appleMat[3][1] = (rand() % 6) - 2.8f;
	apple->setModelMatrix(appleMat);

	while (!glfwWindowShouldClose(game->getWindow()))
	{
		game->drawScene();
		game->updateInput();
	}

}