#ifndef ASTARNODE_H
#define ASTARNODE_H

#include <vector>
#include <QPoint>
#include <unordered_set>
using namespace std;


class AstarNode
{
public:
    AstarNode();
    AstarNode(QPoint *);
    int x();
    int y();
    void addNeighbor(AstarNode*);
    unordered_set<AstarNode*> getNeighbors();
    void removeNeighbor(AstarNode*);
    bool equals(AstarNode*);
    int getCollRadius();

private:
    int xPos;
    int yPos;
    unordered_set<AstarNode*> neighbors;

};

#endif // ASTARNODE_H
