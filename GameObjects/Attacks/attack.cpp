#include <GameObjects/Attacks/attack.h>


Attack::Attack(int x, int y, int height, int width, int duration/*, int damage*/): TempGameObject(x,y,height,width,duration){
// to have more later
}

void Attack::onContact(Actor * actor){
   //do damage
}
