#ifndef SURFACEDECORATOR_H
#define SURFACEDECORATOR_H

#include "platform.h"


class SurfaceDecorator : public Platform
{
public:
    SurfaceDecorator(Platform movementPlat);
    virtual void update() override;
    virtual void surfaceEffect() override;


private:
    Platform movementPlat;
};

#endif // SURFACEDECORATOR_H
