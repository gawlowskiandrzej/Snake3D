#ifndef OBJLOADER_H
#define OBJLOADER_H

#include "libraries.h"
#include <fstream>
#include <sstream>

struct Vertex {
    glm::fvec4 position;
    glm::fvec2 texCoord;
    glm::fvec3 color;
    glm::fvec4 normal;
};

class OBJModel {
public:

    float* verticies;
    float* textCoord;
    float* normals;

    std::vector<glm::vec4> vertex_position;
    std::vector<glm::vec3> vertex_normal;
    std::vector<glm::vec2> vertex_texcoord;

    std::vector<Vertex> result;

    void loadOBJ(const char* filename, float scale, float translate);

    void getPositions();
    void getNormals();
    void getTextcoord();

};


#endif
