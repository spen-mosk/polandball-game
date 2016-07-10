#ifndef MELEEATTACK_H
#define MELEEATTACK_H
#include <GameObjects/Attacks/attack.h>

class MeleeAttack: public Attack{
public:
    MeleeAttack(int,int,int,int,int);
    draw(QPainter *);
    update();
    inRange(Level *);


private:


};

#endif // MELEEATTACK_H
