#include <GameObjects/Attacks/rangedattack.h>

RangedAttack::RangedAttack(int x, int y, int height, int width, int duration, int spd): Attack(x,y,height,width,duration){
    this->speed = spd;
}

void RangedAttack::inRange(Level *l){

}

void RangedAttack::draw(QPainter *q){

}

void RangedAttack::update(){

}

int RangedAttack::getSpeed(){
    return speed;
}
