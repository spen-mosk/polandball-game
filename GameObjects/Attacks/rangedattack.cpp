#include <GameObjects/Attacks/rangedattack.h>

RangedAttack::RangedAttack(int x, int y, int height, int width, int duration, int spd, bool ally): Attack(x,y,height,width,duration,ally){
    this->speed = spd;
}


void RangedAttack::draw(QPainter *q){

}

void RangedAttack::update(){

}

int RangedAttack::getSpeed(){
    return speed;
}
