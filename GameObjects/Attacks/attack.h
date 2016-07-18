#ifndef ATTACK_H
#define ATTACK_H
#include <GameObjects/tempgameobject.h>
#include <level.h>

class Attack: public TempGameObject{
public:
    Attack(int,int,int,int,int); //to add more later i.e. damage multiplier, etc.
    virtual void onContact(Actor *);

private:

};

#endif // ATTACK_H
