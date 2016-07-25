#include "kdtree.h"
#include <QPoint>
#include <queue>
#include <vector>
#include <limits.h>
#include "level.h"

KDTree::KDTree()
{
   this->elems = std::vector<GameObject*>();
}

KDTree::~KDTree(){
    delete root;
}

GameObject * KDTree::get(int index){
    return this->elems[index];
}

KDTree::Node ** KDTree::findNode(GameObject* obj, int level, Node * current, Node * parent){
    if(current == 0){
        return NULL;
    }
    if((obj->getX() == current->data->getX() && obj->getY() == current->data->getY())){
        Node* returnable[2];
        current->priority = level;
        if(parent != 0){
            parent->priority = level -1;
        }
        returnable[0] = current;
        returnable[1] = parent;
        return returnable;
    }
    if(level % 2 == 0){
        if(obj->getX() < current->data->getX()){
            return findNode(obj, ++level, current->left, current);
        }
        else{
            return findNode(obj, ++level, current->right, current);
        }
    }
    else{
        if(obj->getY() < current->data->getY()){
            return findNode(obj, ++level, current->left, current);
        }
        else{
            return findNode(obj, ++level, current->right, current);
        }
    }
}

void KDTree::deleteNode(Node * toDelete, Node * parent, bool deletion){
    int level;
    if(parent == 0){
        level = -1;
    }
    else{
        level = parent->priority;
    }
    if(toDelete->left == 0 && toDelete->right == 0){
        if(level % 2 == 0){
           if(toDelete->data->getX() < parent->data->getX()){
               parent->left = 0;
           }
           else{
               parent->right = 0;
           }
        }
        else{
           if(toDelete->data->getY() < parent->data->getY()){
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
    else if(toDelete->left == 0){
        if(level % 2 == 0){
           if(toDelete->data->getX() < parent->data->getX()){
               parent->left = toDelete->right;
           }
           else{
               parent->right = toDelete->right;
           }
        }
        else{
           if(toDelete->data->getY() < parent->data->getY()){
               parent->left = toDelete->right;
           }
           else{
               parent->right = toDelete->right;
           }
        }
        toDelete->right = 0;
        if(deletion){
            delete toDelete;
        }
    }
    else if(toDelete->right == 0){
        if(level % 2 == 0){
           if(toDelete->data->getX() < parent->data->getX()){
               parent->left = toDelete->left;
           }
           else{
               parent->right = toDelete->left;
           }
        }
        else{
           if(toDelete->data->getY() < parent->data->getY()){
               parent->left = toDelete->left;
           }
           else{
               parent->right = toDelete->left;
           }
        }
        toDelete->left = 0;
        if(deletion){
            delete toDelete;
        }
    }
    else{
        Node * replace = toDelete->left;
        Node * replaceParent = toDelete;
        int currentLevel = level +1;
        toDelete->priority = currentLevel;
        if(currentLevel % 2 == 0){
            std::vector<Node*> *children = new std::vector<Node*>();
            toDelete->left->priority = ++currentLevel;
            children->push_back(toDelete->left);
            while(children->size() > 0){
                std::vector<Node*> *newChildren = new std::vector<Node*>();
                for(int i = 0; i < children->size(); i++){
                    Node * current = (*children)[i];
                    currentLevel = current->priority;
                    if(current->left != 0){
                        current->left->priority = currentLevel + 1;
                        if(replace == 0 || current->left->data->getX() > replace->data->getX()){
                            replace = current->left;
                            replaceParent = current;
                        }
                        newChildren->push_back(current->left);
                    }
                    if(current->right != 0){
                        current->right->priority = currentLevel + 1;
                        if(replace == 0 || current->right->data->getX() > replace->data->getX()){
                            replace = current->right;
                            replaceParent = current;
                        }
                        newChildren->push_back(current->right);
                    }
                }
                children = newChildren;
            }
            Node * replacement = new Node();
            replacement->data = replace->data;
            replacement->priority = replace->priority;
            replacement->left = toDelete->left;
            replacement->right = toDelete->right;
            if(parent == 0){
                root = replacement;
            }
            else if(toDelete->data->getX() < parent->data->getX()){
                parent->left = replacement;
            }
            else{
                parent->right = replacement;
            }
            toDelete->left = 0;
            toDelete->right = 0;
            if(deletion){
                delete toDelete;
            }
            deleteNode(replace, replaceParent, deletion);
        }
        else{
            std::vector<Node*> *children = new std::vector<Node*>();
            toDelete->left->priority = ++currentLevel;
            children->push_back(toDelete->left);
            while(children->size() > 0){
                std::vector<Node*> *newChildren = new std::vector<Node*>();
                for(int i = 0; i < children->size(); i++){
                    Node * current = (*children)[i];
                    currentLevel = current->priority;
                    if(current->left != 0){
                        current->left->priority = currentLevel + 1;
                        if(replace == 0 || current->left->data->getY() > replace->data->getY()){
                            replace = current->left;
                            replaceParent = current;
                        }
                        newChildren->push_back(current->left);
                    }
                    if(current->right != 0){
                        current->right->priority = currentLevel + 1;
                        if(replace == 0 || current->right->data->getY() > replace->data->getY()){
                            replace = current->right;
                            replaceParent = current;
                        }
                        newChildren->push_back(current->right);
                    }
                }
                children = newChildren;
            }
            Node * replacement = new Node();
            replacement->data = replace->data;
            replacement->priority = replace->priority;
            replacement->left = toDelete->left;
            replacement->right = toDelete->right;
            if(toDelete->data->getY() < parent->data->getY()){
                parent->left = replacement;
            }
            else{
                parent->right = replacement;
            }
            toDelete->left = 0;
            toDelete->right = 0;
            if(deletion){
                delete toDelete;
            }
            deleteNode(replace, parent, deletion);
        }
    }
}

void KDTree::removeObj(GameObject * obj, bool deletion){
    Node ** data = findNode(obj, 0, root, 0);
    if(data != NULL){
        deleteNode(data[0], data[1], deletion);
        elems.erase(std::remove(elems.begin(), elems.end(), obj));
    }
}

void KDTree::remove(GameObject * obj){
    removeObj(obj, false);
}

void KDTree::erase(GameObject* obj){
    removeObj(obj, true);
}




std::vector<GameObject*> KDTree::kNN(GameObject * obj, int k){
    std::priority_queue<Node *> queue;
    kNNRecursive(obj, &queue, k, this->root, 0);
    std::vector<GameObject *> list;
    int size = queue.size();
    for(int i = 0; i < size; i++){
        Node * node = (Node*)queue.top();
        queue.pop();
        list.push_back(node->data);
    }
    return list;
}

int KDTree::size(){
    return elems.size();
}

std::vector<GameObject*> KDTree::rangeSearch(GameObject * obj, int range){
   std::vector<GameObject*> vector = std::vector<GameObject*>();
   rangeRecursive(obj, &vector, range, this->root, 0);
   return vector;
}
void KDTree::rangeRecursive(GameObject*obj, std::vector<GameObject*> *vec, int range, Node * node, int level){
    if(node == 0){
       return;
    }
    int x = obj->getX();
    int y = obj->getY();
    int treeX = node->data->getX();
    int treeY = node->data->getY();
    int dist = distance((Actor*)obj, node->data);
    if(dist < range){
        vec->push_back(node->data);
    }
    if(level % 2 == 0){
        if(x < treeX){
            rangeRecursive(obj, vec, range, node->left, ++level);
            if(treeX-x < range){
                rangeRecursive(obj, vec, range, node->right, ++level);
            }
        }
        else{
            rangeRecursive(obj, vec, range, node->right, ++level);
            if(x-treeX < range){
                rangeRecursive(obj, vec, range, node->left, ++level);
            }
        }
    }
    else{
        if(y < treeY){
            rangeRecursive(obj, vec, range, node->left, ++level);
            if(treeY - y < range){
                rangeRecursive(obj, vec, range, node->right, ++level);
            }
        }
        else{
            rangeRecursive(obj, vec, range, node->right, ++level);
            if(y - treeY < range){
                rangeRecursive(obj, vec, range, node->left, ++level);
            }
        }
    }
}

void KDTree::kNNRecursive(GameObject* obj, std::priority_queue<Node*> *queue, int k, Node * node, int level){
    if(node == 0){
       return;
    }
    int x = obj->getX();
    int y = obj->getY();
    int treeX = node->data->getX();
    int treeY = node->data->getY();
    int priority = distance((Actor*)obj, node->data);
    node->priority = priority;
    queue->push(node);
    if(queue->size() > k){
        queue->pop();
    }
    if(level % 2 == 0){
        if(x < treeX){
            kNNRecursive(obj, queue, k, node->left, ++level);
            Node * greatest = queue->top();
            if(queue->size() < k || treeX-x < greatest->priority){
                kNNRecursive(obj, queue, k, node->right, ++level);
            }
        }
        else{
            kNNRecursive(obj, queue, k, node->right, ++level);
            Node * greatest = queue->top();
            if(queue->size() < k || x-treeX < greatest->priority){
                kNNRecursive(obj, queue, k, node->left, ++level);
            }
        }
    }
    else{
        if(y < treeY){
            kNNRecursive(obj, queue, k, node->left, ++level);
            Node * greatest = queue->top();
            if(queue->size() < k || treeY - y < greatest->priority){
                kNNRecursive(obj, queue, k, node->right, ++level);
            }
        }
        else{
            kNNRecursive(obj, queue, k, node->right, ++level);
            Node * greatest = queue->top();
            if(queue->size() < k || y - treeY < greatest->priority){
                kNNRecursive(obj, queue, k, node->left, ++level);
            }
        }
    }
}

void KDTree::insert(GameObject * obj){
    Node *node = new Node();
    node->data = obj;
    if(size() == 0){
        this->elems.push_back(obj);
        root = node;
    }
    else{
        insertRecursive(obj, root, 0);
        this->elems.push_back(obj);
    }
}

void KDTree::insertRecursive(GameObject* obj,Node * compare,  int level){
    int x = obj->getX();
    int y = obj->getY();
    int treeX = compare->data->getX();
    int treeY = compare->data->getY();
    if(level % 2 == 0){
        if(x < treeX){
            if(compare->left == 0){
                compare->left = new Node();
                compare->left->data = obj;
            }
            else{
                insertRecursive(obj, compare->left, ++level);
            }
        }
        else{
            if(compare->right == 0){
                compare->right = new Node();
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
                compare->left = new Node();
                compare->left->data = obj;
            }
            else{
                insertRecursive(obj, compare->left, ++level);
            }
        }
        else{
            if(compare->right == 0){
                compare->right = new Node();
                compare->right->data = obj;
            }
            else{
                insertRecursive(obj, compare->right, ++level);
            }
        }

    }

}
