#ifndef MELEEATTACK_H
#define MELEEATTACK_H
#include "GameObjects/Attacks/attack.h"
#include "GameObjects/Attacks/Statistics/attackstatistics.h"

class MeleeAttack: public Attack{
public:
    MeleeAttack(int, int, AttackStatistics *, Actor *);
    virtual void draw(QPainter *);
    virtual void update();


private:
    Actor* actor;

};

#endif // MELEEATTACK_H
