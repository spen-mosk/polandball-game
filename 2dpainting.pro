QT          += widgets

HEADERS     = \
              window.h \
    actor.h \
    camera.h \
    level.h \
    gamewidget.h \
    inputhandler.h
SOURCES     = \
              main.cpp \
              window.cpp \
    actor.cpp \
    camera.cpp \
    level.cpp \
    gamewidget.cpp \
    inputhandler.cpp

# install
target.path = $$[QT_INSTALL_EXAMPLES]/opengl/2dpainting
INSTALLS += target
CONFIG += console
