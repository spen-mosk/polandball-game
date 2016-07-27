#include "GameObjects/tempgameobject.h"

TempGameObject::TempGameObject(int x, int y, int height, int width, int dura) : GameObject(x,y,height,width, 5), DeleteSubject(){
    this->duration = dura;
}

int TempGameObject::getDuration(){
    return duration;
}

void TempGameObject::update(){
    printf("existence %d\n", existence);
    if(++existence >= duration){
        updateObservers();
    }
}

int TempGameObject::getExistence(){
    return existence;
}

void TempGameObject::handleCollision(GameObject * obj, bool boolean){

}
