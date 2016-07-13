#include <GameObjects/Attacks/onhitdecorator.h>

OnHitDecorator::OnHitDecorator(Attack * tack): public Attack(tack->getX(),tack->getY(), tack->getWidth(), tack->getHeight(), tack->getDuration()){
    this->attack = tack;
}

OnHitDecorator::onContact(Actor * actor){
    this->attack->onContact(actor);
}
