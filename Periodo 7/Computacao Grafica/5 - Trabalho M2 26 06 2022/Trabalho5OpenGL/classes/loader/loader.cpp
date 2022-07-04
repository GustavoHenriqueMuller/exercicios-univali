#include "glew.h"
#include "freeglut.h"
#include "loader.h"

#include "vec3.hpp"
#include "vec2.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

Mesh* Loader::loadObj(const std::string &path) {
    std::cout << "Loading OBJ file from '" << path << "'..." << std::endl;

    Mesh* mesh = new Mesh();
    FILE* file = fopen(path.c_str(), "r");

    if (file == NULL) {
        printf("Impossible to open file!\n");
        exit(-1);
    }

    while (true) {
        char lineHeader[128];
        int res = fscanf(file, "%s", lineHeader);

        if (res == EOF) {
            break;
        }

        if (strcmp(lineHeader, "v") == 0) {
            glm::vec3 position;
            fscanf(file, "%f %f %f\n", &position[0], &position[1], &position[2]);
            mesh->vertexPositions.push_back(position);
        } else if (strcmp(lineHeader, "vt") == 0) {
            glm::vec2 uv;
            fscanf(file, "%f %f\n", &uv[0], &uv[1]);
            mesh->vertexUvs.push_back(uv);
        } else if (strcmp(lineHeader, "vn") == 0) {
            glm::vec3 normal;
            fscanf(file, "%f %f %f\n", &normal[0], &normal[1], &normal[2]);
            mesh->vertexNormals.push_back(normal);
        } else if (strcmp(lineHeader, "f") == 0) {
            unsigned int vertexIndex[3], uvIndex[3], normalIndex[3];
            int matches = fscanf(file, "%d/%d/%d %d/%d/%d %d/%d/%d\n",
                                 &vertexIndex[0], &uvIndex[0], &normalIndex[0],
                                 &vertexIndex[1], &uvIndex[1], &normalIndex[1],
                                 &vertexIndex[2], &uvIndex[2], &normalIndex[2]
                          );

            if (matches != 9) {
                printf("File can't be read. Try exporting with other options\n");
                exit(-1);
            }

            Face face;
            for (int i = 0; i < 3; i++) {
                face.positions[i] = vertexIndex[i] - 1;
                face.uvs[i] = uvIndex[i] - 1;
                face.normals[i] = normalIndex[i] - 1;
            }

            mesh->faces.push_back(face);
        } else {
            char commentBuffer[1000];
            fgets(commentBuffer, 1000, file);
        }
    }

    std::cout << "File loaded successfully." << std::endl;
    fclose(file);

    return mesh;
}

float* Loader::loadVboFromShader(const Mesh &mesh) {
    float* vbo = new float[getMeshVboSize(mesh)];

    for (int i = 0; i < mesh.faces.size(); i++) {
        const Face* face = &mesh.faces[i];
        int faceIndex = i * Face::polygonsPerFace * Mesh::vertexComponentAmount;

        for (int j = 0; j < face->positions.size(); j++) {
            int baseIndex = faceIndex + j * Mesh::vertexComponentAmount;

            vbo[baseIndex] = mesh.vertexPositions[face->positions[j]].x;
            vbo[baseIndex + 1] = mesh.vertexPositions[face->positions[j]].y;
            vbo[baseIndex + 2] = mesh.vertexPositions[face->positions[j]].z;

            vbo[baseIndex + 3] = mesh.vertexUvs[face->uvs[j]].x;
            vbo[baseIndex + 4] = mesh.vertexUvs[face->uvs[j]].y;

            vbo[baseIndex + 5] = mesh.vertexNormals[face->normals[j]].x;
            vbo[baseIndex + 6] = mesh.vertexNormals[face->normals[j]].y;
            vbo[baseIndex + 7] = mesh.vertexNormals[face->normals[j]].z;
        }
    }

    return vbo;
}

int Loader::getMeshVboSize(const Mesh &mesh) {
    return mesh.faces.size() * Face::polygonsPerFace * Mesh::vertexComponentAmount;
}

Bitmap* Loader::loadBmp(const std::string &filename) {
    Bitmap* bmp = new Bitmap;
    unsigned int size, offset, headerSize;

    // Ler o arquivo de entrada
    std::ifstream infile(filename.c_str(), std::ios::binary);

    // Pegar o ponto inicial de leitura
    infile.seekg(10);
    infile.read((char*) &offset, 4);

    // Pegar o tamanho do cabealho do bmp.
    infile.read((char*) &headerSize, 4);

    // Pegar a altura e largura da imagem no cabecalho do bmp.
    infile.seekg(18);
    infile.read((char*) &bmp->sizeX, 4);
    infile.read((char*) &bmp->sizeY, 4);

    // Alocar o buffer para a imagem.
    size = bmp->sizeX * bmp->sizeY * 24;
    bmp->data = new unsigned char[size];

    // Ler a informacao da imagem.
    infile.seekg(offset);
    infile.read((char*) bmp->data, size);

    // Reverte a cor de bgr para rgb
    int temp;
    for (int i = 0; i < size; i += 3) {
        temp = bmp->data[i];
        bmp->data[i] = bmp->data[i + 2];
        bmp->data[i + 2] = temp;
    }

    return bmp;
}

unsigned int Loader::loadProgram(const std::string &vertexShader, const std::string &fragmentShader) {
    unsigned int program = glCreateProgram();
    unsigned int vs = loadShader(GL_VERTEX_SHADER, vertexShader);
    unsigned int fs = loadShader(GL_FRAGMENT_SHADER, fragmentShader);

    glAttachShader(program, vs);
    glAttachShader(program, fs);

    glLinkProgram(program);
    glValidateProgram(program);

    glDeleteShader(vs);
    glDeleteShader(fs);

    return program;
}

unsigned int Loader::loadShader(unsigned int type, const std::string &shader) {
    int shaderId = glCreateShader(type);
    const char* src = shader.c_str();

    glShaderSource(shaderId, 1, &src, nullptr);
    glCompileShader(shaderId);

    // Error handling
    int result;
    glGetShaderiv(shaderId, GL_COMPILE_STATUS, &result);

    if (result == GL_FALSE) {
        int length;
        glGetShaderiv(shaderId, GL_INFO_LOG_LENGTH, &length);

        char* message = (char*) alloca(length * sizeof(char));
        glGetShaderInfoLog(shaderId, length, &length, message);

        std::cout << "Failed to compile shader: " << message << std::endl;
        exit(-1);
    }

    return shaderId;
}

std::string Loader::loadFile(const std::string &path) {
    std::ifstream file;
    std::string line;
    std::stringstream content;

    file.open(path.c_str());

    while(getline(file, line))
        content << line << "\n";

    file.close();
    return content.str();
}
