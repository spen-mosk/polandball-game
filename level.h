#ifndef LEVEL_H
#define LEVEL_H
#include <vector>
#include "actor.h"
#include "camera.h"
#include "platform.h"
#include "player.h"

class Level
{

public:
    Level(Player *);
    Level(Player *, std::vector<GameObject *>);
    void update();
    void applyGravity();
    std::vector<GameObject *> getObjects();

private:
    std::vector<GameObject *> objects;
    std::vector<Actor *> actors;
    std::vector<Platform *> plats;
    //this is stupid, change to double later
    int gravity;

};

#endif // LEVEL_H
