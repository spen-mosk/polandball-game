#include "player.h"
#include <stdio.h>


Player::Player(int x, int y, int radius, int speed) : Actor(x, y, radius){
    keySet = new QSet<int>();
    this->speed = speed;
    this->jumpCount = 0;
    this->verticalSpeed = 0;
}

Player::~Player(){
    delete keySet;
}

void Player::handleInput(int key){
    *keySet += key;
}

void Player::handleRelease(int a){
    if(a == (Qt::Key_Up)){
        jumpCount = 25;
        verticalSpeed = 0;
    }
    *keySet -= a;
}

void Player::update(){
    if(keySet->contains(Qt::Key_Left)){
        this->updateLocation(-speed, 0);
    }
    if(keySet->contains(Qt::Key_Up)){
        this->jump();
        this->updateLocation(0, verticalSpeed);
    }
    if(keySet->contains(Qt::Key_Right)){
        this->updateLocation(speed,0);
    }
//    if(keySet->contains(Qt::Key_Down)){
//        this->updateLocation(0, -speed);
 //   }
   // printf("pos: %d, %d\n", this->getX(), this->getY());
}

void Player::jump(){
    if(jumpCount < 25){
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
//    printf("Hello");
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
