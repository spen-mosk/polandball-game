#ifndef PLATFORM_H
#define PLATFORM_H
#include "GameObjects/gameobject.h"
#include "GameObjects/Actors/actor.h"

class Platform : public GameObject
{

public:
    Platform(int, int, int, int);
    //int getPlatType(); //may not need if we decide to have all platforms be uniform
    //bool isBreakable();
    virtual void draw(QPainter *) override;
    virtual void update();
    virtual void onContact(Actor *){};
    virtual void surfaceEffect(Actor *){};
    void handleCollision(GameObject*);

private:
    static int num;
    int platType;
    bool breakable;

};


#endif // PLATFORM_H
