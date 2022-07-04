#ifndef MESH_H
#define MESH_H

#include "vec2.hpp"
#include "vec3.hpp"

#include "face.h"

#include <vector>

struct Mesh {
    glm::vec3 position = {0.0f, 0.0f, 0.0f};
    glm::vec3 scale = {1.0f, 1.0f, 1.0f};
    glm::vec3 rotation = {0.0f, 0.0f, 0.0f};

    std::vector<glm::vec3> vertexPositions;
    std::vector<glm::vec2> vertexUvs;
    std::vector<glm::vec3> vertexNormals;
    std::vector<Face> faces;

    static const int vertexSize = sizeof(glm::vec3) + sizeof(glm::vec2) + sizeof(glm::vec3);
    static const int vertexComponentAmount = 8;
};

#endif // MESH_H
