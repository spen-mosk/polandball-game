#include <GameObjects/Attacks/attack.h>


Attack::Attack(int x, int y, AttackStatistics* stats): TempGameObject(x,y,stats->getHeight(),stats->getWidth(),stats->getDuration()){
// to have more later
    this->ally = stats->isAlly();
    this->stats = stats;
}

void Attack::onContact(Actor * actor){
   //do damage
}

void Attack::update(){
    TempGameObject::update();
}

bool Attack::isAlly(){
    return ally;
}

AttackStatistics * Attack::getStats(){
    return stats;
}
