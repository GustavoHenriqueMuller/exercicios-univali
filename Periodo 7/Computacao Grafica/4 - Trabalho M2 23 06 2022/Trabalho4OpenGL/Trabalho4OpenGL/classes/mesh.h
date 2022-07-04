#ifndef MESH_H
#define MESH_H

#include "vector3.h"
#include "vector2.h"
#include "scale.h"
#include "rotation.h"
#include "face.h"

#include <vector>

struct Mesh {
    Vector3 position = {0, 0, 0};
    Rotation rotation = {0, 0, 0};
    Scale scale = {1, 1, 1};

    std::vector<Vector3> vertexPositions;
    std::vector<Vector2> vertexUvs;
    std::vector<Vector3> vertexNormals;
    std::vector<Face> faces;

    static int getVertexSize();

    void translateBy(Vector3 translation);
    void scaleBy(Scale scale);
    void rotateBy(float angle, Axis axis);
};

#endif // MESH_H
