#ifndef PLATFORMBUILDER_H
#define PLATFORMBUILDER_H
#include "GameObjects/Platforms/platform.h"
#include <vector>
#include <QPoint>
#include "Actors/actor.h"

class PlatformBuilder
{
public:
    PlatformBuilder();
    PlatformBuilder setContact(void (*func)(Actor*));
    PlatformBuilder setMoveEffect(void (*func)(Actor *));
    PlatformBuilder setMovement(std::vector<QPoint *>);
    PlatformBuilder setPoint(QPoint *);
    PlatformBuilder setDimen(int, int);
    Platform create();
private:

};

#endif // PLATFORMBUILDER_H
