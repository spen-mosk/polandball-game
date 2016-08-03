#ifndef ENEMY_H
#define ENEMY_H
#include "GameObjects/Actors/Statistics/enemystatistics.h"
#include "GameObjects/Attacks/attack.h"
#include "GameObjects/Attacks/meleeattack.h"
#include "GameObjects/Attacks/rangedattack.h"
#include "GameObjects/kdtree.h"
#include "GameObjects/Actors/player.h"
#include <QPoint>
using namespace std;

class Enemy : public Actor
{
public:
    Enemy(int,int, EnemyStatistics*);
    Attack* generateAttack();
    void update();
    void draw(QPainter *);
    void jump();
    void resetJump();
    void maximizeJump();
    void handleCollision(GameObject*);
    bool canAttack();
    void lockOn(Actor*);
    void cancelLock();

private:
    //AI to be added/used in makeDecision
    int attackDelayCount = 0;
    int jumpDelay;
    int jumpDelayCount;
    int verticalSpeed;
    int jumpCount;
    vector<QPoint*> path;
    bool lockedOn;
    QPoint * nextPoint = NULL;
    Actor* lock;
    EnemyStatistics* stats;
};

#endif // ENEMY_H
