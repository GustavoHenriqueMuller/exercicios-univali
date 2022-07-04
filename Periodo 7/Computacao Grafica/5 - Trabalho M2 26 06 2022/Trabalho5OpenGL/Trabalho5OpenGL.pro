TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    classes/illumination.cpp \
    classes/loader/loader.cpp

DEFINES += GLEW_STATIC

INCLUDEPATH += $$PWD/classes \
               $$PWD/classes/loader

# GLEW (statically linked with libglew32s.lib)
win32: LIBS += $$PWD/dependencies/glew/lib/libglew32s.lib

INCLUDEPATH += $$PWD/dependencies/glew/include/GL
DEPENDPATH += $$PWD/dependencies/glew/include/GL

win32:!win32-g++: PRE_TARGETDEPS += $$PWD/dependencies/glew/lib/libglew32s.lib
else:win32-g++: PRE_TARGETDEPS += $$PWD/dependencies/glew/lib/libglew32s.lib

# Freeglut (statically linked with include lib (libfreeglut.a) and dynamically linked with .dll in debug build folder)
win32: LIBS += -lopengl32 -lglu32
win32: LIBS += $$PWD/dependencies/freeglut/lib/libfreeglut.a

INCLUDEPATH += $$PWD/dependencies/freeglut/include/FreeGL
DEPENDPATH += $$PWD/dependencies/freeglut/include/FreeGL

win32:!win32-g++: PRE_TARGETDEPS += $$PWD/dependencies/freeglut/lib/libfreeglut.a
else:win32-g++: PRE_TARGETDEPS += $$PWD/dependencies/freeglut/lib/libfreeglut.a

# GLM
INCLUDEPATH += $$PWD/dependencies/glm

HEADERS += \
    classes/bitmap.h \
    classes/face.h \
    classes/illumination.h \
    classes/mesh.h \
    classes/loader/loader.h

DISTFILES += \
    resources/diceModel.obj \
    resources/diceTexture.png \
    resources/fragmentShader.frag \
    resources/shaders/fragmentShader.frag \
    resources/shaders/vertexShader.vert \
    resources/vertexShader.vert

