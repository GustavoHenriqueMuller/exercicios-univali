#include "glew.h"
#include "freeglut.h"

#include "vector3.h"
#include "axis.h"
#include "loader.h"
#include "illumination.h"

#include <iostream>

#define REDISPLAY_DELAY 10

// Shaders
unsigned int program;

// VAO
unsigned int vaoId;

// Mesh / VBO
Mesh* mesh;
unsigned int vboId;
float* meshVbo;
int meshVboSize;

// Bitmap
unsigned int bitmapId, bitmapNormalId;
Bitmap *bitmapTexture, *bitmapNormalTexture;

// Scene
bool illumination[3] = {true, false, false};
float illuminationPosition[3] = {0.0f, 1.0f, 0.25f};
float illuminationColor[3] = {1.0f, 1.0f, 1.0f};
float illuminationAmbientIntensity = 0.1;
float illuminationDiffuseIntensity = 0.9;

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

    // Set lighting uniforms
    int uniformLocationLightAmbientIntensity = glGetUniformLocation(program, "lightAmbientIntensity;");
    glUniform1f(uniformLocationLightAmbientIntensity, illuminationAmbientIntensity);

    int uniformLocationLightDiffuseIntensity = glGetUniformLocation(program, "lightDiffuseIntensity");
    glUniform1f(uniformLocationLightDiffuseIntensity, illuminationDiffuseIntensity);

    int uniformLocationLightColor = glGetUniformLocation(program, "lightColor");
    glUniform3f(uniformLocationLightColor, illuminationColor[0], illuminationColor[1], illuminationColor[2]);

    int uniformLocationLightPosition = glGetUniformLocation(program, "lightPosition");
    glUniform3f(uniformLocationLightPosition, illuminationPosition[0], illuminationPosition[1], illuminationPosition[2]);

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
            illuminationAmbientIntensity += lightIncrease * 10;
            break;
        case '2': // Ambient light intensity decrease
            illuminationAmbientIntensity -= lightIncrease * 10;
            break;
        case '3': // Diffuse light intensity increase
            illuminationDiffuseIntensity += lightIncrease;
            break;
        case '4': // Diffuse light intensity decrease
            illuminationDiffuseIntensity -= lightIncrease;
            break;

        case 'j': // Set ambient light
            setIllumination(!illumination[AMBIENT], illumination[DIFFUSE]);
            break;
        case 'k': // Set diffuse light
            setIllumination(illumination[AMBIENT], !illumination[DIFFUSE]);
            break;
    }
}

int main(int argc, char** argv) {
    srand(1);

    // Initializing Freeglut
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(512, 512);
    glutInitWindowPosition(50, 50);

    glutCreateWindow("Trabalho M2");

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

    // Loading variables
    mesh = Loader::loadObj("resources/brickwallModel.obj");
    bitmapTexture = Loader::loadBmp("resources/brickwall.bmp");
    bitmapNormalTexture = Loader::loadBmp("resources/brickwallNormal.bmp");

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
    int vertexSize = Mesh::getVertexSize();

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, vertexSize, (const void*) 0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, vertexSize, (const void*) sizeof(Vector3));
    glEnableVertexAttribArray(1);

    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, vertexSize, (const void*) (sizeof(Vector3) + sizeof(Vector2)));
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
    std::string vertexShader = Loader::loadFile("resources/vertexShader.vert");
    std::string fragmentShader = Loader::loadFile("resources/fragmentShader.frag");

    program = Loader::loadProgram(vertexShader, fragmentShader);
    glUseProgram(program);

    // Binding textures to uniforms
    int uniformLocationTexture = glGetUniformLocation(program, "uniTexture");
    int uniformLocationTextureNormal = glGetUniformLocation(program, "uniTextureNormal");

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, bitmapId);
    glUniform1i(uniformLocationTexture, 0);

    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, bitmapNormalId);
    glUniform1i(uniformLocationTextureNormal, 1);

    // Main loop
    glutMainLoop();

    // Deallocating
    glDeleteProgram(program);

    delete mesh;
    delete[] meshVbo;
    delete bitmapTexture;

    return 0;
}
