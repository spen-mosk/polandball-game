#include "attackstatistics.h"

AttackStatistics::AttackStatistics(int h, int w, int d, bool allied)
{
    this->height = h;
    this->width = w;
    this->maxDuration = d;
    this->ally = allied;
}

int AttackStatistics::getHeight(){
    return height;
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
