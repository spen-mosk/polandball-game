#include "platform.h"

Platform::Platform(int x, int y, int h, int w) : GameObject(x, y, h, w){
}

void Platform::draw(QPainter * painter){
    painter->setBrush(Qt::white);
    QPoint *point = getDrawingPosition();
    painter->drawRect(point->x(), point->y(), drawingWidth, drawingHeight);
}

void Platform::handleCollision(GameObject * obj, bool both){
    if(both){
        obj->secondCollision(this);
    }
    int x = obj->getX();
    int y = obj->getY();
    int w = obj->getWidth();
    int h = obj->getHeight();
    int actorLeft = x;
    int actorRight = x + w;
    int actorTop = y;
    int actorBottom = y - h;
    int platLeft = this->getX();
    int platRight = this->getX() + this->getWidth();
    int platTop = this->getY();
    int platBottom = this->getY() - this->getHeight();
    if(actorLeft > platLeft && actorLeft < platRight
            && x < platTop && y > platBottom){
        int offsetX = this->getX() + this->getWidth() - actorLeft;
        obj->setX(x + offsetX);
    }
    else if(actorRight < platRight && actorRight > platLeft
            && y < platTop && y > platBottom){
        int offsetX = actorRight - platLeft;
        obj->setX(x - offsetX);
   //     printf("Collision from the left %d\n", numCollisions++);
    }
    else if(actorTop < platTop && actorTop > platBottom
            && x < platRight && x > platLeft){
        int offsetY = actorTop - platBottom;
        obj->setY(y - offsetY);
//        printf("Collision from the bottom %d\n", numCollisions++);
    }
    else if(actorBottom < platTop && actorBottom > platBottom
            && x < platRight && x > platLeft){
        int offsetY = platTop - actorBottom;
        obj->setY(y + offsetY);
 //       printf("Collision from the top %d\n", numCollisions++);
    }
}

void Platform::update(){}
