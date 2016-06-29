#include <platform.h>

Platform::Platform(int x, int y, int h, int w, int platT, bool breaky) : GameObject(x, y, h, w){
    this->breakable = breaky;
    this->platType = platT;
}

int Platform::getPlatType(){
    return platType;
}

bool Platform::isBreakable(){
    return breakable;
}

void Platform::draw(QPainter * painter){
    painter->setBrush(Qt::black);
    painter->drawRect((GameObject::getX()), (GameObject::getY()),(GameObject::getHeight()), (GameObject::getWidth()));
}
