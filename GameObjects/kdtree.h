#ifndef KDTREE_H
#define KDTREE_H

#include <vector>
#include <queue>
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
            Node(){
                this->left = 0;
                this->right = 0;
            };
            ~Node(){
                delete data;
                delete left;
                delete right;
            };
            Node * left;
            Node * right;
            GameObject * data;
            int priority;
            bool operator <(const Node rhs) const{
                return this->priority < rhs.priority;
            }
    };
    Node * root;
    int size;
    void insertRecursive(GameObject*, Node*,int level);
    void kNNRecursive(GameObject*, std::priority_queue<Node*>*, int, Node*, int);
};

#endif // KDTREE_H
