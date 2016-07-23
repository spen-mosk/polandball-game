#include "enemystatistics.h"

EnemyStatistics::EnemyStatistics(int radius, int speed, int maxhealth, bool ally, AttackStatistics* atk, int jumps):ActorStatistics(radius,speed,maxhealth,ally)
{
    this->enemyAttack = atk;
    this->maxJumps = jumps;
}

AttackStatistics* EnemyStatistics::getAttackInfo(){
    return enemyAttack;
}

int EnemyStatistics::getMaxJumps(){
    return maxJumps;
}
