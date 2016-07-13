#ifndef ONHITDECORATOR_H
#define ONHITDECORATOR_H
#include <GameObjects/Attacks/attack.h>

class OnHitDecorator: public Attack{
public:
    OnHitDecorator(Attack *);
    virtual void onContact(Actor *);
private:
    Attack *attack;

};

#endif // ONHITDECORATOR_H
