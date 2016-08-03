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
    Actor(int, int, ActorStatistics * stats, int);
    virtual ~Actor(){};
    QPoint * getPosition();
    bool contains(QPoint * point);
    QPoint * getCenter();
    void setFacing(bool left);
    bool facingLeft();
    void updateLocation(int,int);
    int getRadius();
    virtual void jump() = 0;
    virtual void resetJump() = 0;
    virtual void maximizeJump() = 0;
    virtual void update();
    void handleCollision(GameObject*);
    bool isAlly();


private:
    static int num;
    int xMove;
    int yMove;
    ActorStatistics * stats;
    bool faceLeft;
    bool ally;
};

#endif // ACTOR_H
