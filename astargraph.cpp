#include "astargraph.h"

void AstarGraph::addNode(QPoint * point){
    AstarNode * node = new AstarNode(point);
    tree.insert(node);
}
