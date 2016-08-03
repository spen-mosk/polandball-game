#ifndef RANGEDATTACKSTATISTICS_H
#define RANGEDATTACKSTATISTICS_H

#include "GameObjects/Attacks/Statistics/attackstatistics.h"

class RangedAttackStatistics : public AttackStatistics
{
public:
    RangedAttackStatistics(int, int, int, int, bool, int);
    int getSpeed();
private:
    int speed;
};

#endif // RANGEDATTACKSTATISTICS_H
