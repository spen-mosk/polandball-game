#ifndef PLAYER_H
#define PLAYER_H

#include <QSet>
#include "actor.h"

class Player : public Actor
{
    Q_OBJECT

public:
    Player(int, int, int, int);
    virtual void update() override;
    virtual void draw(QPainter *) override;


public slots:
    void handleInput(int);
    void handleRelease(int);

private:
    QSet<int> * keySet;
    int speed;
};

#endif // PLAYER_H
