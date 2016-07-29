#include "platform.h"

Platform::Platform(int x, int y, int h, int w) : GameObject(x, y, h, w, 1){
}

void Platform::draw(QPainter * painter){
    painter->setBrush(Qt::white);
    QPoint *point = getDrawingPosition();
    painter->drawRect(point->x(), point->y(), drawingWidth, drawingHeight);
}

void Platform::handleCollision(GameObject * obj){
    if(Platform *p = dynamic_cast<Platform*>(obj)){
        return;
    }
    int x = obj->getX();
    int y = obj->getY();
    int w = obj->getWidth();
    int h = obj->getHeight();
    int centerX = x + obj->getWidth() / 2;
    int centerY = y + obj->getHeight() / 2;
    int actorLeft = x;
    int actorRight = x + w;
    int actorTop = y;
    int actorBottom = y - h;
    int platLeft = this->getX();
    int platRight = this->getX() + this->getWidth();
    int platTop = this->getY();
    int platBottom = this->getY() - this->getHeight();
    obj->setGrav(true && obj->getGrav());
    if(actorLeft > platLeft && actorLeft < platRight
            && centerY < platTop && centerY > platBottom){
        int offsetX = this->getX() + this->getWidth() - actorLeft;
        obj->setX(x + offsetX);
    }
    else if(actorRight < platRight && actorRight > platLeft
            && centerY < platTop && centerY > platBottom){
        int offsetX = actorRight - platLeft;
        obj->setX(x - offsetX);
    }
    else if(actorTop < platTop && actorTop > platBottom
            && centerX < platRight && centerX > platLeft){
        int offsetY = actorTop - platBottom;
        obj->setY(y - offsetY);
    }
    else if(actorBottom < platTop + obj->getHeight() && actorBottom > platBottom
            && centerX < platRight && centerX > platLeft){
        obj->setGrav(false);
        int offsetY = this->getY() - actorBottom;
        obj->setY(platTop + obj->getHeight());
    }
}

void Platform::update(){}
