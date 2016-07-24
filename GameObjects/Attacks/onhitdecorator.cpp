#include "GameObjects/Attacks/onhitdecorator.h"
#include "GameObjects/Attacks/Statistics/attackstatistics.h"


OnHitDecorator::OnHitDecorator(Attack * tack): Attack(tack->getX(),tack->getY(), tack->getStats()){
    this->attack = tack;
}

void OnHitDecorator::onContact(Actor * actor){
    this->attack->onContact(actor);
}
