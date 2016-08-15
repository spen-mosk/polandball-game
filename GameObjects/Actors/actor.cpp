#include "actor.h"
#include "enemy.h"
#include <stdio.h>
#include <vector>

int Actor::num = 0;

Actor::Actor(int a, int b, ActorStatistics * stats, int collRad)
    :GameObject(a, b, 2*stats->getRadius(), 2*stats->getRadius(), collRad, "Actor"+
                                std::to_string(Actor::num++)){

    this->stats = stats;
    QPoint * center = this->getCenter();
}

bool Actor::isAlly(){
    return ally;
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
