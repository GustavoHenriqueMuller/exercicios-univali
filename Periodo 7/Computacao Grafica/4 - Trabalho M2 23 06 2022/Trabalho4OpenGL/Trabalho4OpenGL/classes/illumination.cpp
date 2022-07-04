#include "illumination.h"
#include "freeglut.h"

void initIllumination() {
    // Material definition
    float ambient[] = {0.05, 0.05, 0.05, 1.0};
    float diffuse[] = {0.7, 0.7, 0.7, 1.0};

    glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);

    // Light definition
    float ambientLight[] = {1.0, 1.0, 1.0, 1.0};
    float diffuseLight[] = {1.0, 1.0, 1.0, 1.0};

    glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuseLight);

    float lightPosition[] = {0.0, 0.0, 0.0, 1.0};
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);

    glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
}

void setIllumination(bool ambient, bool diffuse) {
    illumination[0] = ambient;
    illumination[1] = diffuse;

    illumination[0] ? glEnable(GL_LIGHT0) : glDisable(GL_LIGHT0);
    illumination[1] ? glEnable(GL_LIGHT1) : glDisable(GL_LIGHT1);
}
