TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    bfs.cpp \
    connection.cpp \
    dfs.cpp \
    operations.cpp \
    screen.cpp \
    utils.cpp

HEADERS += \
    bfs.h \
    connection.h \
    dfs.h \
    graph.h \
    operations.h \
    screen.h \
    utils.h
