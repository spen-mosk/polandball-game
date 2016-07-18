#ifndef PLAYERSTATISTICS_H
#define PLAYERSTATISTICS_H
#include "actorstatistics.h"

class PlayerStatistics : public ActorStatistics
{
public:
    PlayerStatistics(int, int, int, int, int, int, bool, int, int, int, int);
    int getAttack1Dmg;
    int getAttack2Dmg;
    int getAttack3Dmg;

private:
    int attack1Dmg;
    int attack2Dmg;
    int attack3Dmg;
};

#endif // PLAYERSTATISTICS_H
