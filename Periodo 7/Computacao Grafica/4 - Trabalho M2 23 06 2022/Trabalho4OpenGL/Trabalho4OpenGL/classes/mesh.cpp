#include "mesh.h"
#include "vector3.h"

#include <iostream>

int Mesh::getVertexSize() {
    return sizeof(Vector3) + sizeof(Vector2) + sizeof(Vector3);
}

void Mesh::translateBy(Vector3 translation) {
    this->position = addVector3(this->position, translation);

    for (int i = 0; i < this->vertexPositions.size(); i++) {
        this->vertexPositions[i] = addVector3(this->vertexPositions[i], translation);
    }
}

void Mesh::scaleBy(Scale scale) {
    this->scale.x = this->scale.x * scale.x;
    this->scale.y = this->scale.y * scale.y;
    this->scale.z = this->scale.z * scale.z;

    for (int i = 0; i < this->vertexPositions.size(); i++) {
        Vector3 direction = subtractVector3(this->vertexPositions[i], this->position);
        direction = scaleVector3(direction, scale);

        this->vertexPositions[i] = addVector3(this->position, direction);
    }
}

void Mesh::rotateBy(float angle, Axis axis) {
    if (axis.x) this->rotation.x += angle;
    if (axis.y) this->rotation.y += angle;
    if (axis.z) this->rotation.z += angle;

    Vector3 tempPosition = this->position;
    this->translateBy({-tempPosition.x, -tempPosition.y, -tempPosition.z});

    for (int i = 0; i < this->vertexPositions.size(); i++) {
        this->vertexPositions[i] = rotateVector3(this->vertexPositions[i], angle, axis);
    }

    this->translateBy(tempPosition);
}
