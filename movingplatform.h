#ifndef MOVINGPLATFORM_H
#define MOVINGPLATFORM_H
#include <platform.h>

class MovingPlatform : public Platform
{

public:
    MovingPlatform(int, int, int, int, int, bool, int, int);
    void updateLocation();

private:
    int xSpeed;
    int ySpeed;
};


#endif // MOVINGPLATFORM_H
