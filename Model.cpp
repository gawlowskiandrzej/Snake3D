#include "Model.h"

Model::Model(float* vertexPosition, float* vertexTexCoord, float* vertexNormal, unsigned int vertexCount)
{
    // Initialize verts to models
    this->vertexPosition = vertexPosition;
    this->vertexNormal = vertexNormal;
    this->vertexTexCoord = vertexTexCoord;
    this->vertexCount = vertexCount;
}

void Model::setModelMatrix(mat4 modelMatrix) { this->modelMatrix = modelMatrix; }

mat4 Model::getModelMatrix() { return this->modelMatrix; }

void Model::rotate(float rotation, vec3 axis) { this->modelMatrix = glm::rotate(this->modelMatrix, radians(rotation), axis);}

void Model::scale(vec3 scale) { this->modelMatrix = glm::scale(this->modelMatrix, scale); }

void Model::translate(vec3 translate) { this->modelMatrix = glm::translate(this->modelMatrix, translate); }

void Model::readTextureFromPng(const char* filePath)
{
    glActiveTexture(GL_TEXTURE0);

    //Wczytanie do pamiêci komputera
    std::vector<unsigned char> image;   //Alokuj wektor do wczytania obrazka
    unsigned width, height;   //Zmienne do których wczytamy wymiary obrazka
    //Wczytaj obrazek
    unsigned error = lodepng::decode(image, width, height, filePath);

    //Import do pamiêci karty graficznej
    glGenTextures(1, this->texture); //Zainicjuj jeden uchwyt
    glBindTexture(GL_TEXTURE_2D, *this->texture); //Uaktywnij uchwyt
    //Wczytaj obrazek do pamiêci KG skojarzonej z uchwytem
    glTexImage2D(GL_TEXTURE_2D, 0, 4, width, height, 0,
        GL_RGBA, GL_UNSIGNED_BYTE, (unsigned char*)image.data());

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

}

void Model::sendToShader(ShaderProgram* sp)
{
    glUniformMatrix4fv(sp->u("M"), 1, false, glm::value_ptr(this->modelMatrix));

    // Send object to GPU
    glVertexAttribPointer(sp->a("vertex"), 4, GL_FLOAT, false, 0, this->vertexPosition);
    glVertexAttribPointer(sp->a("texCoord"), 2, GL_FLOAT, false, 0, this->vertexTexCoord);
    //glVertexAttribPointer(sp->a("normal"), 4, GL_FLOAT, false, 0, this->vertexNormal);
}

void Model::activeTexture(ShaderProgram* sp)
{
    glUniform1i(sp->u("tex"), 0);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, *this->texture);
}
