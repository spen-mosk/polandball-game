#include "GameObjects/Attacks/meleeattack.h"
#include <QPoint>

MeleeAttack::MeleeAttack(int x, int y, AttackStatistics* stats, Actor* act): Attack(x,y,stats){
// to have more later
    this->actor = act;
}

void MeleeAttack::draw(QPainter *painter){
    painter->setBrush(Qt::red);
    QPoint drawingPos = *(getDrawingPosition());
    painter->drawRect(drawingPos.x(), drawingPos.y(), drawingHeight, drawingWidth);

}

void MeleeAttack::update(){
    Attack::update();
    QPoint * center = actor->getCenter();
    AttackStatistics *stats = getStats();
    if(actor->facingLeft()){
        setX(center->x() - stats->getWidth());
        setY(center->y() + stats->getHeight() / 2);
    }
    else{
        setX(center->x());
        setY(center->y() + stats->getHeight() / 2);
    }
}
