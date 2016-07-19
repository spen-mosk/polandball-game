#include "player.h"
#include <stdio.h>

Player::Player(int x, int y, PlayerStatistics *stat) : Actor(x, y, stat){
    keySet = new QSet<int>();
    this->jumpCount = 0;
    this->verticalSpeed = 0;
    this->stats = stat;
}

Player::~Player(){
}

void Player::addKey(int key){
    (*keySet) += key;
}

void Player::removeKey(int key){
    (*keySet) -= key;
    if(key == Qt::Key_Up){
        endJump();
    }
}

void Player::endJump(){
    jumpCount = stats->getJumpCount();
    verticalSpeed = 0;
}

void Player::update(){
    int x = Qt::Key_Up;
    if(keySet->contains(x)){
        this->jump();
        this->updateLocation(0, verticalSpeed);
    }
    if(keySet->contains(Qt::Key_Right)){
        this->updateLocation(stats->getSpeed(),0);
    }
    if(keySet->contains(Qt::Key_Left)){
        this->updateLocation(-stats->getSpeed(), 0);
    }
}

void Player::jump(){
    if(jumpCount < this->stats->getJumpCount()){
        jumpCount += 1;
        verticalSpeed = jumpCount/15;
        if(verticalSpeed < 1){
            verticalSpeed = 3;
        }
    }
    else{
        verticalSpeed = 0;
    }
}

void Player::resetJump(){
    jumpCount = 0;
    verticalSpeed = 0;
}

void Player::maximizeJump(){
    if(jumpCount == 0){
        jumpCount = 25;
    }
}

void Player::draw(QPainter * painter){
    painter->setBrush(Qt::blue);
    painter->drawEllipse(*(getDrawingPosition()), drawingHeight, drawingWidth);
}
