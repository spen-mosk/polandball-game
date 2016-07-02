#ifndef PLATFORM_H
#define PLATFORM_H
#include "gameobject.h"
#include "actor.h"

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

private:
    int platType;
    bool breakable;

};


#endif // PLATFORM_H
