#include "actor.h"
#include <stdio.h>
#include <vector>

Actor::Actor(int a, int b, int radius)
    :GameObject(a, b, radius, radius){
    this->radius = radius;
    QPoint * center = this->getCenter();
}

void Actor::updateLocation(int xOffset, int yOffset){
    std::vector<int> temp;
    QPoint * center = getCenter();
    temp.push_back(center->x());
    temp.push_back(center->y());
    setX(this->getX() + xOffset);
    setY(this->getY() + yOffset);
}

int Actor::getRadius(){
    return this->radius;
}

QPoint * Actor::getCenter(){
    QPoint * point = new QPoint(getX() + radius, getY() - radius);
    return point;
}
