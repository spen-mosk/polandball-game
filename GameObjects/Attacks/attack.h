#ifndef ATTACK_H
#define ATTACK_H
#include <GameObjects/tempgameobject.h>
#include <level.h>

class Attack: public TempGameObject{
public:
    Attack(int,int,int,int,int); //to add more later i.e. damage multiplier, etc.
    virtual void inRange(Level *) = 0;
    virtual void onContact(Acor *) = 0;

private:


};

#endif // ATTACK_H
