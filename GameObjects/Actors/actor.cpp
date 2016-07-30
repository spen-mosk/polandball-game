#include "actor.h"
#include <stdio.h>
#include <vector>

Actor::Actor(int a, int b, ActorStatistics * stats)
    :GameObject(a, b, 2*stats->getRadius(), 2*stats->getRadius(), stats->getRadius()){

    this->stats = stats;
    QPoint * center = this->getCenter();
}

void Actor::updateLocation(int xOffset, int yOffset){
    setX(this->x() + xOffset);
    setY(this->y() + yOffset);
}

void Actor::handleCollision(GameObject * obj){
}

void Actor::update(){
    if(getGrav()){
        this->updateLocation(0, -stats->getGravity());
    }
}

void Actor::setFacing(bool left){
    this->faceLeft = left;
}

bool Actor::facingLeft(){
    return faceLeft;
}

int Actor::getRadius(){
    return stats->getRadius();
}

QPoint * Actor::getCenter(){
    QPoint * point = new QPoint(x() + stats->getRadius(), y() - stats->getRadius());
    return point;
}
