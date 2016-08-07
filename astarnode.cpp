#include "astarnode.h"

AstarNode::AstarNode()
{
    xPos = 0;
    yPos = 0;
    neighbors = unordered_set<AstarNode*>();
}

AstarNode::AstarNode(QPoint * point){
    xPos = point->x();
    yPos = point->y();
    neighbors = unordered_set<AstarNode*>();
}

unordered_set<AstarNode*> AstarNode::getNeighbors(){
    return this->neighbors;
}

bool AstarNode::equals(AstarNode * other){
    if(other == 0){
        return false;
    }
    return other->x() == this->x() && other->y() == this->y();
}

void AstarNode::addNeighbor(AstarNode * node){
    this->neighbors.insert(node);
}

int AstarNode::getCollRadius(){
    return 0;
}

void AstarNode::removeNeighbor(AstarNode * node){
    neighbors.erase(node);
}

int AstarNode::x(){
    return xPos;
}

int AstarNode::y(){
    return yPos;
}
