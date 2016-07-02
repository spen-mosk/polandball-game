#ifndef ONCONTACTDECORATOR_H
#define ONCONTACTDECORATOR_H

#include "platform.h"
#include "surfacedecorator.h"


class OnContactDecorator : public Platform
{
public:
    OnContactDecorator(SurfaceDecorator *, int, int, int, int);
    virtual void onContact(Actor *) override;
    virtual void surfaceEffect(Actor *) override;


private:
    SurfaceDecorator *decorator;
};

#endif // ONCONTACTDECORATOR_H
