#include <movingplatform.h>

MovingPlatform::MovingPlatform(int x, int y, int h, int w, int xs, int ys) : Platform(x,y,h,w){
    this->xSpeed = xs;
    this->ySpeed = ys;
}

void MovingPlatform::updateLocation(){
    GameObject::setX(GameObject::getX() + xSpeed);
    GameObject::setY(GameObject::getY() + ySpeed);
}

void MovingPlatform::update(){
    updateLocation();
}
