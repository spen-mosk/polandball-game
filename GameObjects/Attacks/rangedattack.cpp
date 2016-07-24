#include <GameObjects/Attacks/rangedattack.h>

RangedAttack::RangedAttack(int x, int y, AttackStatistics*stats): Attack(x,y, stats){
    this->speed = stats->getSpeed();
}


void RangedAttack::draw(QPainter *q){

}

void RangedAttack::update(){
    Attack::update();
}

int RangedAttack::getSpeed(){
    return speed;
}
