#ifndef ACTOR_H
#define ACTOR_H

#include <QPoint>
#include <QPainter>
#include "GameObjects/gameobject.h"
#include <vector>

class Actor : public GameObject
{

public:
    Actor(int, int, int);
    virtual ~Actor(){};
    QPoint * getPosition();
    bool contains(QPoint * point);
    QPoint * getCenter();
    void updateLocation(int,int);
    int getRadius();
    virtual void jump() = 0;
    virtual void resetJump() = 0;
    virtual void maximizeJump() = 0;

private:
    int xMove;
    int yMove;
    int radius;
};

#endif // ACTOR_H
