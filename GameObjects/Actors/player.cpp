#include "player.h"
#include <stdio.h>


Player::Player(int x, int y, int radius, int speed) : Actor(x, y, radius){
    keySet = new QSet<int>();
    this->speed = speed;
}

void Player::handleInput(int key){
    *keySet += key;
}

void Player::handleRelease(int a){
    *keySet -= a;
}

void Player::update(){
    if(keySet->contains(Qt::Key_Left)){
        this->updateLocation(-speed, 0);
    }
    if(keySet->contains(Qt::Key_Up)){
        this->updateLocation(0, speed);
    }
    if(keySet->contains(Qt::Key_Right)){
        this->updateLocation(speed,0);
    }
    if(keySet->contains(Qt::Key_Down)){
        this->updateLocation(0, -speed);
    }
    printf("pos: %d, %d\n", this->getX(), this->getY());
}

void Player::draw(QPainter * painter){
    painter->setBrush(Qt::blue);
    painter->drawEllipse(*(GameObject::getDrawingPosition()), getRadius(), getRadius());
}
