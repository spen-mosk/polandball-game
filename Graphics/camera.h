#ifndef CAMERA_H
#define CAMERA_H

#include <vector>
#include "GameObjects/kdtree.h"
#include "GameObjects/Actors/actor.h"
#include "GameObjects/Actors/player.h"
#include "GameObjects/gameobject.h"
#include <QWidget>

class Camera
{

public:
    Camera(int, QWidget *);
    ~Camera();
    std::vector<GameObject*> * snapshot(Player *, KDTree<GameObject*> *);


private:
    int metersPerScreen;
    double pixPerMeter;
    double screenWidth;
    double screenHeight;
};

#endif // CAMERA_H
