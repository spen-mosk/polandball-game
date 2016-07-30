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
    void addNeigbor(AstarNode*);

private:
    int xPos;
    int yPos;
    vector<AstarNode*> neighbors;

};

#endif // ASTARNODE_H
