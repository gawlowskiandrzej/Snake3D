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
#include "MyCube.h"

int main(void)
{
	Game* game = new Game();

	Model* floor = new Model(myFloorVertices, myFloorTexCoords, nullptr,myFloorVertexCount);

	Model* snakeHead = new Model("./objFiles/snakeHead.obj", "./textures/snakeSkin.png");

	//snakeHead->translate(vec3(0, 0, 0));
	snakeHead->scale(vec3(6.0f, 6.0f, 6.0f));

	floor->readTextureFromPng("./textures/grass.png");
	floor->scale(vec3(3.3f, 3.3f, 1.0f));
	game->addModel(floor);

	Snake* snakeBody = new Snake(snakeHead, 1);
	game->addSnake(snakeBody);

	printf("Resources loaded... starting app loop.");

	while (!glfwWindowShouldClose(game->getWindow()))
	{
		game->drawScene();
		game->updateInput();
	}

}