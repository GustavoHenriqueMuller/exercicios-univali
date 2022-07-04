#ifndef ILLUMINATION_H
#define ILLUMINATION_H

extern bool illumination[3];

enum IlluminationType {
    ILLUMINATION_AMBIENT,
    ILLUMINATION_DIFFUSE,
    ILLUMINATION_SPECULAR
};

void initIllumination();
void setIllumination(bool ambient, bool diffuse);

#endif // ILLUMINATION_H
