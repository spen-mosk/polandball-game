#include <GameObjects/Attacks/attack.h>


Attack::Attack(int x, int y, int height, int width, int duration/*, int damage*/, bool ally): TempGameObject(x,y,height,width,duration){
// to have more later
    this->ally = ally;
}

void Attack::onContact(Actor * actor){
   //do damage
}

bool Attack::isAlly(){
    return ally;
}
