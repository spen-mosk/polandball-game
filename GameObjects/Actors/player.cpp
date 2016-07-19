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
        this->maximizeJump();
    }
}

void Player::endJump(){
    jumpCount = stats->getMaxJumps();
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
    if(jumpCount < this->stats->getMaxJumps()){
        jumpCount += 1;
        verticalSpeed = jumpCount/15;
        if(verticalSpeed < 1){
            verticalSpeed = 4;
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
        jumpCount = this->stats->getMaxJumps();
    }
}

void Player::draw(QPainter * painter){
    painter->setBrush(Qt::blue);
    painter->drawEllipse(*(getDrawingPosition()), drawingHeight, drawingWidth);
}

MeleeAttack Player::generateMeleeAttack(){
    int placeholder = 10;
    return MeleeAttack(this->getCenter()->x(),this->getCenter()->y() + placeholder/2, placeholder,placeholder*2,placeholder, true);
}

RangedAttack Player::generateRangedAttack(){
    int placeholder = 5;
    return RangedAttack(this->getCenter()->x()+this->getRadius(),this->getCenter()->y() + placeholder/2, placeholder,placeholder*2,placeholder, 1, true);
}

void Player::generateUltAttack(){

}
