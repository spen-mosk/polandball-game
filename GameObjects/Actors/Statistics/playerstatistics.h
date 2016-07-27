#ifndef PLAYERSTATISTICS_H
#define PLAYERSTATISTICS_H
#include <vector>
#include "actorstatistics.h"
#include "GameObjects/Attacks/Statistics/meleeattackstatistics.h"
#include "GameObjects/Attacks/Statistics/rangedattackstatistics.h"
#include "GameObjects/Attacks/Statistics/ultimateattackstatistics.h"

class PlayerStatistics : public ActorStatistics
{
public:
    PlayerStatistics(int, int, int, bool, int, AttackStatistics*, AttackStatistics*, AttackStatistics*, int);
    AttackStatistics* getMeleeInfo();
    AttackStatistics* getRangedInfo();
    AttackStatistics* getUltInfo();
    int getMaxJumps();

private:
    AttackStatistics* primary;
    AttackStatistics* secondary;
    AttackStatistics* tertiary;
    int maxJump;
};

#endif // PLAYERSTATISTICS_H
