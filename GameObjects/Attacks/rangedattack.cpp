#include <GameObjects/Attacks/rangedattack.h>

RangedAttack::RangedAttack(int x, int y, int height, int width, int duration, int spd): Attack(x,y,height,width,duration){
    this->speed = spd;
}

RangedAttack::inRange(Level *l){

}

RangedAttack::draw(QPainter *q){

}

RangedAttack::update(){

}

RangedAttack::getSpeed(){
    return speed;
}
