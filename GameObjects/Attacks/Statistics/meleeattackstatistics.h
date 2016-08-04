#ifndef MELEEATTACKSTATISTICS_H
#define MELEEATTACKSTATISTICS_H

#include "GameObjects/Attacks/Statistics/attackstatistics.h"


class MeleeAttackStatistics : public AttackStatistics
{
public:
    MeleeAttackStatistics(int, int, int, bool, int);
};

#endif // MELEEATTACKSTATISTICS_H
