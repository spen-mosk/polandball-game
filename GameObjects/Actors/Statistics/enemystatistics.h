#ifndef ENEMYSTATISTICS_H
#define ENEMYSTATISTICS_H
#include "GameObjects/Actors/Statistics/actorstatistics.h"
#include "GameObjects/Attacks/Statistics/attackstatistics.h"
#include "GameObjects/Attacks/Statistics/meleeattackstatistics.h"
#include "GameObjects/Attacks/Statistics/rangedattackstatistics.h"


class EnemyStatistics : public ActorStatistics
{
public:
    EnemyStatistics(int, int, int, bool, int,AttackStatistics*, int);
    AttackStatistics* getAttackInfo();
    int getMaxJumps();
private:
    int maxJumps;
    AttackStatistics* enemyAttack;

};

#endif // ENEMYSTATISTICS_H
