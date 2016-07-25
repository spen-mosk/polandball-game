#include "enemy.h"

Enemy::Enemy(int x, int y, EnemyStatistics* stat): Actor(x,y,stat)
{
    this->stats = stat;
}

void Enemy::makeDecision(KDTree* tree){

}

void Enemy::update(){

}

void Enemy::draw(QPainter * p){

}

void Enemy::jump(){

}

void Enemy::maximizeJump(){

}

void Enemy::resetJump(){

}

/*Attack* Enemy::generateAttack(){
    Attack* placeholder = new MeleeAttack(1,1,1,1,1,false, this);
    return placeholder;
}
*/
