#include "enemy.h"
#include "ourmath.h"
#include "astargraph.h"
#include <cmath>
using namespace std;

Enemy::Enemy(int x, int y, EnemyStatistics* stat): Actor(x,y,stat, stat->getAwarenessRange())
{
    this->stats = stat;
    this->verticalSpeed = 3;
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
    Actor::update();
    if(nextPoint == NULL && this->path.size() != 0){
        nextPoint = *(this->path.begin());
        this->path.erase(this->path.begin());
    }
    if(!this->getGrav()){
        resetJump();
    }
    if(canAttack()){
        //DO we want to move if we canAttack?
        //Probably not
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
    }
    //this means some jumping or descending is involved, and means changing platforms
    //we need to do calculations to see if we can make it
    //Its 5:00 am, I don't feel like doing those right now
    else if(nextPoint != NULL){
        int realMax = stats->getMaxJumps() - this->jumpCount;
        int jumpHeight = (verticalSpeed - stats->getGravity()) * realMax;
        int xDist = abs(nextPoint->x() - this->x());
        int cycles = xDist / this->stats->getSpeed();
        int descent = stats->getGravity() * (cycles - realMax);
        int yHeight = jumpHeight - descent;
        if(this->jumpCount > stats->getMaxJumps() || yHeight > nextPoint->y()){
            this->jump();
            if(this->x() < nextPoint->x()){
                this->updateLocation(this->stats->getSpeed(), 0);
            }
            else if(this->x() > nextPoint->x()){
                this->updateLocation(-this->stats->getSpeed(), 0);
            }
        }
    }
    if(nextPoint != NULL && distance(nextPoint, new QPoint(this->x(), this->y())) <= 1 && this->path.size() > 0){
        nextPoint = *(this->path.begin());
        this->path.erase(this->path.begin());
    }
    else if(this->path.size() == 0){
        nextPoint = NULL;
    }
    //printf("ENEMY X: %d, ENEMY Y %d\n", this->x(), this->y());
    this->setGrav(true);
}

void Enemy::draw(QPainter * p){
    p->setBrush(Qt::red);
    p->drawEllipse(drawingX, drawingY, drawingHeight, drawingWidth);
}

void Enemy::handleCollision(GameObject * obj){
    if(Player * act = dynamic_cast<Player*>(obj)){
        //TODO this is actually wrong, but it works for now
        if(act->isAlly() == this->isAlly()){
            this->lockOn(act);
        }
    }
}

void Enemy::jump(){
    if(this->jumpCount++ < this->stats->getMaxJumps()){
        this->updateLocation(0, this->verticalSpeed);
    }

}

void Enemy::maximizeJump(){

}

void Enemy::resetJump(){
    this->jumpCount = 0;
}

void Enemy::lockOn(Actor* p){
    AstarGraph& graph = AstarGraph::getInstance();
    if(!lockedOn){
        this->lockedOn = true;
        this->lock = p;
        //instead of passing in coords of lock, determine optimal attack position
        this->path = graph.findPath(new QPoint(this->x(), this->y()), new QPoint(p->x(), p->y()));
    }
    //always lock onto the closest adversary
    else{
       if(distance(this, p) < distance(this, lock)){
           this->lock = p;
           //change this so instead of generating a new path, we modify the existing path
           //instead of passing in coords of enemy, determine optimal attack position
           this->path = graph.findPath(new QPoint(this->x(), this->y()), new QPoint(p->x(), p->y()));
       }
       else if(distance(this, p) == distance(this, lock) && this->path.size() > 0){
           this->path = graph.modifyPath(this->path, new QPoint(p->x(), p->y()));
           /*
           if(this->path.size() > 1){
               QPoint * last = this->path[this->path.size()-1];
               QPoint * second = this->path[this->path.size()-2];
               QPoint target = QPoint(p->x(), p->y());
               if((target.x() < last->x() && target.x() > second->x())
                       || (target.x() > last->x() && target.x() < second->x())){
                   this->path.erase(--(this->path.end()));
               }
               this->path.push_back(&target);
           }
           */
       }
       else if(this->path.size() == 0){
           this->path = graph.findPath(new QPoint(this->x(), this->y()), new QPoint(p->x(), p->y()));
           /*
           if(this->path.size() > 1){
               QPoint * last = this->path[this->path.size()-1];
               QPoint * second = this->path[this->path.size()-2];
               QPoint target = QPoint(p->x(), p->y());
               if((target.x() < last->x() && target.x() > second->x())
                       || (target.x() > last->x() && target.x() < second->x())){
                   this->path.erase(--(this->path.end()));
               }
               this->path.push_back(&target);
           }
           */
       }
    }
}


void Enemy::cancelLock(){
    this->lockedOn = false;
}

bool Enemy::canAttack(){
    //bool stuff based on player's position, speed, and size of enemy's attack
    //this will be more if we are not locked in
    return lockedOn && false;
}

Attack* Enemy::generateAttack(){
    return NULL;
}
