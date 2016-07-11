#include <GameObjects/tempgameobject.h>

TempGameObject::TempGameObject(int x, int y, int height, int width, int dura) : GameObject(x,y,height,width){
    this->duration = dura;
}

int TempGameObject::getDuration(){
    return duration;
}
