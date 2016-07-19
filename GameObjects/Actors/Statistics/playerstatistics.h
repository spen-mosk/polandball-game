#ifndef PLAYERSTATISTICS_H
#define PLAYERSTATISTICS_H
#include <vector>
#include "actorstatistics.h"

class PlayerStatistics : public ActorStatistics
{
public:
    PlayerStatistics(int, int, int, bool, std::vector<int>, std::vector<int>, std::vector<int>, int);
    std::vector<int> getMeleeInfo();
    std::vector<int> getRangedInfo();
    std::vector<int> getUltInfo();
    int getMaxJumps();

private:
    std::vector<int> meleeAtk;
    std::vector<int> rangedAtk;
    std::vector<int> ultAtk;
    int maxJump;
};

#endif // PLAYERSTATISTICS_H
