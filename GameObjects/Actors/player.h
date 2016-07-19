#ifndef PLAYER_H
#define PLAYER_H

#include <QSet>
#include "actor.h"
#include "Statistics/playerstatistics.h"

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
    void endJump();
    void addKey(int);
    void removeKey(int);

private:
    int verticalSpeed;
    int jumpCount;
    PlayerStatistics * stats;
    QSet<int> * keySet;
};

#endif // PLAYER_H
