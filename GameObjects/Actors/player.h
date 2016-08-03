#ifndef PLAYER_H
#define PLAYER_H

#include <QSet>
#include <vector>
#include "actor.h"
#include "Statistics/playerstatistics.h"
#include "GameObjects/Attacks/attack.h"
#include "GameObjects/Attacks/meleeattack.h"
#include "GameObjects/Attacks/rangedattack.h"

class Player : public Actor
{
    Q_OBJECT

public:
    Player(int, int, PlayerStatistics * stats);
    virtual ~Player() override;
    virtual void update() override;
    virtual void draw(QPainter *) override;
    void jump();
    void resetJump();
    void maximizeJump();
    void addKey(int);
    void removeKey(int);
    MeleeAttack *primaryAttack();
    RangedAttack *secondaryAttack();
    Attack*ultAttack();
    bool canAttack();


private:
    int meleeDelayCount;
    int rangedDelayCount;
    int ultDelayCount;
    int jumpCount;
    PlayerStatistics * stats;
    QSet<int> * keySet;
    int jumpDelay;
    int jumpDelayCount;
};

#endif // PLAYER_H
