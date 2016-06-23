QT          += widgets

HEADERS     = glwidget.h \
              window.h \
    actor.h
SOURCES     = glwidget.cpp \
              main.cpp \
              window.cpp \
    actor.cpp

# install
target.path = $$[QT_INSTALL_EXAMPLES]/opengl/2dpainting
INSTALLS += target
CONFIG += console
