#ifndef LEVEL_H
#define LEVEL_H
#include <vector>
#include "actor.h"
#include "camera.h"
#include "player.h"

class Level
{

public:
    Level(Player *);
    void update();
    std::vector<GameObject *> getObjects();

private:
    std::vector<GameObject *> objects;
    //this is stupid, change to double later
    int gravity;

};

#endif // LEVEL_H
