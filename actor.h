#ifndef ACTOR_H
#define ACTOR_H

#include <QPoint>
#include <QPainter>
#include "gameobject.h"

class Actor : public GameObject
{
public:
    Actor(int, int, int);
    QPoint * getPosition();
    bool contains(QPoint * point);
    void updateLocation(int,int);
    virtual void update() = 0;
    int getRadius();

private:
    int xMove;
    int yMove;
    int radius;
};

#endif // ACTOR_H
