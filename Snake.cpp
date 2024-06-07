#include "Model.h"
#include "Snake.h"

bool Snake::isCollided()
{
    mat4 snakeMat = snakeFragments[0]->getModelMatrix();
    printf("snake pos x: %.2f \n snake pos y: %.2f\n", snakeMat[3][0], snakeMat[3][1]);

    // checking snake posx and posy is in area
    if (snakeMat[3][0] > 3.0f || snakeMat[3][0] < -3.0f || snakeMat[3][1] > 3.0f || snakeMat[3][1] < -3.0f)
    {
        printf("Snake collided with wall you loose!"); exit(EXIT_SUCCESS);
        return true;
    }

    for (int i = 1; i < snakeFragments.size(); i++)
    {
        mat4 snakeMat = snakeFragments[0]->getModelMatrix();
        mat4 fragModelMat = snakeFragments.at(i)->getModelMatrix();
        float matxDiff = abs(fragModelMat[3][0] - snakeMat[3][0]);
        float matyDiff = abs(fragModelMat[3][1] - snakeMat[3][1]);
        printf("%d snake fragment  pos x: %.4f \n%d snake fragment pos y: %.4f\n", i , matxDiff, i, matyDiff);
        if (matxDiff <= 0.01f && matyDiff <= 0.01f)
        {
            printf("Snake collided with fagment %d!", i); //exit(EXIT_SUCCESS);
            //return true;
        }
    }

    return false;
}

Snake::Snake(Model* snakeHead, Model* snakeBody , int baseLength)
{
    this->length = 1;
    this->baseLength = baseLength;
    this->snakeFragments.push_back(snakeHead);
    this->snakeFragments.push_back(snakeBody);
    this->angle = 12.0f; this->move(this->getLength() - 1);
    this->length++;
    this->extendSnake(baseLength);
        
}

void Snake::extendSnake(int amount)
{
    for (int i = 0; i < amount; i++)
    {
        Model* snakeFrag = new Model(*this->snakeFragments.at(this->length - 1));
        this->snakeFragments.push_back(snakeFrag);
        this->angle = 12.0f; this->move(this->getLength() - 1);
        this->length++;
    }
}

void Snake::move(int index)
{
    if (isCollided())
    {
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
