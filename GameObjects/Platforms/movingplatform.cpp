#include "GameObjects/Platforms/movingplatform.h"
#include <cmath>

MovingPlatform::MovingPlatform(int x, int y, int h, int w, int xs, int ys, std::vector<int*> points) : Platform(x,y,h,w){
    this->xSpeed = xs;
    this->ySpeed = ys;
    this->points = points;
    this->nextPoint = 0;
}

void MovingPlatform::write(FILE *stream){
    std::string string = "movingplatform\t";
    string += std::to_string(this->x()) + "\t" + std::to_string(this->y()) + "\t" + std::to_string(this->getHeight()) + "\t" + std::to_string(this->getWidth()) + "\t"
              + std::to_string(this->xSpeed) + "\t" + std::to_string(this->ySpeed) +"\t";
    string += this->points.size();
    for(int a = 0; a < this->points.size(); a++){
        string += "\t" + std::to_string(points[a][0]) + "\t" + std::to_string(points[a][1]);
    }
    string +="\n";
    fprintf(stream, "%s", string.c_str());
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
