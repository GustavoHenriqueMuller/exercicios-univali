#include "glew.h"
#include "freeglut.h"
#include "mat4x4.hpp"
#include "ext/matrix_transform.hpp"
#include "gtx/string_cast.hpp"
#include "gtc/type_ptr.hpp"

#include "loader.h"
#include "illumination.h"

#include <iostream>

#define REDISPLAY_DELAY 10

enum MovementType {
    MOVEMENT_LIGHT,
    MOVEMENT_MODEL
};

enum RotationAxis {
    ROTATION_AXIS_X,
    ROTATION_AXIS_Y,
    ROTATION_AXIS_Z
};

// Shaders
unsigned int program;

// VAO
unsigned int vaoId;

// Mesh / VBO
Mesh* mesh;
unsigned int vboId;
float* meshVbo;
int meshVboSize;
glm::mat4 modelMatrix;
RotationAxis rotationAxis = ROTATION_AXIS_Z;

// Bitmap
unsigned int bitmapId, bitmapNormalId;
Bitmap *bitmapTexture, *bitmapNormalTexture;

// Scene
bool illumination[3] = {true, true, false};
float illuminationPosition[3] = {0.0f, 1.0f, 0.25f};
float illuminationColor[3] = {1.0f, 1.0f, 1.0f};
float illuminationAmbientIntensity = 0.1;
float illuminationDiffuseIntensity = 0.9;

MovementType movementType = MOVEMENT_MODEL;

// Functions
void initScene() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClearDepth(1.0f);
    glDepthFunc(GL_LESS);
    glEnable(GL_DEPTH_TEST);
    glShadeModel(GL_SMOOTH);
    initIllumination();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -10.0f);

    // Creating model matrix uniform
    modelMatrix = glm::translate(glm::mat4(1.0f), mesh->position);
    modelMatrix = glm::scale(modelMatrix, mesh->scale);
    modelMatrix = glm::rotate(modelMatrix, mesh->rotation[0], glm::vec3(1.0f, 0.0f, 0.0f));
    modelMatrix = glm::rotate(modelMatrix, mesh->rotation[1], glm::vec3(0.0f, 1.0f, 0.0f));
    modelMatrix = glm::rotate(modelMatrix, mesh->rotation[2], glm::vec3(0.0f, 0.0f, 1.0f));

    // Binding model matrix to uniform
    int uniformLocationModelMatrix = glGetUniformLocation(program, "uniModelMatrix");
    glUniformMatrix4fv(uniformLocationModelMatrix, 1, GL_FALSE, glm::value_ptr(modelMatrix));

    // Set lighting uniforms
    glUniform1f(glGetUniformLocation(program, "lightAmbientIntensity"), illuminationAmbientIntensity);
    glUniform1f(glGetUniformLocation(program, "lightAmbientActive"), illumination[ILLUMINATION_AMBIENT]);

    glUniform1f(glGetUniformLocation(program, "lightDiffuseIntensity"), illuminationDiffuseIntensity);
    glUniform1f(glGetUniformLocation(program, "lightDiffuseActive"), illumination[ILLUMINATION_DIFFUSE]);

    glUniform3f(glGetUniformLocation(program, "lightColor"), illuminationColor[0], illuminationColor[1], illuminationColor[2]);
    glUniform3f(glGetUniformLocation(program, "lightPosition"), illuminationPosition[0], illuminationPosition[1], illuminationPosition[2]);

    // Draw model
    glDrawArrays(GL_TRIANGLES, 0, mesh->faces.size() * 3);

    // Cleaning
    glutSwapBuffers();
}

void reshape(int width, int height) {
    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(45.0f, 640.0f / 480.0f, 0.1f, 1000.0f);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void redisplay(int value) {
    glutPostRedisplay();
    glutTimerFunc(REDISPLAY_DELAY, redisplay, 0);
}

void keyboard(unsigned char key, int x, int y) {
    float speed = 0.05f;
    float lightIncrease = 0.05f;

    switch (movementType) {
        case MOVEMENT_LIGHT: {
            switch (key) {
                case 'w': // Up
                    illuminationPosition[1] += speed;
                    break;
                case 'a': // Left
                    illuminationPosition[0] -= speed;
                    break;
                case 's': // Down
                    illuminationPosition[1] -= speed;
                    break;
                case 'd': // Right
                    illuminationPosition[0] += speed;
                    break;
                case 'q': // Back
                    illuminationPosition[2] -= speed;
                    break;
                case 'e': // Forward
                    illuminationPosition[2] += speed;
                    break;

                case '1': // Ambient light intensity increase
                    illuminationAmbientIntensity += lightIncrease;
                    break;
                case '2': // Ambient light intensity decrease
                    illuminationAmbientIntensity -= lightIncrease;
                    break;
                case '3': // Diffuse light intensity increase
                    illuminationDiffuseIntensity += lightIncrease;
                    break;
                case '4': // Diffuse light intensity decrease
                    illuminationDiffuseIntensity -= lightIncrease;
                    break;

                case 'j': // Set ambient light
                    setIllumination(!illumination[ILLUMINATION_AMBIENT], illumination[ILLUMINATION_DIFFUSE]);
                    break;
                case 'k': // Set diffuse light
                    setIllumination(illumination[ILLUMINATION_AMBIENT], !illumination[ILLUMINATION_DIFFUSE]);
                    break;
            }
            break;
        }

        case MOVEMENT_MODEL: {
            switch (key) {
                case 'w': // Up
                    mesh->position[1] += speed;
                    break;
                case 'a': // Left
                    mesh->position[0] -= speed;
                    break;
                case 's': // Down
                    mesh->position[1] -= speed;
                    break;
                case 'd': // Right
                    mesh->position[0] += speed;
                    break;
                case 'q': // Back
                    mesh->position[2] -= speed;
                    break;
                case 'e': // Forward
                    mesh->position[2] += speed;
                    break;

                case 'x': // Change rotation axis to x
                    rotationAxis = ROTATION_AXIS_X;
                    break;
                case 'y': // Change rotation axis to y
                    rotationAxis = ROTATION_AXIS_Y;
                    break;
                case 'z': // Change rotation axis to z
                    rotationAxis = ROTATION_AXIS_Z;
                    break;

                case 'u': // Increase in x-axis scale
                    mesh->scale[0] += speed;
                    break;
                case 'j': // Decrease in x-axis scale
                    mesh->scale[0] -= speed;
                    break;
                case 'i': // Increase in y-axis scale
                    mesh->scale[1] += speed;
                    break;
                case 'k': // Decrease in y-axis scale
                    mesh->scale[1] -= speed;
                    break;
                case 'o': // Increase in z-axis scale
                    mesh->scale[2] += speed;
                    break;
                case 'l': // Decrease in z-axis scale
                    mesh->scale[2] -= speed;
                    break;
            }
            break;
        }
    }

    // Change mode from light to model
    if (key == 'm') {
        movementType = movementType == MOVEMENT_LIGHT ? MOVEMENT_MODEL : MOVEMENT_LIGHT;
    }
}

void mouse(int button, int state, int x, int y) {
    float rotation = 0.1f;

    if (state != GLUT_UP && movementType == MOVEMENT_MODEL) {
        switch (button) {
            case 3: // Scroll up (clockwise)
                mesh->rotation[rotationAxis] += rotation;
                break;
            case 4: // Scroll down (anti-clockwise)
                mesh->rotation[rotationAxis] -= rotation;
                break;
            default:
                break;
        }
    }
}

int main(int argc, char** argv) {
    srand(1);

    // Initializing Freeglut
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(512, 512);
    glutInitWindowPosition(50, 50);

    glutCreateWindow("Trabalho 5 - M2");

    // Initializing GLEW
    if (glewInit() != GLEW_OK) {
        return -1;
    }

    // Initializing scene
    std::cout << glGetString(GL_VERSION) << std::endl;
    initScene();

    // Setting callbacks
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(REDISPLAY_DELAY, redisplay, 0);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);

    // Loading variables
    mesh = Loader::loadObj("gunModel.obj");
    bitmapTexture = Loader::loadBmp("gunTexture.bmp");
    bitmapNormalTexture = Loader::loadBmp("gunNormal.bmp");

    mesh->position = glm::vec3(0.0f, 0.0f, -2.0f);

    // Creating VAO / VBO
    glGenVertexArrays(1, &vaoId);
    glGenBuffers(1, &vboId);
    glBindVertexArray(vaoId);

    // Binding VBO
    meshVbo = Loader::loadVboFromShader(*mesh);
    meshVboSize = Loader::getMeshVboSize(*mesh);

    glBindBuffer(GL_ARRAY_BUFFER, vboId);
    glBufferData(GL_ARRAY_BUFFER, meshVboSize * sizeof(float), meshVbo, GL_STATIC_DRAW);

    // Creating VBO layout
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, Mesh::vertexSize, (const void*) 0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, Mesh::vertexSize, (const void*) sizeof(glm::vec3));
    glEnableVertexAttribArray(1);

    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, Mesh::vertexSize, (const void*) (sizeof(glm::vec3) + sizeof(glm::vec2)));
    glEnableVertexAttribArray(2);

    // Generating and binding texture
    glGenTextures(1, &bitmapId);
    glBindTexture(GL_TEXTURE_2D, bitmapId);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, bitmapTexture->sizeX, bitmapTexture->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, bitmapTexture->data);

    // Generating and binding normal texture
    glGenTextures(1, &bitmapNormalId);
    glBindTexture(GL_TEXTURE_2D, bitmapNormalId);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, bitmapNormalTexture->sizeX, bitmapNormalTexture->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, bitmapNormalTexture->data);

    // Creating shaders
    std::string vertexShader = Loader::loadFile("vertexShader.vert");
    std::string fragmentShader = Loader::loadFile("fragmentShader.frag");

    program = Loader::loadProgram(vertexShader, fragmentShader);
    glUseProgram(program);

    // Setting texture uniforms
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, bitmapId);
    glUniform1i(glGetUniformLocation(program, "uniTexture"), 0);

    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, bitmapNormalId);
    glUniform1i(glGetUniformLocation(program, "uniTextureNormal"), 1);

    // Creating projection matrix
    glm::mat4 projectionMatrix = glm::perspective(glm::radians(60.0f), 1.0f, 0.1f, 10.0f);
    glUniformMatrix4fv(glGetUniformLocation(program, "uniProjectionMatrix"), 1, GL_FALSE, glm::value_ptr(projectionMatrix));

    // Main loop
    glutMainLoop();

    // Deallocating
    glDeleteProgram(program);

    delete mesh;
    delete[] meshVbo;
    delete bitmapTexture;

    return 0;
}
