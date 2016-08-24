#ifndef MOVINGPLATFORM_H
#define MOVINGPLATFORM_H
#include "GameObjects/Platforms/platform.h"
#include <vector>

class MovingPlatform : public Platform
{

public:
    MovingPlatform(int, int, int, int, int, int, std::vector<int*>);
    virtual void update() override;

private:
    int xSpeed;
    int ySpeed;
    int nextPoint;
    std::vector<int*> points;
};


#endif // MOVINGPLATFORM_H
