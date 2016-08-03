#include "rangedattackstatistics.h"

RangedAttackStatistics::RangedAttackStatistics(int h, int w, int d, int sp, bool allied, int dl):AttackStatistics(h, w, d, allied, 0, 0, false, dl)
{
    this->speed = sp;
}

int RangedAttackStatistics::getSpeed(){
    return speed;
}
