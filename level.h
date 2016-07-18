#ifndef LEVEL_H
#define LEVEL_H
#include <vector>
#include "GameObjects/Actors/actor.h"
#include "Graphics/camera.h"
#include "GameObjects/Platforms/platform.h"
#include "GameObjects/Actors/player.h"
#include <QSet>
#include "GameObjects/kdtree.h"

class Level
{

public:
    Level(Player *);
    Level(Player *, std::vector<GameObject *>);
    ~Level();
    void update();
    void applyGravity();
    void ActorPlatformCollisions();
    std::vector<GameObject *> getObjects();

public slots:
    void handlePress(int);
    void handleRelease(int);

private:
    std::vector<GameObject *> objects;
    std::vector<Actor *> actors;
    std::vector<Platform *> plats;
    Player * player;
    //this is stupid, change to double later
    KDTree tree;
    void checkCollisions();
    void actorCollisions(Actor*, GameObject*);
    QSet<int>* keySet;
    int gravity;

};

int distance(Actor *, GameObject*);

#endif // LEVEL_H
