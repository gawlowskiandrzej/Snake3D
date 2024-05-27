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
#include "MyCube.h"

int main(void)
{
	Game* game = new Game();

	Model* floor = new Model(myFloorVertices, myFloorTexCoords, nullptr,myFloorVertexCount);

	Model* snakeHead = new Model(mySnakeVertices, mySnakeTexCoords, nullptr, mySnakeVertexCount);

	snakeHead->readTextureFromPng("./bricks.png");
	snakeHead->scale(vec3(0.1f, 0.1f, 1.0f));
	game->addModel(snakeHead);

	floor->readTextureFromPng("./grass.png");
	floor->scale(vec3(0.8f, 0.8f, 1.0f));
	game->addModel(floor);

	printf("Resources loaded... starting app loop.");

	while (!glfwWindowShouldClose(game->getWindow()))
	{
		game->drawScene();
		game->updateInput();
	}

	//printf("EEEL");
}

//float speed_x = 0;
//float speed_y = 0;
//float aspectRatio = 1;
//
//ShaderProgram* sp;
//
//
////Odkomentuj, �eby rysowa� kostk�
//float* vertices = myCubeVertices;
//float* normals = myCubeNormals;
//float* texCoords = myCubeTexCoords;
//float* colors = myCubeColors;
//int vertexCount = myCubeVertexCount;
//
//
////Odkomentuj, �eby rysowa� czajnik
////float* vertices = myTeapotVertices;
////float* normals = myTeapotVertexNormals;
////float* texCoords = myTeapotTexCoords;
////float* colors = myTeapotColors;
////int vertexCount = myTeapotVertexCount;
//
//GLuint tex0;
//GLuint tex1;
//
////Procedura obs�ugi b��d�w
//void error_callback(int error, const char* description) {
//	fputs(description, stderr);
//}
//
//
//void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
//
//}
//
//void windowResizeCallback(GLFWwindow* window, int width, int height) {
//	if (height == 0) return;
//	aspectRatio = (float)width / (float)height;
//	glViewport(0, 0, width, height);
//}
//
//
//GLuint readTexture(const char* filename) {
//	GLuint tex;
//	glActiveTexture(GL_TEXTURE0);
//
//	//Wczytanie do pami�ci komputera
//	std::vector<unsigned char> image;   //Alokuj wektor do wczytania obrazka
//	unsigned width, height;   //Zmienne do kt�rych wczytamy wymiary obrazka
//	//Wczytaj obrazek
//	unsigned error = lodepng::decode(image, width, height, filename);
//
//	//Import do pami�ci karty graficznej
//	glGenTextures(1, &tex); //Zainicjuj jeden uchwyt
//	glBindTexture(GL_TEXTURE_2D, tex); //Uaktywnij uchwyt
//	//Wczytaj obrazek do pami�ci KG skojarzonej z uchwytem
//	glTexImage2D(GL_TEXTURE_2D, 0, 4, width, height, 0,
//		GL_RGBA, GL_UNSIGNED_BYTE, (unsigned char*)image.data());
//
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//
//	return tex;
//}
//
//
////Procedura inicjuj�ca
//void initOpenGLProgram(GLFWwindow* window) {
//	//************Tutaj umieszczaj kod, kt�ry nale�y wykona� raz, na pocz�tku programu************
//	glClearColor(0, 0, 0, 1);
//	glEnable(GL_DEPTH_TEST);
//	glfwSetWindowSizeCallback(window, windowResizeCallback);
//	glfwSetKeyCallback(window, keyCallback);
//
//	sp = new ShaderProgram("v_simplest.glsl", NULL, "f_simplest.glsl");
//	tex0 = readTexture("bricks.png");
//	//tex1 = readTexture("bricks2_height.png");
//}
//
//
////Zwolnienie zasob�w zaj�tych przez program
//void freeOpenGLProgram(GLFWwindow* window) {
//	//************Tutaj umieszczaj kod, kt�ry nale�y wykona� po zako�czeniu p�tli g��wnej************
//
//	delete sp;
//}
//
//
//
//
////Procedura rysuj�ca zawarto�� sceny
//void drawScene(GLFWwindow* window, float angle_x, float angle_y) {
//	//************Tutaj umieszczaj kod rysuj�cy obraz******************l
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//	glm::mat4 V = glm::lookAt(
//		glm::vec3(0, 0, -4),
//		glm::vec3(0, 0, 0),
//		glm::vec3(0.0f, 1.0f, 0.0f)); //Wylicz macierz widoku
//
//	glm::mat4 P = glm::perspective(50.0f * PI / 180.0f, aspectRatio, 0.01f, 50.0f); //Wylicz macierz rzutowania
//
//	glm::mat4 M = glm::mat4(1.0f);
//	M = glm::rotate(M, angle_y, glm::vec3(1.0f, 0.0f, 0.0f)); //Wylicz macierz modelu
//	M = glm::rotate(M, angle_x, glm::vec3(0.0f, 1.0f, 0.0f)); //Wylicz macierz modelu
//
//	sp->use();//Aktywacja programu cieniuj�cego
//	//Przeslij parametry programu cieniuj�cego do karty graficznej
//	glUniformMatrix4fv(sp->u("P"), 1, false, glm::value_ptr(P));
//	glUniformMatrix4fv(sp->u("V"), 1, false, glm::value_ptr(V));
//	glUniformMatrix4fv(sp->u("M"), 1, false, glm::value_ptr(M));
//
//	glEnableVertexAttribArray(sp->a("vertex"));  //W��cz przesy�anie danych do atrybutu vertex
//	glVertexAttribPointer(sp->a("vertex"), 4, GL_FLOAT, false, 0, vertices); //Wska� tablic� z danymi dla atrybutu vertex
//
//	glEnableVertexAttribArray(sp->a("color"));  //W��cz przesy�anie danych do atrybutu color
//	glVertexAttribPointer(sp->a("color"), 4, GL_FLOAT, false, 0, colors); //Wska� tablic� z danymi dla atrybutu color
//
//	glEnableVertexAttribArray(sp->a("normal"));  //W��cz przesy�anie danych do atrybutu normal
//	glVertexAttribPointer(sp->a("normal"), 4, GL_FLOAT, false, 0, normals); //Wska� tablic� z danymi dla atrybutu normal
//
//	glEnableVertexAttribArray(sp->a("texCoord0"));  //W��cz przesy�anie danych do atrybutu texCoord
//	glVertexAttribPointer(sp->a("texCoord0"), 2, GL_FLOAT, false, 0, texCoords); //Wska� tablic� z danymi dla atrybutu texCoord
//
//	glUniform1i(sp->u("textureMap0"), 0);
//	glActiveTexture(GL_TEXTURE0);
//	glBindTexture(GL_TEXTURE_2D, tex0);
//
//	glUniform1i(sp->u("textureMap1"), 1);
//	glActiveTexture(GL_TEXTURE1);
//	glBindTexture(GL_TEXTURE_2D, tex1);
//
//	glDrawArrays(GL_TRIANGLES, 0, vertexCount); //Narysuj obiekt
//
//	glDisableVertexAttribArray(sp->a("vertex"));  //Wy��cz przesy�anie danych do atrybutu vertex
//	glDisableVertexAttribArray(sp->a("color"));  //Wy��cz przesy�anie danych do atrybutu color
//	glDisableVertexAttribArray(sp->a("normal"));  //Wy��cz przesy�anie danych do atrybutu normal
//	glDisableVertexAttribArray(sp->a("texCoord0"));  //Wy��cz przesy�anie danych do atrybutu texCoord0
//
//	glfwSwapBuffers(window); //Przerzu� tylny bufor na przedni
//}
//
//
//int main(void)
//{
//	GLFWwindow* window; //Wska�nik na obiekt reprezentuj�cy okno
//
//	glfwSetErrorCallback(error_callback);//Zarejestruj procedur� obs�ugi b��d�w
//
//	if (!glfwInit()) { //Zainicjuj bibliotek� GLFW
//		fprintf(stderr, "Nie mo�na zainicjowa� GLFW.\n");
//		exit(EXIT_FAILURE);
//	}
//
//	window = glfwCreateWindow(500, 500, "OpenGL", NULL, NULL);  //Utw�rz okno 500x500 o tytule "OpenGL" i kontekst OpenGL.
//
//	if (!window) //Je�eli okna nie uda�o si� utworzy�, to zamknij program
//	{
//		fprintf(stderr, "Nie mo�na utworzy� okna.\n");
//		glfwTerminate();
//		exit(EXIT_FAILURE);
//	}
//
//	glfwMakeContextCurrent(window); //Od tego momentu kontekst okna staje si� aktywny i polecenia OpenGL b�d� dotyczy� w�a�nie jego.
//	glfwSwapInterval(1); //Czekaj na 1 powr�t plamki przed pokazaniem ukrytego bufora
//
//	if (glewInit() != GLEW_OK) { //Zainicjuj bibliotek� GLEW
//		fprintf(stderr, "Nie mo�na zainicjowa� GLEW.\n");
//		exit(EXIT_FAILURE);
//	}
//
//	initOpenGLProgram(window); //Operacje inicjuj�ce
//
//	//G��wna p�tla
//	float angle_x = 0; //Aktualny k�t obrotu obiektu
//	float angle_y = 0; //Aktualny k�t obrotu obiektu
//	glfwSetTime(0); //Zeruj timer
//	while (!glfwWindowShouldClose(window)) //Tak d�ugo jak okno nie powinno zosta� zamkni�te
//	{
//		angle_x += speed_x * glfwGetTime(); //Zwi�ksz/zmniejsz k�t obrotu na podstawie pr�dko�ci i czasu jaki up�yna� od poprzedniej klatki
//		angle_y += speed_y * glfwGetTime(); //Zwi�ksz/zmniejsz k�t obrotu na podstawie pr�dko�ci i czasu jaki up�yna� od poprzedniej klatki
//		glfwSetTime(0); //Zeruj timer
//		drawScene(window, angle_x, angle_y); //Wykonaj procedur� rysuj�c�
//		glfwPollEvents(); //Wykonaj procedury callback w zalezno�ci od zdarze� jakie zasz�y.
//	}
//
//	freeOpenGLProgram(window);
//
//	glfwDestroyWindow(window); //Usu� kontekst OpenGL i okno
//	glfwTerminate(); //Zwolnij zasoby zaj�te przez GLFW
//	exit(EXIT_SUCCESS);
//}