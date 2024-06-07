#ifndef SNAKE_H
#define SNAKE_H


class Snake {
	private:

		int length;
		int baseLength = 1;
		//float fragmentDistance = 2.0f;

		bool isCollided();

	public:

		Snake(Model* snakeHead, Model* snakeBody, int baseLength);

		float angle;
		float speed = 0.1f;
		std::vector<Model*> snakeFragments;

		void extendSnake(int amount);
		void move(int index);
		void renderSnakeBody(ShaderProgram* sp);

		int getLength();
};

#endif // !SNAKE_H

