#include "GameObjects/tempgameobject.h"
#include "GameObjects/Platforms/platform.h"

int TempGameObject::num = 0;

TempGameObject::TempGameObject(int x, int y, int height, int width, int dura) :
        GameObject(x,y,height,width, 5, "Temp"+std::to_string(TempGameObject::num++)){
    REGISTER
    this->duration = dura;
}

int TempGameObject::getDuration(){
    return duration;
}

void TempGameObject::update(){
//    printf("existence %d\n", existence);
    if(++existence >= duration){
        emit deleteEvent(DeleteEvent(this));
    }
}

int TempGameObject::getExistence(){
    return existence;
}

void TempGameObject::handleCollision(GameObject * obj){
    int x = obj->x();
    int y = obj->y();
    int w = obj->getWidth();
    int h = obj->getHeight();
    int centerX = this->x() + this->getWidth() /2;
    int centerY = this->y() - this->getHeight() / 2;
    int platLeft = x;
    int platRight = x + w;
    int platTop = y;
    int platBottom = y - h;
    int actorLeft = this->x();
    int actorRight = this->x() + this->getWidth();
    int actorTop = this->y();
    int actorBottom = this->y() - this->getHeight();
    if(actorLeft > platLeft && actorLeft < platRight
            && centerY < platTop && centerY > platBottom
     || actorRight < platRight && actorRight > platLeft
            && centerY < platTop && centerY > platBottom
    || actorTop < platTop && actorTop > platBottom
            && centerX < platRight && centerX > platLeft
    || actorBottom < platTop && actorBottom > platBottom
            && centerX < platRight && centerX > platLeft){
        if(Platform * plat = dynamic_cast<Platform*>(obj)){
            this->existence = this->duration;
        }
    }
}
