#include "actor.h"
#include <stdio.h>

Actor::Actor(int a, int b, int radius)
    :GameObject(a, b, radius, radius){
    this->radius = radius;
}

void Actor::updateLocation(int xOffset, int yOffset){
    setX(this->getX() + xOffset);
    setY(this->getY() + yOffset);
}

int Actor::getRadius(){
    return this->radius;
}
