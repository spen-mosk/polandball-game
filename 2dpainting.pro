QT          += widgets

HEADERS     = \
              Graphics/window.h \
    GameObjects/Actors/actor.h \
    camera.h \
    level.h \
    Graphics/gamewidget.h \
    GameObjects/gameobject.h \
    GameObjects/Actors/player.h \
    GameObjects/Platforms/platform.h \
    GameObjects/Platforms/movingplatform.h \
    GameObjects/Platforms/surfacedecorator.h \
    GameObjects/Platforms/oncontactdecorator.h
SOURCES     = \
              main.cpp \
              Graphics/window.cpp \
    GameObjects/Actors/actor.cpp \
    Graphics/camera.cpp \
    level.cpp \
    Graphics/gamewidget.cpp \
    GameObjects/gameobject.cpp \
    GameObjects/Actors/player.cpp \
    GameObjects/Platforms/platform.cpp \
    GameObjects/Platforms/movingplatform.cpp \
    GameObjects/Platforms/surfacedecorator.cpp \
    GameObjects/Platforms/oncontactdecorator.cpp

# install
target.path = $$[QT_INSTALL_EXAMPLES]/opengl/2dpainting
INSTALLS += target
CONFIG += console
