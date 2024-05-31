#include "Model.h"
#include "Snake.h"

bool Snake::isCollided()
{
    return false;
}

Snake::Snake(Model* snakeHead, int baseLength)
{
    this->length = 1;
    this->snakeFragments.push_back(snakeHead);
    this->extendSnake(1);
}

void Snake::extendSnake(int amount)
{
    for (int i = 0; i < amount; i++)
    {
        this->snakeFragments.push_back(new Model(*this->snakeFragments.at(this->length - 1)));
        this->length++;
    }
}

void Snake::move(int index)
{
    if (isCollided())
    {
        printf("Snake run into the wall or himself, you loose!");
        exit(EXIT_SUCCESS);
    }
    if (index == 0)
    {
        this->snakeFragments.at(index)->translate(vec3(0.0f, this->speed, 0.0f));
        this->snakeFragments.at(index)->rotate(this->angle,vec3(0.0f, 0.0f, 1.0f));
        return;
    }
    this->snakeFragments.at(index)->setModelMatrix(this->snakeFragments.at(index - 1)->getModelMatrix());
    this->snakeFragments.at(index)->translate(vec3(0.0f, this->fragmentDistance, 0.0f));
    this->move(index - 1);
}

int Snake::getLength() { return this->length; }

void Snake::renderSnakeBody(ShaderProgram* sp)
{
    for (Model* snakeBody : this->snakeFragments)
    {
        snakeBody->sendToShader(sp);
        snakeBody->activeTexture(sp);
        glDrawArrays(GL_TRIANGLES, 0, snakeBody->vertexCount);
    }
}
