#ifndef ATTACK_H
#define ATTACK_H
#include <GameObjects/tempgameobject.h>
#include <GameObjects/Actors/actor.h>
//#include <level.h>

class Attack: public TempGameObject{
public:
    Attack(int,int,int,int,int, bool); //to add more later i.e. damage multiplier, etc.
    virtual void onContact(Actor *);
    bool isAlly();

private:
    bool ally;
};

#endif // ATTACK_H
