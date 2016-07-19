#include "actor.h"
#include <stdio.h>
#include <vector>

Actor::Actor(int a, int b, ActorStatistics * stats)
    :GameObject(a, b, stats->getRadius(), stats->getRadius()){
    this->stats = stats;
    QPoint * center = this->getCenter();
}

void Actor::updateLocation(int xOffset, int yOffset){
    setX(this->getX() + xOffset);
    setY(this->getY() + yOffset);
}

int Actor::getRadius(){
    return stats->getRadius();
}

QPoint * Actor::getCenter(){
    QPoint * point = new QPoint(getX() + stats->getRadius(), getY() - stats->getRadius());
    return point;
}
