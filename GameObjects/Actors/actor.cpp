#include "actor.h"
#include <stdio.h>
#include <vector>

Actor::Actor(int a, int b, ActorStatistics * stats)
    :GameObject(a, b, stats->getRadius(), stats->getRadius()){
    this->stats = stats;
    QPoint * center = this->getCenter();
    this->direction = true;
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

bool Actor::isFacingRight(){
    return direction;
}

void Actor::faceLeft(){
    direction = false;
}

void Actor::faceRight(){
    direction = true;
}
