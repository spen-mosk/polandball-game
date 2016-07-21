#ifndef ULTIMATEATTACKSTATISTICS_H
#define ULTIMATEATTACKSTATISTICS_H

#include "GameObjects/Attacks/Statistics/meleeattackstatistics.h"
#include "GameObjects/Attacks/Statistics/rangedattackstatistics.h"

class UltimateAttackStatistics : public MeleeAttackStatistics,RangedAttackStatistics
{
public:
    UltimateAttackStatistics(int, int, int, int, bool, bool);
    bool isMelee();
private:
    bool attackType;
};

#endif // ULTIMATEATTACKSTATISTICS_H
