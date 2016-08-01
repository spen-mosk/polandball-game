#include "playerstatistics.h"
#include "GameObjects/Attacks/Statistics/attackstatistics.h"

PlayerStatistics::PlayerStatistics(int radius, int speed, int maxhealth, bool ally, int grav, AttackStatistics * attack1,
                                   AttackStatistics* attack2, AttackStatistics* attack3, int jumps, int vSpeed):
                                                ActorStatistics(radius, speed, maxhealth, ally, grav){
    this->primary = attack1;
    this->maxJump = jumps;
    this->secondary = attack2;
    this->tertiary = attack3;
    this->verticalSpeed = vSpeed;
}

int PlayerStatistics::getVertSpeed(){
    return verticalSpeed;
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
