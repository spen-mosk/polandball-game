#ifndef ACTOR_H
#define ACTOR_H

#include <QPoint>

class Actor
{
public:
    Actor();
    Actor(int, int);
    QPoint * getPosition();
    void move(int,int);

private:
    int xPos;
    int yPos;
};

#endif // ACTOR_H
