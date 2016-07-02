#ifndef SURFACEDECORATOR_H
#define SURFACEDECORATOR_H

#include "platform.h"


class SurfaceDecorator : public Platform
{
public:
    SurfaceDecorator(Platform*, int, int, int, int);
    virtual void update() override;
    virtual void surfaceEffect(Actor *) override;


private:
    Platform *movementPlat;
};

#endif // SURFACEDECORATOR_H
