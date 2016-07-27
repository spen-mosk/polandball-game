#include "actorstatistics.h"

ActorStatistics::ActorStatistics(int radius, int maxhealth, int speed, bool ally, int grav)
{
    this->radius = radius;
    this->maxhealth = maxhealth;
    this->speed = speed;
    this->ally = ally;
    this->grav = grav;
}

int ActorStatistics::getMaxHealth(){
    return this->maxhealth;
}

int ActorStatistics::getGravity(){
    return grav;
}

int ActorStatistics::getSpeed(){
    return speed;
}

int ActorStatistics::getRadius(){
    return this->radius;
}

bool ActorStatistics::isAlly(){
    return this->ally;
}
