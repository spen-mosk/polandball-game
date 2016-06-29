#ifndef PLATFORM_H
#define PLATFORM_H
#include <gameobject.h>

class Platform : public GameObject
{

public:
    Platform(int, int, int, int, int, bool);
    int getPlatType(); //may not need if we decide to have all platforms be uniform
    bool isBreakable();
    virtual void draw(QPainter *) override;

private:
    int platType;
    bool breakable;

};


#endif // PLATFORM_H
