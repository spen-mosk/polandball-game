#include "ultimateattackstatistics.h"

UltimateAttackStatistics::UltimateAttackStatistics(int h, int w, int d, int s, bool allied, bool melee):MeleeAttackStatistics(h,w,d,allied),RangedAttackStatistics(h,w,d,s,allied)
{
    this->attackType = melee;
}

bool UltimateAttackStatistics::isMelee(){
    return attackType;
}
