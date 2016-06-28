#ifndef CAMERA_H
#define CAMERA_H

#include <vector>
#include "actor.h"
#include "gameobject.h"
#include <QWidget>


class Camera
{

public:
    Camera(int, QWidget *);
    std::vector<GameObject*> * snapshot(GameObject *, std::vector<GameObject *>);


private:
    int metersPerScreen;
    double pixPerMeter;
    int screenWidth;
    int screenHeight;
};

#endif // CAMERA_H
