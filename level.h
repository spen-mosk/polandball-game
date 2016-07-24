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
#include "GameObjects/deletesubject.h"

class Level : public QObject, public DeleteObserver
{
    Q_OBJECT

public:
    Level(Player *);
    Level(Player *, std::vector<GameObject *>, int);
    virtual ~Level();
    void update();
    void applyGravity();
    void ActorPlatformCollisions();
    void onDelete(DeleteSubject*);
    KDTree * getObjects();

public slots:
    void handlePress(int);
    void handleRelease(int);

private:
    Player * player;
    KDTree tree;
    void checkCollisions();
    void actorCollisions(Actor*, GameObject*);
    int gravity = -1;

};

int distance(Actor *, GameObject*);

#endif // LEVEL_H
