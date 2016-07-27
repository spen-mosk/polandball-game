#include "gameobject.h"
#include <stdio.h>

GameObject::GameObject(int x, int y, int h, int w, int rad)
{
    xPos = x;
    yPos = y;
    height = h;
    width = w;
    collRad= rad;
    this->grav = true;
}

bool GameObject::getGrav(){
    return grav;
}

void GameObject::setGrav(bool grav){
    this->grav = grav;
}

int GameObject::getCollRadius(){
    return collRad;
}

int GameObject::getX(){
    return xPos;
}

QPoint * GameObject::getDrawingPosition(){
    QPoint * point = new QPoint(drawingX, drawingY);
    return point;
}

void GameObject::initialCollision(GameObject* obj){
    this->handleCollision(obj, true);
}

void GameObject::secondCollision(GameObject* obj){
    this->handleCollision(obj, false);
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
