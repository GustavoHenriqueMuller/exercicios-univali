#ifndef FILEREADER_H
#define FILEREADER_H

#include "mesh.h"
#include "bitmap.h"

#include <string>
#include <vector>

namespace Loader {
    Mesh* loadObj(const std::string &path);
    float* loadVboFromShader(const Mesh &mesh);
    int getMeshVboSize(const Mesh &mesh);

    Bitmap* loadBmp(const std::string &filename);
    unsigned int loadProgram(const std::string &vertexShader, const std::string &fragmentShader);
    unsigned int loadShader(unsigned int type, const std::string &shader);
    std::string loadFile(const std::string &path);
}

#endif // FILEREADER_H
