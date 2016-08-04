#ifndef KDTREE_H
#define KDTREE_H

#include <vector>
#include <queue>
#include "ourmath.h"
#include "GameObjects/gameobject.h"
#include "assert.h"
/*
#undef assert
#define assert void(0);
*/



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
            for(i; i != elems.end(); i++){
                T elem = *i;
                if(obj->getCollRadius() >= elem->getCollRadius()){
                    elems.insert(i, obj);
                    break;
                }
            }
            if(i == elems.end()){
                elems.push_back(obj);
            }
            //sort by collRadius, greatest to least
        }
        assert(satisfiesProp());
        assert(this->size()==startSize+1);
        printf("\nsize: %d, count %d\n", this->size(), this->countNodes());
        //assert(this->size() == this->countNodes());
    }

    void remove(T obj){
        int startSize = this->size();
        removeObj(obj, false);
        printf("\nthis->size(): %d, start %d\n", this->size(), startSize);
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

    std::vector<T> rangeSearch(T obj, int range){
        int startSize = this->size();
        std::vector<T> vector = std::vector<T>();
        rangeRecursive(obj, &vector, range, this->root, 0);
        assert(satisfiesProp());
        assert(this->size() == startSize);
        assert(this->size() == this->countNodes());
        return vector;
    }

    std::vector<T> rangeSearch(T obj, int range, int width, int height){
        int startSize = this->size();
        std::vector<T> vector = std::vector<T>();
        rangeRecursive(obj, &vector, range, this->root, 0, width, height);
        assert(satisfiesProp());
        assert(this->size() == startSize);
        assert(this->size() == this->countNodes());
        return vector;
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
            else{
                return findNode(obj, ++level, current->right, current);
            }
        }
        else{
            if(obj->y() < current->data->y()){
                return findNode(obj, ++level, current->left, current);
            }
            else{
                return findNode(obj, ++level, current->right, current);
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
            else if(level % 2 == 0){
                if(toDelete->data->x() < parent->data->x()){
                    parent->left = NULL;
                }
                else{
                    parent->right = NULL;
                }
            }
            else{
                if(toDelete->data->y() < parent->data->y()){
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
            if(level % 2 == 0){
                if(parent == 0){
                     root = 0;
                }
                else if(toDelete->data->x() < parent->data->x()){
                    parent->left = 0;
                }
                else{
                    parent->right = 0;
                }
             }
             else{
                if(parent == 0){
                    root = 0;
                }
                else if(toDelete->data->y() < parent->data->y()){
                    parent->left = 0;
                }
                else{
                    parent->right = 0;
                }
             }
             if(deletion){
                 delete toDelete;
             }
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

    void rangeRecursive(T obj, std::vector<T>* vec, int range, Node<T>* node, int level){
        if(node == 0){
            return;
        }
        int x = obj->x();
        int y = obj->y();
        int treeX = node->data->x();
        int treeY = node->data->y();
        double dist = distance(obj, node->data);
        if(dist < range){
            vec->push_back(node->data);
        }
        if(level % 2 == 0){
            if(x < treeX){
                rangeRecursive(obj, vec, range, node->left, ++level);
                if(x + range > treeX){
                    rangeRecursive(obj, vec, range, node->right, ++level);
                }
            }
            else{
                rangeRecursive(obj, vec, range, node->right, ++level);
                if(x-range < treeX){
                    rangeRecursive(obj, vec, range, node->left, ++level);
                }
            }
        }
        else{
            if(y < treeY){
                rangeRecursive(obj, vec, range, node->left, ++level);
                if(y + range > treeY){
                    rangeRecursive(obj, vec, range, node->right, ++level);
                }
            }
            else{
                rangeRecursive(obj, vec, range, node->right, ++level);
                if(y - range < treeY){
                    rangeRecursive(obj, vec, range, node->left, ++level);
                }
            }
        }
    }

    void rangeRecursive(T obj, std::vector<T>* vec, int range, Node<T>* node, int level, int width, int height){
        if(node == 0){
            return;
        }
        int x = obj->x();
        int y = obj->y();
        int treeX = node->data->x();
        int treeY = node->data->y();
        double dist = distance(obj, node->data);
        if(dist < range){
            vec->push_back(node->data);
        }
        if(level % 2 == 0){
            if(x < treeX){
                rangeRecursive(obj, vec, range, node->left, ++level, width, height);
                if(x + width + range > treeX){
                    rangeRecursive(obj, vec, range, node->right, ++level, width, height);
                }
            }
            else{
                rangeRecursive(obj, vec, range, node->right, ++level, width, height);
                if(x-range < treeX + node->data->getWidth()){
                    rangeRecursive(obj, vec, range, node->left, ++level, width, height);
                }
            }
        }
        else{
            if(y < treeY){
                rangeRecursive(obj, vec, range, node->left, ++level, width, height);
                if(y + range > treeY - node->data->getHeight()){
                    rangeRecursive(obj, vec, range, node->right, ++level, width, height);
                }
            }
            else{
                rangeRecursive(obj, vec, range, node->right, ++level);
                if(y - height - range < treeY){
                    rangeRecursive(obj, vec, range, node->left, ++level, width, height);
                }
            }
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
        printf("\nstart %d, this->size() %d\n", this->countNodes(), this->size());
        assert(satisfiesProp());
        //assert(this->countNodes() == this->size());
        assert(startSize-1 == this->size());
    }
};

#endif // KDTREE_H
