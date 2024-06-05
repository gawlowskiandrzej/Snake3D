#include "objloader.h"

void OBJModel::loadOBJ(const char* path, float scale, float translate)
{
    std::vector< unsigned int > vertexIndices, uvIndices, normalIndices;
    std::vector< glm::vec3 > temp_vertices;
    std::vector< glm::vec2 > temp_uvs;
    std::vector< glm::vec3 > temp_normals;
    int vert_max = 0;

    FILE* file = fopen(path, "r");
    if (file == NULL) {
        printf("Impossible to open the file !\n");
    }

    while (1) {

        char lineHeader[128];
        // read the first word of the line
        int res = fscanf(file, "%s", lineHeader);
        if (res == EOF)
            break;
        if (strcmp(lineHeader, "v") == 0) {
            glm::vec3 vertex;
            fscanf(file, "%f %f %f\n", &vertex.x, &vertex.y, &vertex.z);
            if (vertex.x > vert_max)
                vert_max = vertex.x;
            if (vertex.y > vert_max)
                vert_max = vertex.y;
            if (vertex.z > vert_max)
                vert_max = vertex.z;
            temp_vertices.push_back(vertex);
        }
        else if (strcmp(lineHeader, "vt") == 0) {
            glm::vec2 uv;
            fscanf(file, "%f %f\n", &uv.x, &uv.y);
            temp_uvs.push_back(uv);
        }
        else if (strcmp(lineHeader, "vn") == 0) {
            glm::vec3 normal;
            fscanf(file, "%f %f %f\n", &normal.x, &normal.y, &normal.z);
            temp_normals.push_back(normal);
        }
        else if (strcmp(lineHeader, "f") == 0) {
            std::string vertex1, vertex2, vertex3;
            unsigned int vertexIndex[3], uvIndex[3], normalIndex[3];
            int matches = fscanf(file, "%d/%d/%d %d/%d/%d %d/%d/%d\n", &vertexIndex[0], &uvIndex[0], &normalIndex[0], &vertexIndex[1], &uvIndex[1], &normalIndex[1], &vertexIndex[2], &uvIndex[2], &normalIndex[2]);
            if (matches != 9) {
                printf("File can't be read by our simple parser : ( Try exporting with other options\n");
            }

            vertexIndices.push_back(vertexIndex[0]);
            vertexIndices.push_back(vertexIndex[1]);
            vertexIndices.push_back(vertexIndex[2]);
            uvIndices.push_back(uvIndex[0]);
            uvIndices.push_back(uvIndex[1]);
            uvIndices.push_back(uvIndex[2]);
            normalIndices.push_back(normalIndex[0]);
            normalIndices.push_back(normalIndex[1]);
            normalIndices.push_back(normalIndex[2]);
        }
    }
    glm::vec3 vert_max_glm = glm::vec3(vert_max, vert_max, vert_max);
    for (unsigned int i = 0; i < vertexIndices.size(); i++) {
        unsigned int vertexIndex = vertexIndices[i];
        glm::vec3 vertex = temp_vertices[vertexIndex - 1];
        vertex.z += translate+3;
        vertex.x *= scale*0.7;
        vertex.y *= scale;
        vertex.z *= scale*0.7;
        vertex_position.push_back(vec4(vertex,1));
    }

    for (unsigned int i = 0; i < normalIndices.size(); i++) {
        unsigned int normalIndex = normalIndices[i];
        glm::vec3 normal = temp_normals[normalIndex - 1];
        normal = glm::normalize(normal);
        vertex_normal.push_back(normal);
    }

    for (unsigned int i = 0; i < uvIndices.size(); i++) {
        unsigned int uvIndex = uvIndices[i];
        glm::vec2 uv = temp_uvs[uvIndex - 1];
        //uv = glm::normalize(uv);
        uv.x *= scale*2;
        uv.y *= scale*2;
        vertex_texcoord.push_back(uv);
    }

    this->getNormals();
    this->getPositions();
    this->getTextcoord();
}

void OBJModel::getPositions()
{
    this->verticies = new float[vertex_position.size() * 4];
    int pos = 0;

    for (int i = 0; i < vertex_position.size(); i++) {
        this->verticies[pos++] = vertex_position.at(i).x;
        this->verticies[pos++] = vertex_position.at(i).y;
        this->verticies[pos++] = vertex_position.at(i).z;
        this->verticies[pos++] = vertex_position.at(i).w;
        //this->verticies[pos++] = vertex_position.at(i).w;
    }
}

void OBJModel::getNormals()
{
    this->normals = new float[vertex_normal.size() * 3];
    int pos = 0;

    for (int i = 0; i < vertex_normal.size(); i++) {
        this->normals[pos++] = vertex_normal.at(i)[0];
        this->normals[pos++] = vertex_normal.at(i)[1];
        this->normals[pos++] = vertex_normal.at(i)[2];
        //this->normals[pos++] = result.at(i).normal[3];
    }
}

void OBJModel::getTextcoord()
{
    this->textCoord = new float[vertex_texcoord.size() * 2];
    int pos = 0;

    for (int i = 0; i < vertex_texcoord.size(); i++) {
        this->textCoord[pos++] = vertex_texcoord.at(i)[0];
        this->textCoord[pos++] = vertex_texcoord.at(i)[1];
    }
}
