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
    PlayerStatistics(int, int, int, bool, int, AttackStatistics*, AttackStatistics*, AttackStatistics*, int, int);
    AttackStatistics* getMeleeInfo();
    AttackStatistics* getRangedInfo();
    AttackStatistics* getUltInfo();
    int getMaxJumps();
    int getVertSpeed();

private:
    AttackStatistics* primary;
    AttackStatistics* secondary;
    AttackStatistics* tertiary;
    int maxJump;
    int verticalSpeed;
};

#endif // PLAYERSTATISTICS_H
