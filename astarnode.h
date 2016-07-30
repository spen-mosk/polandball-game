#ifndef ASTARNODE_H
#define ASTARNODE_H

#include <vector>
#include <QPoint>
using namespace std;


class AstarNode
{
public:
    AstarNode();
    AstarNode(QPoint *);
    int x();
    int y();
    void addNeighbor(AstarNode*);
    vector<AstarNode*> getNeighbors();

private:
    int xPos;
    int yPos;
    vector<AstarNode*> neighbors;

};

#endif // ASTARNODE_H
