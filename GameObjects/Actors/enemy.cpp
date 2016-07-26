#include "enemy.h"

Enemy::Enemy(int x, int y, EnemyStatistics* stat): Actor(x,y,stat)
{
    this->stats = stat;
}

void Enemy::update(){
    if(lockedOn){
        //stuff
        if(canAttack()){
            //stuff
        }else{
            //stuff
        }
    }

}

void Enemy::draw(QPainter * p){
    p->setBrush(Qt::red);
    p->drawEllipse(*(getDrawingPosition()), drawingHeight, drawingWidth);
}

void Enemy::jump(){

}

void Enemy::maximizeJump(){

}

void Enemy::resetJump(){

}

void Enemy::lockOn(Player* p){
    this->lockedOn = true;
    this->player = p;
}

void Enemy::cancelLock(){
    this->lockedOn = false;
}

bool Enemy::canAttack(){
    //bool stuff based on player's position, speed, and size of enemy's attack
    return true;
}

Attack* Enemy::generateAttack(){
    Attack* placeholder = new MeleeAttack(1,1,1,1,1,false);
    return placeholder;
}
