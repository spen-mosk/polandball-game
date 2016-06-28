#ifndef LEVEL_H
#define LEVEL_H
#include <vector>
#include "actor.h"
#include "camera.h"

class Level
{

public:
    Level();
    void update();
    std::vector<GameObject *> getObjects();

private:
    std::vector<GameObject *> objects;
    //this is stupid, change to double later
    int gravity;

};

#endif // LEVEL_H
