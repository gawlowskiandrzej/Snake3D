#include "Model.h"
#include "Snake.h"

bool Snake::isCollided()
{
    return false;
}

Snake::Snake(Model* snakeHead, Model* snakeBody , int baseLength)
{
    this->length = 1;
    this->snakeFragments.push_back(snakeHead);
    this->snakeFragments.push_back(snakeBody);
    this->length++;
    this->extendSnake(baseLength);
}

void Snake::extendSnake(int amount)
{
    for (int i = 0; i < amount; i++)
    {
        Model* snakeFrag = new Model(*this->snakeFragments.at(this->length - 1));
        this->snakeFragments.push_back(snakeFrag);
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
        this->snakeFragments.at(index)->translate(vec3(0, 0, this->speed));
        this->snakeFragments.at(index)->rotate(this->angle,vec3(0.0f, 1.0f, 0.0f));
        return;
    }

    this->snakeFragments.at(index)->setModelMatrix(this->snakeFragments.at(index - 1)->getModelMatrix());
    this->move(index - 1);
}

int Snake::getLength() { return this->length; }

void Snake::renderSnakeBody(ShaderProgram* sp)
{
    for (Model* snakeBody : this->snakeFragments)
    {
        snakeBody->sendToShader(sp);
        snakeBody->activeTexture(sp);
        
        glDrawArrays(GL_TRIANGLE_FAN, 0, snakeBody->getCount());
    }

}
