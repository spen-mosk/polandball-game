#include "gameobject.h"

GameObject::GameObject(int x, int y, int h, int w)
{
    xPos = x;
    yPos = y;
    height = h;
    width = w;
}

int GameObject::getX(){
    return xPos;
}

int GameObject::getY(){
    return yPos;
}

int GameObject::getHeight(){
    return height;
}

int GameObject::getWidth(){
    return width;
}

void GameObject::setX(int newX){
    xPos = newX;
}

void GameObject::setY(int newY){
    yPos = newY;
}

QPoint * GameObject::getPosition(){
    QPoint * point = new QPoint(xPos, yPos);
    return point;
}
