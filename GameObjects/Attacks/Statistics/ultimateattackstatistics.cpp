#include "ultimateattackstatistics.h"

UltimateAttackStatistics::UltimateAttackStatistics(int h, int w, int d, int s, bool allied, bool melee, int dl):MeleeAttackStatistics(h,w,d,allied, dl),RangedAttackStatistics(h,w,d,s,allied, dl)
{
    this->attackType = melee;
}

bool UltimateAttackStatistics::isMelee(){
    return attackType;
}
