#include "actor.h"
#include <stdio.h>
#include <vector>

Actor::Actor(int a, int b, int radius)
    :GameObject(a, b, radius, radius){
    this->radius = radius;
    previousLocation.push_back(a);
    previousLocation.push_back(b);
}

void Actor::updateLocation(int xOffset, int yOffset){
    temp = std::vector<int>;
    temp.push_back(this->getX());
    temp.push_back(this->getY());
    previousLocation = std::vector<int>;
    setX(this->getX() + xOffset);
    setY(this->getY() + yOffset);
}

int Actor::getRadius(){
    return this->radius;
}

std::vector Actor::getPreviousLocation(){
    return previousLocation;
}


