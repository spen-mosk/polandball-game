#ifndef ONHITDECORATOR_H
#define ONHITDECORATOR_H
#include <GameObjects/Attacks/attack.h>

class OnHitDecorator: public Attack{
public:
    OnHitDecorator(int,int,int,int,int);
    virtual void damageEffect(Actor *);

};

#endif // ONHITDECORATOR_H
