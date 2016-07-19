#include <GameObjects/Attacks/onhitdecorator.h>

OnHitDecorator::OnHitDecorator(Attack * tack): Attack(tack->getX(),tack->getY(), tack->getWidth(), tack->getHeight(), tack->getDuration(), tack->isAlly()){
    this->attack = tack;
}

void OnHitDecorator::onContact(Actor * actor){
    this->attack->onContact(actor);
}
