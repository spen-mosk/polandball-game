#include "GameObjects/tempgameobject.h"

TempGameObject::TempGameObject(int x, int y, int height, int width, int dura) : GameObject(x,y,height,width), DeleteSubject(){
    this->duration = dura;
}

int TempGameObject::getDuration(){
    return duration;
}

void TempGameObject::update(){
    if(++existence >= duration){
        updateObservers();
    }
}

int TempGameObject::getExistence(){
    return existence;
}

void TempGameObject::handleCollision(GameObject * obj){

}
