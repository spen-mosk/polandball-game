#include "actor.h"
#include <stdio.h>

Actor::Actor()
{
    xPos = 0;
    yPos = 0;
}

Actor::Actor(int a, int b){
    xPos = a;
    yPos = b;
}

QPoint * Actor::getPosition(){
    QPoint * point = new QPoint(xPos, yPos);
    printf("QPOINT: %d, %d", point->x(), point->y());
    return point;
}

void Actor::move(int xOffset, int yOffset){
    xPos += xOffset;
    yPos += yOffset;
}
