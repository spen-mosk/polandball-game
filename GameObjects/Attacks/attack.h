#ifndef ATTACK_H
#define ATTACK_H
#include "GameObjects/tempgameobject.h"
#include "GameObjects/Actors/actor.h"
#include "Statistics/attackstatistics.h"

class Attack: public TempGameObject{

public:
    Attack(int,int, AttackStatistics *); //to add more later i.e. damage multiplier, etc.
    virtual void onContact(Actor *);
    virtual void update();
    bool isAlly();
    AttackStatistics* getStats();
private:
    bool ally;
    AttackStatistics* stats;
};

#endif // ATTACK_H
