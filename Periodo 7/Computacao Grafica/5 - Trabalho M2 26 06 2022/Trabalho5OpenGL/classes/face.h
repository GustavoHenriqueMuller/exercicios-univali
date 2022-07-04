#ifndef FACE_H
#define FACE_H

#include <array>
#include <stdlib.h>

struct Face {
    static const int polygonsPerFace = 3;

    std::array<int, polygonsPerFace> positions;
    std::array<int, polygonsPerFace> uvs;
    std::array<int, polygonsPerFace> normals;
};

#endif // FACE_H
