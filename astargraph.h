#ifndef ASTARGRAPH_H
#define ASTARGRAPH_H
#include <QPoint>
#include <vector>
#include "GameObjects/kdtree.h"
#include "astarnode.h"

//Uses singleton pattern described here: http://stackoverflow.com/questions/1008019/c-singleton-design-pattern
class AstarGraph
{
public:
    void addNode(QPoint*);
    std::vector<QPoint*> findPath(QPoint*, QPoint*);
    static AstarGraph& getInstance(){
        static AstarGraph instance;
        return instance;
    }

    AstarGraph(AstarGraph const&) = delete;
    void operator=(AstarGraph const&) = delete;
private:
    int nodeDist;
    AstarGraph(){
        nodeDist = 5;
    }
    KDTree<AstarNode*> tree;

};

#endif // ASTARGRAPH_H
