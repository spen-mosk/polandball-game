#include <GameObjects/Attacks/rangedattack.h>

RangedAttack::RangedAttack(int x, int y, bool left, AttackStatistics*stats): Attack(x,y, stats){
    this->speed = stats->getSpeed();
    if(left){
        this->speed *= -1;
    }
}


void RangedAttack::draw(QPainter *q){
    q->setBrush(Qt::red);
    QPoint drawingPos = *(getDrawingPosition());
    q->drawRect(drawingPos.x(), drawingPos.y(), drawingHeight, drawingWidth);
}

void RangedAttack::update(){
    Attack::update();
    this->setX(this->getX() + this->speed);
}

int RangedAttack::getSpeed(){
    return speed;
}
