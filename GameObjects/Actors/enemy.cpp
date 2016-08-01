#include "enemy.h"
#include "ourmath.h"
#include "astargraph.h"
#include <cmath>
using namespace std;

Enemy::Enemy(int x, int y, EnemyStatistics* stat): Actor(x,y,stat)
{
    this->stats = stat;
}

void Enemy::update(){
    /*
    if(lockedOn){
        //stuff
        if(canAttack()){
            //stuff
        }else{
            //stuff
        }
    }
    */
    //check lockedIn here
    if(canAttack()){
       //DO we want to move if we canAttack?
    }
    //if we can't attack, we may want to move
    else
    //if we are where we want to be, nextPoint will be null
    if(nextPoint != NULL && abs(this->getCenter()->y() - nextPoint->y()) < this->getRadius()){
        if(nextPoint->x() < this->x()){
            this->updateLocation(-this->stats->getSpeed(), 0);
        }
        else{
            this->updateLocation(this->stats->getSpeed(), 0);
        }
        if(distance(nextPoint, new QPoint(this->x(), this->y())) <= 1){
            nextPoint = *(this->path.begin());
            this->path.erase(this->path.begin());
        }
    }
    //this means some jumping or descending is involved, and means changing platforms
    //we need to do calculations to see if we can make it
    //Its 5:00 am, I don't feel like doing those right now
    else{

    }
}

void Enemy::draw(QPainter * p){
    p->setBrush(Qt::red);
    p->drawEllipse(drawingX, drawingY, drawingHeight, drawingWidth);
}

void Enemy::handleCollision(GameObject * obj){
    if(Actor * act = dynamic_cast<Actor*>(obj)){
        if(act->isAlly() == this->isAlly()){
            this->lockOn(act);
        }
    }
}

void Enemy::jump(){

}

void Enemy::maximizeJump(){

}

void Enemy::resetJump(){

}

void Enemy::lockOn(Actor* p){
    if(!lockedOn){
        this->lockedOn = true;
        this->lock = p;
        AstarGraph& graph = AstarGraph::getInstance();
        //instead of passing in coords of lock, determine optimal attack position
        this->path = graph.findPath(new QPoint(this->x(), this->y()), new QPoint(p->x(), p->y()));
    }
    //always lock onto the closest adversary
    else{
       if(distance(this, p) < distance(this, lock)){
           this->lock = p;
           AstarGraph& graph = AstarGraph::getInstance();
           //change this so instead of generating a new path, we modify the existing path
           //instead of passing in coords of enemy, determine optimal attack position
           this->path = graph.findPath(new QPoint(this->x(), this->y()), new QPoint(p->x(), p->y()));
       }
    }
}

void Enemy::cancelLock(){
    this->lockedOn = false;
}

bool Enemy::canAttack(){
    //bool stuff based on player's position, speed, and size of enemy's attack
    //this will be more if we are not locked in
    return lockedOn;
}

Attack* Enemy::generateAttack(){
    return NULL;
}
