QT          += widgets

HEADERS     = \
              Graphics/window.h \
    GameObjects/Actors/actor.h \
    Graphics/camera.h \
    level.h \
    Graphics/gamewidget.h \
    GameObjects/gameobject.h \
    GameObjects/Actors/player.h \
    GameObjects/Platforms/platform.h \
    GameObjects/Platforms/movingplatform.h \
    GameObjects/Platforms/surfacedecorator.h \
    GameObjects/Platforms/oncontactdecorator.h \
    GameObjects/tempgameobject.h \
    GameObjects/Attacks/attack.h \
    GameObjects/Attacks/meleeattack.h \
    GameObjects/Attacks/rangedattack.h \
    GameObjects/platformbuilder.h \
    GameObjects/kdtree.h
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
    GameObjects/Platforms/oncontactdecorator.cpp \
    GameObjects/tempgameobject.cpp \
    GameObjects/Attacks/meleeattack.cpp \
    GameObjects/Attacks/attack.cpp \
    GameObjects/Attacks/rangedattack.cpp \
    GameObjects/platformbuilder.cpp \
    GameObjects/kdtree.cpp

# install
target.path = $$[QT_INSTALL_EXAMPLES]/opengl/2dpainting
INSTALLS += target
CONFIG += console
