#include <movingplatform.h>

MovingPlatform::MovingPlatform(int x, int y, int h, int w, int platT, bool breaky, int xs, int ys) : Platform(x,y,h,w,platT,breaky){
    this->xSpeed = xs;
    this->ySpeed = ys;
}

void MovingPlatform::updateLocation(){
    GameObject::setX(GameObject::getX() + xSpeed);
    GameObject::setY(GameObject::getY() + ySpeed);
}
