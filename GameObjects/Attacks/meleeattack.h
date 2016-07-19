#ifndef MELEEATTACK_H
#define MELEEATTACK_H
#include <GameObjects/Attacks/attack.h>

class MeleeAttack: public Attack{
public:
    MeleeAttack(int, int, int, int, int, bool);
    virtual void draw(QPainter *);
    virtual void update();


private:


};

#endif // MELEEATTACK_H
