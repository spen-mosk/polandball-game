#ifndef PLAYERSTATISTICS_H
#define PLAYERSTATISTICS_H
#include <vector>

class PlayerStatistics : public ActorStatistics
{
public:
    PlayerStatistics(int, int, int, bool, std::vector<int>, std::vector<int>, std::vector<int>);
    std::vector<int> getMeleeInfo();
    std::vector<int> getRangedInfo();
    std::vector<int> getUltInfo();

private:
    std::vector<int> meleeAtk;
    std::vector<int> rangedAtk;
    std::vector<int> ultAtk;
};

#endif // PLAYERSTATISTICS_H
