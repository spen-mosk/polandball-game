#ifndef LEVEL_H
#define LEVEL_H
#include <vector>
#include <actor.h>
#include <camera.h>

class Level
{
public:
    Level();
    Level(double, Camera);
private:
    vector<Actor *> actors;
    double gravity;
};

#endif // LEVEL_H
