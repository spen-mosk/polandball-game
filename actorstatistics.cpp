#include "actorstatistics.h"

ActorStatistics::ActorStatistics(int x, int y, int radius, int health, int speed, bool ally)
{
    this->x = x;
    this->y = y;
    this->radius = radius;
    this->health = health;
    this->speed = speed;
    this->ally = ally;
}

int ActorStatistics::getHealth(){
    return this->health;
}

int ActorStatistics::getX(){
    return this->x;
}

int ActorStatistics::getY(){
    return this->y;
}

int ActorStatistics::getRadius(){
    return this->radius;
}

bool ActorStatistics::isAlly(){
    return this->ally;
}
