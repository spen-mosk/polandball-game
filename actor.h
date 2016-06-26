#ifndef ACTOR_H
#define ACTOR_H

#include <QPoint>
#include <QPainter>

class Actor
{
public:
    Actor();
    Actor(int, int, int);
    QPoint * getPosition();
    bool contains(QPoint * point);
    void move(int,int);
    void draw(QPainter * painter);

private:
    int xPos;
    int yPos;
    int radius;
};

#endif // ACTOR_H
