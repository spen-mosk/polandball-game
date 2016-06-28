#include "player.h"


Player::Player(int x, int y, int radius, int speed) : Actor(x, y, radius){
    keySet = new QSet<int>();
    this->speed = speed;
}

void Player::handleInput(int key){
    *keySet += key;
}

void Player::update(){
    if(keySet->contains(Qt::Key_Left)){
        this->updateLocation(-speed, 0);
    }
    if(keySet->contains(Qt::Key_Up)){
        this->updateLocation(speed, 0);
    }
    if(keySet->contains(Qt::Key_Right)){
        this->updateLocation(0, speed);
    }
    if(keySet->contains(Qt::Key_Down)){
        this->updateLocation(0, -speed);
    }
}

void Player::draw(QPainter * painter){
    painter->setBrush(Qt::yellow);
    painter->drawEllipse(*(GameObject::getPosition()), getRadius(), getRadius());
}
