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
    int size();
    void insert(GameObject *);
    void remove(GameObject*);
    void erase(GameObject*);
    GameObject* get(int);
    std::vector<GameObject *> kNN(GameObject*, int);
    std::vector<GameObject*> rangeSearch(GameObject*, int);

private:
    class Node{
        public:
            Node(){
                this->left = 0;
                this->right = 0;
            };
            ~Node(){
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
    std::vector<GameObject*> elems;
    void insertRecursive(GameObject*, Node*,int level);
    Node ** findNode(GameObject *, int, Node *, Node*);
    void deleteNode(Node *, Node *, bool);
    void kNNRecursive(GameObject*, std::priority_queue<Node*>*, int, Node*, int);
    void rangeRecursive(GameObject*, std::vector<GameObject*>*, int, Node*, int);
    void removeObj(GameObject*, bool);
};

#endif // KDTREE_H
