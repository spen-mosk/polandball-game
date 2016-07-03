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
    QPoint * getPosition();
    bool contains(QPoint * point);
    void updateLocation(int,int);
    int getRadius();
    std::vector<int> getPreviousLocation();

private:
    int xMove;
    int yMove;
    int radius;
    std::vector<int> previousLocation;
};

#endif // ACTOR_H
