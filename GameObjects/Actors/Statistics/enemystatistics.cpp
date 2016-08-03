#include "enemystatistics.h"

EnemyStatistics::EnemyStatistics(int radius, int speed, int maxhealth, bool ally, int grav,AttackStatistics* atk, int jumps, int aware):ActorStatistics(radius,speed,maxhealth,ally,grav)
{
    this->enemyAttack = atk;
    this->maxJumps = jumps;
    this->awareness = aware;
}

AttackStatistics* EnemyStatistics::getAttackInfo(){
    return enemyAttack;
}

int EnemyStatistics::getMaxJumps(){
    return maxJumps;
}

int EnemyStatistics::getAwarenessRange(){
    return awareness;
}
