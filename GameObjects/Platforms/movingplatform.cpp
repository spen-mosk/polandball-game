#include "GameObjects/Platforms/movingplatform.h"
#include <cmath>

MovingPlatform::MovingPlatform(int x, int y, int h, int w, int xs, int ys, std::vector<int*> points) : Platform(x,y,h,w){
    this->xSpeed = xs;
    this->ySpeed = ys;
    this->points = points;
    this->nextPoint = 0;
}

void MovingPlatform::update(){
    int nextX = points[nextPoint][0];
    int nextY = points[nextPoint][1];
    if(abs(nextX - this->x()) <= xSpeed && abs(nextY - this->y()) <= ySpeed){
        this->setX(nextX);
        this->setY(nextY);
        nextPoint = (nextPoint + 1) % points.size();
    }
    else{
        if(this->x() < nextX){
            this->setX(this->x() + xSpeed);
        }
        else{
            this->setX(this->x() - xSpeed);
        }
        if(this->y() < nextY){
            this->setY(this->y() + ySpeed);
        }
        else{
            this->setY(this->y() - ySpeed);
        }
    }
}
