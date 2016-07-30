#include <GameObjects/Platforms/movingplatform.h>

MovingPlatform::MovingPlatform(int x, int y, int h, int w, int xs, int ys) : Platform(x,y,h,w){
    this->xSpeed = xs;
    this->ySpeed = ys;
}

void MovingPlatform::updateLocation(){
    GameObject::setX(GameObject::x() + xSpeed);
    GameObject::setY(GameObject::y() + ySpeed);
}

void MovingPlatform::update(){
    updateLocation();
}
