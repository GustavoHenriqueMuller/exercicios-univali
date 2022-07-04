#ifndef FACE_H
#define FACE_H

#include "vector2.h"
#include "vector3.h"

#include <vector>
#include <stdlib.h>

struct Face {
    std::vector<int> positions;
    std::vector<int> uvs;
    std::vector<int> normals;
};


#endif // FACE_H
