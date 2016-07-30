#ifndef ASTARGRAPH_H
#define ASTARGRAPH_H
#include <QPoint>
#include <vector>
#include "GameObjects/kdtree.h"
#include "GameObjects/Platforms/platform.h"
#include "astarnode.h"
using namespace std;
//Uses singleton pattern described here: http://stackoverflow.com/questions/1008019/c-singleton-design-pattern
class AstarGraph
{
public:
    void addNode(QPoint*);
    vector<QPoint*> findPath(QPoint*, QPoint*);
    static AstarGraph& getInstance(){
        static AstarGraph instance;
        return instance;
    }
    int getNodeDist();
    void addPlat(Platform* plat);
    AstarGraph(AstarGraph const&) = delete;
    void operator=(AstarGraph const&) = delete;
private:
    int nodeDist;
    vector<Platform*> plats = vector<Platform*>();
    AstarGraph(){
        nodeDist = 5;
    }
    KDTree<AstarNode*> tree;
    bool intersectsPlat(AstarNode*, AstarNode*);

};

#endif // ASTARGRAPH_H
