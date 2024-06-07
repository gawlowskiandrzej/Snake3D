/*
Niniejszy program jest wolnym oprogramowaniem; mo¿esz go
rozprowadzaæ dalej i / lub modyfikowaæ na warunkach Powszechnej
Licencji Publicznej GNU, wydanej przez Fundacjê Wolnego
Oprogramowania - wed³ug wersji 2 tej Licencji lub(wed³ug twojego
wyboru) którejœ z póŸniejszych wersji.

Niniejszy program rozpowszechniany jest z nadziej¹, i¿ bêdzie on
u¿yteczny - jednak BEZ JAKIEJKOLWIEK GWARANCJI, nawet domyœlnej
gwarancji PRZYDATNOŒCI HANDLOWEJ albo PRZYDATNOŒCI DO OKREŒLONYCH
ZASTOSOWAÑ.W celu uzyskania bli¿szych informacji siêgnij do
Powszechnej Licencji Publicznej GNU.

Z pewnoœci¹ wraz z niniejszym programem otrzyma³eœ te¿ egzemplarz
Powszechnej Licencji Publicznej GNU(GNU General Public License);
jeœli nie - napisz do Free Software Foundation, Inc., 59 Temple
Place, Fifth Floor, Boston, MA  02110 - 1301  USA
*/

#include "Game.h"
#include "MyFloor.h"
#include "myWall.h"

int main(void)
{
	Game* game = new Game();

	Model* floor = new Model(myFloorVertices, myFloorTexCoords, nullptr,myFloorVertexCount);

	floor->readTextureFromPng("./textures/grass2.png");
	floor->scale(vec3(3.3f, 3.3f, 1.0f));

	Model* snakeHead = new Model("./objFiles/Sun.obj", "./textures/snakeHead.png", 0.08);

	snakeHead->translate(vec3(0.4, 0.4, -1.3));
	snakeHead->rotate(90, vec3(1, 0, 0));
	snakeHead->scale(vec3(1.2, 1.2, 1.2));

	Model* snakeBodyFrag = new Model("./objFiles/snakeBody.obj", "./textures/snakeBody.png", 0.07, -4);

	snakeBodyFrag->translate(vec3(0, 0, -1.3));
	snakeBodyFrag->scale(vec3(1.2, 1.2, 1.2));

	Model* fence = new Model(myWallVertices, myWallTexCoords, nullptr, myWallVertexCount);

	fence->translate(vec3(0, 0, -1.3));
	fence->scale(vec3(3.3, 3.3, 1));
	fence->readTextureFromPng("./textures/fence.png");

	Model* apple = new Model("./objFiles/apple.obj", "./textures/apple.png");
	
	apple->scale(vec3(5, 5, 5));
	apple->rotate(-90, vec3(1, 0, 0));
	apple->translate(vec3(0.2, 0.2, -2.3));
	

	game->addModel(floor);
	game->addModel(fence);
	game->addModel(apple);

	Snake* snakeBody = new Snake(snakeHead,snakeBodyFrag, 28);
	game->addSnake(snakeBody);

	printf("Resources loaded... starting app loop.");

	while (!glfwWindowShouldClose(game->getWindow()))
	{
		game->drawScene();
		game->updateInput();
	}

}