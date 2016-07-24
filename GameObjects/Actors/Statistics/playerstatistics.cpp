#include "playerstatistics.h"
#include "GameObjects/Attacks/Statistics/attackstatistics.h"

PlayerStatistics::PlayerStatistics(int radius, int speed, int maxhealth, bool ally, AttackStatistics * attack1,
                                   AttackStatistics* attack2, AttackStatistics* attack3, int jumps):
ActorStatistics(radius, speed, maxhealth, ally){
    this->primary = attack1;
    this->maxJump = jumps;
    this->secondary = attack2;
    this->tertiary = attack3;
}

AttackStatistics* PlayerStatistics::getMeleeInfo(){
    return primary;
}

int PlayerStatistics::getMaxJumps(){
    return maxJump;
}

AttackStatistics* PlayerStatistics::getRangedInfo(){
    return secondary;
}

AttackStatistics* PlayerStatistics::getUltInfo(){
    return tertiary;
}
