#include "rangedattackstatistics.h"

RangedAttackStatistics::RangedAttackStatistics(int h, int w, int d, int sp, bool allied):AttackStatistics(h, w, d, allied)
{
    this->speed = sp;
}

int RangedAttackStatistics::getSpeed(){
    return speed;
}
