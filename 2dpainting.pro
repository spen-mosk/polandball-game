QT          += widgets

HEADERS     = \
              window.h \
    actor.h \
    camera.h \
    level.h \
    gamewidget.h \
    gameobject.h \
    player.h \
    platform.h \
    movingplatform.h \
    surfacedecorator.h \
    oncontactdecorator.h
SOURCES     = \
              main.cpp \
              window.cpp \
    actor.cpp \
    camera.cpp \
    level.cpp \
    gamewidget.cpp \
    gameobject.cpp \
    player.cpp \
    platform.cpp \
    movingplatform.cpp \
    surfacedecorator.cpp \
    oncontactdecorator.cpp

# install
target.path = $$[QT_INSTALL_EXAMPLES]/opengl/2dpainting
INSTALLS += target
CONFIG += console
