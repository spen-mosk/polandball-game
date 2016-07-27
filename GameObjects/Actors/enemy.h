#ifndef ENEMY_H
#define ENEMY_H
#include "GameObjects/Actors/Statistics/enemystatistics.h"
#include "GameObjects/Attacks/attack.h"
#include "GameObjects/Attacks/meleeattack.h"
#include "GameObjects/Attacks/rangedattack.h"
#include "GameObjects/kdtree.h"
#include "GameObjects/Actors/player.h"

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
    bool canAttack();
    void lockOn(Player*);
    void cancelLock();

private:
    //AI to be added/used in makeDecision
    int jumpDelay;
    int jumpDelayCount;
    int verticalSpeed;
    int jumpCount;
    bool lockedOn;
    Player* player;
    EnemyStatistics* stats;
};

#endif // ENEMY_H
