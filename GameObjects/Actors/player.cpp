#include "player.h"
#include <stdio.h>

Player::Player(int x, int y, PlayerStatistics *stat) : Actor(x, y, stat){
    keySet = new QSet<int>();
    this->jumpCount = 0;
    this->verticalSpeed = 3;
    this->stats = stat;
    this->jumpDelayCount = 28;
    this->jumpDelay = 14;
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
    Actor::update();
    printf("PLAYER X %d, PLAYER Y %d\n", this->x(), this->y());
    int x = Qt::Key_Up;
    if(!getGrav()){
        resetJump();
    }
    //printf("ACTOR GRAVITY %s\n", getGrav() ? "true" : "false");
    if(keySet->contains(x)){
        if(jumpDelayCount == jumpDelay){
            this->jump();
        }
    }
    if(keySet->contains(Qt::Key_Right)){
        this->updateLocation(stats->getSpeed(), 0);
        setFacing(false);
    }
    if(keySet->contains(Qt::Key_Left)){
        this->updateLocation(-stats->getSpeed(), 0);
        setFacing(true);
    }
    setGrav(true);
}

void Player::jump(){
    if(jumpCount < this->stats->getMaxJumps()){
        this->setGrav(true);
        jumpCount += 1;
        this->updateLocation(0, verticalSpeed);
    }
}

void Player::resetJump(){
    jumpCount = 0;
    if(jumpDelayCount < jumpDelay){
        printf("%d\n",jumpDelayCount);
        jumpDelayCount += 1;
    }
}

void Player::maximizeJump(){
    printf("maximized\n");
    jumpCount = this->stats->getMaxJumps();
    if(jumpCount == 0){
        jumpCount = this->stats->getMaxJumps();
    }
    if(jumpCount == this->stats->getMaxJumps()){
        jumpDelayCount = 0;
    }
}

void Player::draw(QPainter * painter){
    painter->setBrush(Qt::blue);
    painter->drawEllipse(*(this->getDrawingPosition()), drawingHeight, drawingWidth);
}

MeleeAttack* Player::primaryAttack(){
    AttackStatistics* melle = stats->getMeleeInfo();
    return new MeleeAttack(this->getCenter()->x(),this->getCenter()->y() + melle->getHeight()/2, melle, this);
}

RangedAttack* Player::secondaryAttack(){
    AttackStatistics* melle = stats->getRangedInfo();
    if(facingLeft()){
        return new RangedAttack(this->getCenter()->x()-this->getRadius() - melle->getWidth(),this->getCenter()->y() + melle->getHeight()/2, this->facingLeft(), melle);
    }
    else{
        return new RangedAttack(this->getCenter()->x()+this->getRadius(),this->getCenter()->y() + melle->getHeight()/2, this->facingLeft(), melle);
    }
}

Attack* Player::ultAttack(){
    AttackStatistics *ult = stats->getUltInfo();
    Attack* attack;
    if(ult->isMelee()){
        attack = new MeleeAttack(this->getCenter()->x(),this->getCenter()->y() + ult->getHeight()/2, ult, this);
    }
    else{
        attack = new RangedAttack(this->getCenter()->x(),this->getCenter()->y() + ult->getHeight()/2, this->facingLeft(), ult);

    }
    return attack;
}
