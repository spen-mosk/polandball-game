#ifndef LEVEL_H
#define LEVEL_H
#include <vector>
#include "GameObjects/Actors/actor.h"
#include "Graphics/camera.h"
#include "GameObjects/Platforms/platform.h"
#include "GameObjects/Actors/player.h"
#include <QSet>
#include "GameObjects/kdtree.h"
#include <QObject>

class Level : public QObject
{
    Q_OBJECT

public:
    Level(Player *);
    Level(Player *, std::vector<GameObject *>, int);
    virtual ~Level();
    void update();
    void applyGravity();
    void ActorPlatformCollisions();
    KDTree * getObjects();

public slots:
    void handlePress(int);
    void handleRelease(int);

private:
    std::vector<GameObject *> objects;
    std::vector<Actor *> actors;
    std::vector<Platform *> plats;
    Player * player;
    KDTree tree;
    KDTree allObjs;
    void checkCollisions();
    void actorCollisions(Actor*, GameObject*);
    int gravity = -1;

};

int distance(Actor *, GameObject*);

#endif // LEVEL_H
