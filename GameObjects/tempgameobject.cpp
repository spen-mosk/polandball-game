#include "GameObjects/tempgameobject.h"
#include "GameObjects/Platforms/platform.h"

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

void TempGameObject::handleCollision(GameObject * obj){
    if(Platform * plat = dynamic_cast<Platform*>(obj)){
        this->existence = this->duration;
    }

}
