TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        CPU.c \
        files.c \
        list.c \
        main.c \
        schedulers.c

HEADERS += \
    CPU.h \
    files.h \
    list.h \
    schedulers.h \
    task.h
