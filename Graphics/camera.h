#ifndef CAMERA_H
#define CAMERA_H

#include <vector>
#include "GameObjects/Actors/actor.h"
#include "GameObjects/Actors/player.h"
#include "GameObjects/gameobject.h"
#include <QWidget>


class Camera
{

public:
    Camera(int, QWidget *);
    std::vector<GameObject*> * snapshot(Player *, std::vector<GameObject *>);


private:
    int metersPerScreen;
    double pixPerMeter;
    int screenWidth;
    int screenHeight;
};

#endif // CAMERA_H
