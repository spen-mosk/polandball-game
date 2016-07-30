#include "astarnode.h"

AstarNode::AstarNode()
{
    xPos = 0;
    yPos = 0;
    neighbors = vector<AstarNode*>();
}

AstarNode::AstarNode(QPoint * point){
    xPos = point->x();
    yPos = point->y();
    neighbors = vector<AstarNode*>();
}

void AstarNode::addNeigbor(AstarNode * node){
    this->neighbors.push_back(node);
}

int AstarNode::x(){
    return xPos;
}

int AstarNode::y(){
    return yPos;
}
