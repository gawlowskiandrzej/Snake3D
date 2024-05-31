#ifndef SNAKE_H
#define SNAKE_H


class Snake {
	private:

		int length;
		float fragmentDistance = -1.0f;

		bool isCollided();

	public:

		Snake(Model* snakeHead, int baseLength);

		float angle;
		float speed = 0.8f;
		std::vector<Model*> snakeFragments;

		void extendSnake(int amount);
		void move(int index);
		void renderSnakeBody(ShaderProgram* sp);

		int getLength();
};

#endif // !SNAKE_H

