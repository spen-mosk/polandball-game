#ifndef KDTREE_H
#define KDTREE_H

#include <vector>
#include "GameObjects/gameobject.h"
class KDTree
{
public:
    KDTree();
    ~KDTree();
    void insert(GameObject *);
    std::vector<GameObject *> kNN(GameObject*, int);
private:
    class Node{
        public:
            Node();
            ~Node();
            Node * left;
            Node * right;
            GameObject * data;
            int priority;
    };
    class Compare{
        bool operator() (Node * first, Node * last){
            return first->priority < last->priority;
        }
    };

    Node * root;
    int size;
    std::vector<GameObject *> objs;
    void insertRecursive(GameObject*, Node*,int level);
};

#endif // KDTREE_H
