#include "objloader.h"

void OBJModel::loadOBJ(const char* filename)
{
    std::stringstream stream;
    std::ifstream input(filename);

    std::string line;
    GLint temp_glint;
    std::string prefix = "";

    vec4 temp_vec4(1.0f);
    vec2 temp_vec2;

    std::vector<GLint> vertex_position_indicies;
    std::vector<GLint> vertex_texcoord_indicies;
    std::vector<GLint> vertex_normal_indicies;

    if (!input.is_open()) {
        printf("Cannot open file ");
        return;
    }

    while (std::getline(input, line)) {
        stream.clear();
        stream.str(line);
        stream >> prefix;

        if (prefix == "v") {
            temp_vec4.w = 1.0f;
            stream >> temp_vec4.x >> temp_vec4.y >> temp_vec4.z;
            vertex_position.push_back(temp_vec4);
        }

        else if (prefix == "vt") {
            stream >> temp_vec2.x >> temp_vec2.y;
            vertex_texcoord.push_back(temp_vec2);
        }

        else if (prefix == "vn") {
            temp_vec4.w = 0.0f;
            stream >> temp_vec4.x >> temp_vec4.y >> temp_vec4.z;
            vertex_normal.push_back(temp_vec4);
        }

        else if (prefix == "f") {
            int c = 0;
            while (stream >> temp_glint) {
                if (c == 0)
                    vertex_position_indicies.push_back(temp_glint);
                else if (c == 1)
                    vertex_texcoord_indicies.push_back(temp_glint);
               else if (c == 2)
                    vertex_normal_indicies.push_back(temp_glint);

                if (stream.peek() == '/') { ++c; stream.ignore(1, '/'); }
                else if (stream.peek() == ' ') { ++c; stream.ignore(1, ' '); }

                if (c > 1) c = 0;
            }
        }
        result.resize(vertex_position_indicies.size(), Vertex());

        for (int i = 0; i < result.size(); ++i)
        {
            result[i].position = vertex_position[vertex_position_indicies[i] - 1];
            result[i].texCoord = vertex_texcoord[vertex_position_indicies[i] - 1];
            //result[i].normal = vertex_normal[vertex_normal_indicies[i] - 1];
            result[i].color = vec3(1, 1, 1);
        }
    }
    this->getNormals();
    this->getPositions();
    this->getTextcoord();
}

void OBJModel::getPositions()
{
    this->verticies = new float[result.size() * 4];
    int pos = 0;

    for (int i = 0; i < result.size(); i++) {
        this->verticies[pos++] = result.at(i).position.x;
        this->verticies[pos++] = result.at(i).position.y;
        this->verticies[pos++] = result.at(i).position.z;
        this->verticies[pos++] = result.at(i).position.w;
    }
}

void OBJModel::getNormals()
{
    this->normals = new float[result.size() * 4];
    int pos = 0;

    for (int i = 0; i < result.size(); i++) {
        this->normals[pos++] = result.at(i).normal[0];
        this->normals[pos++] = result.at(i).normal[1];
        this->normals[pos++] = result.at(i).normal[2];
        this->normals[pos++] = result.at(i).normal[3];
    }
}

void OBJModel::getTextcoord()
{
    this->textCoord = new float[result.size() * 2];
    int pos = 0;

    for (int i = 0; i < result.size(); i++) {
        this->textCoord[pos++] = result.at(i).texCoord[0];
        this->textCoord[pos++] = result.at(i).texCoord[1];
    }
}
