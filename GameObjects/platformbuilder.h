#ifndef PLATFORMBUILDER_H
#define PLATFORMBUILDER_H

#include <vector>
#include <QPoint>

class PlatformBuilder
{
public:
    PlatformBuilder();
    PlatformBuilder setContact((*func)(Actor*));
    PlatformBuilder setMoveEffect((*func)(Actor *));
    PlatformBuilder setMovement(std:vector<QPoint *>);
    PlatformBuilder setPoint(QPoint *);
    PlatformBuilder setDimen(int, int);
    Platform create();
private:

};

#endif // PLATFORMBUILDER_H
