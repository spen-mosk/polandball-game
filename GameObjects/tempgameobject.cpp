#include <GameObjects/tempgameobject.h>

TempGameObject::TempGameObject(int x, int y, int height, int width, int dura) : GameObject(x,y,height,width){
    this->duration = dura;
}

TempGameObject::getDuration(){
    return duration;
}
