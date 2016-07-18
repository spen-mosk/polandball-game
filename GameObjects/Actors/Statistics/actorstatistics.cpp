#include "actorstatistics.h"

ActorStatistics::ActorStatistics(int radius, int maxhealth, int speed, bool ally)
{
    this->radius = radius;
    this->maxhealth = maxhealth;
    this->speed = speed;
    this->ally = ally;
}

int ActorStatistics::getHealth(){
    return this->health;
}

int ActorStatistics::getRadius(){
    return this->radius;
}

bool ActorStatistics::isAlly(){
    return this->ally;
}
