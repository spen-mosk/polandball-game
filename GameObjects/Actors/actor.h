#ifndef ACTOR_H
#define ACTOR_H

#include <QPoint>
#include <QPainter>
#include "GameObjects/gameobject.h"
#include "GameObjects/Actors/Statistics/actorstatistics.h"
#include <vector>

class Actor : public GameObject
{

public:
    Actor(int, int, ActorStatistics * stats);
    virtual ~Actor(){};
    QPoint * getPosition();
    bool contains(QPoint * point);
    QPoint * getCenter();
    void updateLocation(int,int);
    int getRadius();
    virtual void jump() = 0;
    virtual void resetJump() = 0;
    virtual void maximizeJump() = 0;
    bool isFacingRight();
    void faceRight();
    void faceLeft();

private:
    int xMove;
    int yMove;
    ActorStatistics * stats;
    bool direction;
};

#endif // ACTOR_H
