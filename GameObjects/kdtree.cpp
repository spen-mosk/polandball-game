#include "kdtree.h"
#include <QPoint>
#include <queue>
#include <vector>
#include "level.h"

KDTree::KDTree()
{
   this->size = 0;
}

KDTree::~KDTree(){
    delete root;
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
    if(size == 0){
        root = node;
    }
    else{
        insertRecursive(obj, root, 0);
    }
    size++;
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
