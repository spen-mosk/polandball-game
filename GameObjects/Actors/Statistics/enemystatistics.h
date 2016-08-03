#ifndef ENEMYSTATISTICS_H
#define ENEMYSTATISTICS_H
#include "GameObjects/Actors/Statistics/actorstatistics.h"
#include "GameObjects/Attacks/Statistics/attackstatistics.h"
#include "GameObjects/Attacks/Statistics/meleeattackstatistics.h"
#include "GameObjects/Attacks/Statistics/rangedattackstatistics.h"


class EnemyStatistics : public ActorStatistics
{
public:
    EnemyStatistics(int, int, int, bool, int,AttackStatistics*, int, int);
    AttackStatistics* getAttackInfo();
    int getMaxJumps();
    int getAwarenessRange();
private:
    int maxJumps;
    int awareness;
    AttackStatistics* enemyAttack;

};

#endif // ENEMYSTATISTICS_H
