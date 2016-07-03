#ifndef MOVINGPLATFORM_H
#define MOVINGPLATFORM_H
#include <GameObjects/Platforms/platform.h>

class MovingPlatform : public Platform
{

public:
    MovingPlatform(int, int, int, int, int, int);
    void updateLocation();
    virtual void update() override;

private:
    int xSpeed;
    int ySpeed;
};


#endif // MOVINGPLATFORM_H
