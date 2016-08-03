#include "attackstatistics.h"

AttackStatistics::AttackStatistics(int h, int w, int d, bool allied, int dmg, int speed, bool isMelee, int dlay)
{
    this->height = h;
    this->damage = dmg;
    this->width = w;
    this->maxDuration = d;
    this->ally = allied;
    this->speed = speed;
    this->melee = isMelee;
    this->delay = dlay;
}

int AttackStatistics::getHeight(){
    return height;
}

int AttackStatistics::getSpeed(){
    return speed;
}

bool AttackStatistics::isMelee(){
    return melee;
}

int AttackStatistics::getDamage(){
    return damage;
}

int AttackStatistics::getWidth(){
    return width;
}

int AttackStatistics::getDuration(){
    return maxDuration;
}

bool AttackStatistics::isAlly(){
    return ally;
}

int AttackStatistics::getDelay(){
    return delay;
}
