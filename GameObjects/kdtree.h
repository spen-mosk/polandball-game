#ifndef KDTREE_H
#define KDTREE_H

#include <vector>
#include <queue>
#include <climits>
#include "ourmath.h"
#include "GameObjects/gameobject.h"
#include "assert.h"
#undef assert
#define assert void(0);



template<class T>
class KDTree
{

public:
    KDTree()
    {
        this->elems = std::vector<T>();
    }

    ~KDTree(){
         delete root;
    }

    int size(){
        return elems.size();
    }

    std::vector<T> getElems(){
        return this->elems;
    }

    bool satisfiesProp(){
        if(root == 0){
            return true;
        }
        int level = -1;
        bool satisfies = true;
        std::vector<Node<T>*> *children = new std::vector<Node<T>*>();
        children->push_back(root);
        int count = 0;
        while(children->size() > 0){
            level++;
            std::vector<Node<T>*> *newChildren = new std::vector<Node<T>*>();
            for(int i = 0; i < children->size(); i++){
                Node<T> * current = (*children)[i];
                if(current->left != 0){
                    newChildren->push_back(current->left);
                    if(level % 2 == 0){
                        satisfies = satisfies && current->left->data->x() < current->data->x();
                    }
                    else{
                        satisfies = satisfies && current->left->data->y() < current->data->y();
                    }
                }
                if(current->right != 0){
                    newChildren->push_back(current->right);
                    if(level % 2 == 0){
                        satisfies = satisfies && current->right->data->x() >= current->data->x();
                    }
                    else{
                        satisfies = satisfies && current->right->data->y() >= current->data->y();
                    }
                }
            }
            children = newChildren;
        }
        return satisfies;
    }

    void rebuildTree(){
        if(root == 0){
            return;
        }
        std::vector<Node<T>**> broken = std::vector<Node<T>**>();
        brokenInvariants(root, &broken, INT_MIN, INT_MIN, INT_MAX, INT_MAX, 0);
        for(int i = 0; i < broken.size(); i++){
            Node<T> ** nodes = broken[i];
            T obj = nodes[0]->data;
            this->deleteNode(nodes[0], nodes[1], false);
            this->insertRecursive(obj, root, 0);
            assert(this->countNodes() == this->size());
        }
        assert(this->satisfiesProp());
    }


    int countNodes(){
        if(root==NULL){
            return 0;
        }
        std::vector<Node<T>*> *children = new std::vector<Node<T>*>();
        children->push_back(root);
        int count = 0;
        while(children->size() > 0){
            std::vector<Node<T>*> *newChildren = new std::vector<Node<T>*>();
            for(int i = 0; i < children->size(); i++){
                count++;
                Node<T> * current = (*children)[i];
                if(current->left != 0){
                    newChildren->push_back(current->left);
                }
                if(current->right != 0){
                    newChildren->push_back(current->right);
                }
            }
            children = newChildren;
        }
        return count;
    }

    void insert(T obj){
        int startSize = this->size();
        Node<T> *node = new Node<T>();
        node->data = obj;
        if(size() == 0 || root == 0){
            this->elems.push_back(obj);
            root = node;
        }
        else{
            insertRecursive(obj, root, 0);
            auto i = elems.begin();
            int counter = 0;
            for(i; i != elems.end(); i++){
                T elem = *i;
                if(obj->getCollRadius() >= elem->getCollRadius()){
                    elems.insert(i, obj);
                    break;
                }
                counter++;
            }
            if(counter == elems.size()){
                elems.push_back(obj);
            }
            //sort by collRadius, greatest to least
        }
        assert(satisfiesProp());
        assert(this->size()==startSize+1);
        //assert(this->size() == this->countNodes());
    }

    void remove(T obj){
        int startSize = this->size();
        removeObj(obj, false);
        assert(startSize==this->size()+1);
        assert(this->size() == this->countNodes());
    }

    void erase(T obj){
        removeObj(obj, true);
    }

    T get(int index){
        return this->elems[index];
    }

    std::vector<T> kNN(T obj, int k){
        std::priority_queue<Node<T> *, std::vector<Node<T>*>, comparator> queue;
        kNNRecursive(obj, &queue, k, this->root, 0);
        std::vector<T> list;
        int size = queue.size();
        for(int i = 0; i < size; i++){
            Node<T> * node = (Node<T>*)queue.top();
            queue.pop();
            list.push_back(node->data);
        }
        assert(satisfiesProp());
        return list;
    }


    std::vector<T> rangeSearch(T obj, int x, int y, int xw, int yh){
        if(root == 0){
            return std::vector<T>();
        }
        if(obj->y() < 5 && obj->getWidth() == 2){
            printf("STOP\n");
        }
        int plane[4] = {x, y, xw, yh};
        int region[4] = {INT_MIN, INT_MAX, INT_MAX, INT_MIN};
        std::vector<T> objs = std::vector<T>();
        rangeRecursive(obj, &objs, root, 0, plane, region);
        return objs;
    }

private:
    template<class E>
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
            Node<E> * left;
            Node<E> * right;
            E data;
            int priority;
    };

    struct comparator{

        bool operator()(Node<T> * node1, Node<T>* node2){
            return node1->priority < node2->priority;
        }

    };

    Node<T> * root;
    std::vector<T> elems;

    void insertRecursive(T obj, Node<T>* compare,int level){
        int x = obj->x();
        int y = obj->y();
        int treeX = compare->data->x();
        int treeY = compare->data->y();
        if(level % 2 == 0){
            if(x < treeX){
                if(compare->left == 0){
                    compare->left = new Node<T>();
                    compare->left->data = obj;
                }
                else{
                    insertRecursive(obj, compare->left, ++level);
                }
            }
            else{
                if(compare->right == 0){
                    compare->right = new Node<T>();
                    compare->right->data = obj;
                }
                else{
                    insertRecursive(obj, compare->right, ++level);
                }
            }
        }
        else{
            if(y < treeY){
                if(compare->left == 0){
                    compare->left = new Node<T>();
                    compare->left->data = obj;
                }
                else{
                    insertRecursive(obj, compare->left, ++level);
                }
            }
            else{
                if(compare->right == 0){
                    compare->right = new Node<T>();
                    compare->right->data = obj;
                }
                else{
                    insertRecursive(obj, compare->right, ++level);
                }
            }
        }
    }

    Node<T> ** findNode(T obj, int level, Node<T> * current, Node<T>* parent){
        if(current == 0){
            return NULL;
        }
        if(parent != 0){
            parent->priority = level -1;
        }

        if(obj->equals(current->data)){
            Node<T>* returnable[2];
            current->priority = level;
            returnable[0] = current;
            returnable[1] = parent;
            return returnable;
        }
        if(level % 2 == 0){
            if(obj->x() < current->data->x()){
                return findNode(obj, ++level, current->left, current);
            }
            else if(obj->x() > current->data->x()){
                return findNode(obj, ++level, current->right, current);
            }
            else{
                Node<T> ** right = findNode(obj, level+1, current->right, current);
                Node<T> ** left =  findNode(obj, level+1, current->left, current);
                if(right != 0){
                    return right;
                }
                return left;
            }
        }
        else{
            if(obj->y() < current->data->y()){
                return findNode(obj, ++level, current->left, current);
            }
            else if(obj->y() > current->data->y()){
                return findNode(obj, ++level, current->right, current);
            }
            else{
                Node<T> ** right = findNode(obj, level+1, current->right, current);
                Node<T> ** left =  findNode(obj, level+1, current->left, current);
                if(right != 0){
                    return right;
                }
                return left;
            }
        }
    }

    void deleteNode(Node<T> * toDelete, Node<T>* parent, bool deletion){
        int level;
        if(parent == 0){
            level = -1;
        }
        else{
            level = parent->priority;
        }
        if(toDelete->left != 0 || toDelete->right != 0){
            std::vector<Node<T>*> *children = new std::vector<Node<T>*>();
            std::vector<T> *reInsert = new std::vector<T>();
            children->push_back(toDelete);
            while(children->size() > 0){
                std::vector<Node<T>*> *newChildren = new std::vector<Node<T>*>();
                for(int i = 0; i < children->size(); i++){
                    Node<T> * current = (*children)[i];
                    if(current->left != 0){
                        reInsert->push_back(current->left->data);
                        newChildren->push_back(current->left);
                    }
                    if(current->right != 0){
                        reInsert->push_back(current->right->data);
                        newChildren->push_back(current->right);
                    }
                }
                children = newChildren;
            }
            assert(reInsert->size() != this->size());
            if(parent == 0){
                root = NULL;
            }
            else{
                if(parent->left !=  NULL && toDelete->data->equals(parent->left->data)){
                    parent->left = NULL;
                }
                else{
                    parent->right = NULL;
                }

            }
            toDelete->left = 0;
            toDelete->right = 0;
            for(int a = 0; a < reInsert->size(); a++){
                if(root == 0){
                    root = new Node<T>();
                    root->data = (*reInsert)[a];
                }
                else{
                    this->insertRecursive((*reInsert)[a], root, 0);
                }
            }
            if(deletion){
                delete toDelete;
            }
        }
        else{
            if(parent == 0){
                root = 0;
            }
            else if(parent->left !=  NULL && toDelete->data->equals(parent->left->data)){
                parent->left = NULL;
            }
            else{
                parent->right = NULL;
            }
        }
        if(deletion){
            delete toDelete;
        }
    }

    void kNNRecursive(T obj, std::priority_queue<Node<T>*, vector<Node<T>*>, comparator>* queue, int k, Node<T>* node, int level){
        if(node == 0){
            return;
        }
        int x = obj->x();
        int y = obj->y();
        int treeX = node->data->x();
        int treeY = node->data->y();
        int priority = distance(obj, node->data);
        node->priority = priority;
        queue->push(node);
        if(queue->size() > k){
            queue->pop();
        }
        if(level % 2 == 0){
            if(x < treeX){
                kNNRecursive(obj, queue, k, node->left, ++level);
                Node<T> * greatest = queue->top();
                if(queue->size() < k || treeX-x < greatest->priority){
                    kNNRecursive(obj, queue, k, node->right, ++level);
                }
            }
            else{
                kNNRecursive(obj, queue, k, node->right, ++level);
                Node<T> * greatest = queue->top();
                if(queue->size() < k || x-treeX < greatest->priority){
                    kNNRecursive(obj, queue, k, node->left, ++level);
                }
            }
        }
        else{
            if(y < treeY){
                kNNRecursive(obj, queue, k, node->left, ++level);
                Node<T> * greatest = queue->top();
                if(queue->size() < k || treeY - y < greatest->priority){
                    kNNRecursive(obj, queue, k, node->right, ++level);
                }
            }
            else{
                kNNRecursive(obj, queue, k, node->right, ++level);
                Node<T> * greatest = queue->top();
                if(queue->size() < k || y - treeY < greatest->priority){
                    kNNRecursive(obj, queue, k, node->left, ++level);
                }
            }
        }
    }

    void fillTree(Node<T> * node, std::vector<T> * vec){
        std::vector<Node<T>*> *children = new std::vector<Node<T>*>();
        children->push_back(node);
        while(children->size() > 0){
            std::vector<Node<T>*> *newChildren = new std::vector<Node<T>*>();
            for(int i = 0; i < children->size(); i++){
                Node<T> * current = (*children)[i];
                vec->push_back(current->data);
                if(current->left != 0){
                    newChildren->push_back(current->left);
                }
                if(current->right != 0){
                    newChildren->push_back(current->right);
                }
            }
            children = newChildren;
        }
    }

    void rangeRecursive(T obj, std::vector<T> *vec, Node<T> *node, int level, int* region, int*currentReg){
        int leftQuad[4] = {currentReg[0], currentReg[1], currentReg[2], currentReg[3]};
        int rightQuad[4] = {currentReg[0], currentReg[1], currentReg[2], currentReg[3]};
        if(level % 2 == 0){
            leftQuad[2] = node->data->x();
            rightQuad[0] = node->data->x();
        }
        else{
            leftQuad[1] = node->data->y();
            rightQuad[3] = node->data->y();
        }
        T data = node->data;
        int objs[4] = {data->x(),data->y(), data->x() + data->getWidth(), data->y() - data->getHeight()};
        if(intersects(region, objs) || intersects(objs, region)){
            vec->push_back(data);
        }
        if(contains(region, leftQuad)){
            fillTree(node, vec);
        }
        else if(intersects(region, leftQuad) || intersects(leftQuad, region)){
            if(node->left != 0){
                printf("Going Left\n");
                rangeRecursive(obj, vec, node->left, level+1, region, leftQuad);
            }
        }
        if(contains(region, rightQuad)){
            fillTree(node, vec);
        }
        else if(intersects(region, rightQuad) || intersects(rightQuad, region)){
            if(node->right != 0){
                printf("Going Right\n");
                rangeRecursive(obj, vec, node->right, level+1,  region, rightQuad);
            }
        }
    }

    void brokenInvariants(Node<T> * current, std::vector<Node<T>**> *vec, int minX, int minY, int maxX, int maxY, int level){
        int leftMaxX = maxX, leftMaxY = maxY;
        int rightMinX = minX, rightMinY = minY;
        if(level % 2 == 0){
            leftMaxX = current->data->x();
            rightMinX = current->data->x();
        }
        else{
            leftMaxY = current->data->y();
            rightMinY = current->data->y();
        }
        if(current->left != 0 && (current->left->data->x() > leftMaxX || current->left->data->x() < minX
                   || current->left->data->y() > leftMaxY || current->left->data->y() < minY)){
            Node<T> ** data = (Node<T>**)malloc(sizeof(Node<T>*) * 2);
            data[0] = current->left;
            data[1] = current;
            vec->push_back(data);
        }
        else if(current->left != 0){
            brokenInvariants(current->left, vec, minX, minY, leftMaxX, leftMaxY, level+1);
        }
        if(current->right != 0 && (current->right->data->x() > maxX || current->right->data->x() < rightMinX
                   || current->right->data->y() > maxY || current->right->data->y() < rightMinY)){
            Node<T> ** data = (Node<T>**)malloc(sizeof(Node<T>*) * 2);
            data[0] = current->right;
            data[1] = current;
            vec->push_back(data);
        }
        else if(current->right != 0){
            brokenInvariants(current->right, vec, rightMinX, rightMinY, maxX, maxY, level+1);
        }
    }

    void removeObj(T obj, bool deletion){
        int startSize = this->size();
        Node<T> ** data = findNode(obj, 0, root, 0);
        if(data != NULL){
            deleteNode(data[0], data[1], deletion);
            auto iter = std::remove(elems.begin(), elems.end(), obj);
            elems.erase(iter);
        }
        assert(satisfiesProp());
        //assert(this->countNodes() == this->size());
        assert(startSize-1 == this->size());
    }
};

#endif // KDTREE_H
