#include "astargraph.h"
#include <QSet>
#include <unordered_map>
#include <iterator>
#include <algorithm>
#include "ourmath.h"
using namespace std;

void AstarGraph::addNodes(vector<AstarNode*> nodes){
    for(int i = 1; i < nodes.size(); i++){
        nodes[i-1]->addNeighbor(nodes[i]);
        nodes[i]->addNeighbor(nodes[i-1]);
    }
    //mess with how long this gap should be
    vector<AstarNode*> nodes1 = tree.rangeSearch(nodes[0], 25);
    vector<AstarNode*> nodes2 = tree.rangeSearch(nodes[nodes.size() -1], 25);

    for(int i = 0; i < nodes1.size(); i++){
        if(!intersectsPlat(nodes1[i], nodes[nodes.size() -1])){
            nodes[0]->addNeighbor(nodes1[i]);
        }
    }

    for(int i = 0; i < nodes2.size(); i++){
        if(!intersectsPlat(nodes2[i], nodes[nodes.size() -1])){
            nodes[nodes.size() - 1]->addNeighbor(nodes2[i]);
        }
    }

    for(int a = 0; a < nodes.size(); a++){
        tree.insert(nodes[a]);
    }

}

void AstarGraph::addPlat(Platform * plat){
    plats.push_back(plat);
}

bool AstarGraph::intersectsPlat(AstarNode * one, AstarNode * two){

    return false;
}

vector<QPoint*> AstarGraph::modifyPath(vector<QPoint*> path, QPoint * end){
    AstarNode* endNode = new AstarNode(end);
    AstarNode *endNeighbor = tree.kNN(endNode, 1)[0];
    delete endNode;

    auto iter = std::find(path.begin(), path.end(), new QPoint(endNode->x(), endNode->y()));
    if(iter != path.end()){
        path.erase(iter, path.end());
        path.push_back(new QPoint(endNeighbor->x(), endNeighbor->y()));
        return path;
    }
    else{
        return findPath(path[0], end);
    }
}

vector<QPoint*> AstarGraph::findPath(QPoint * start, QPoint * end){
    //find the two closest nodes in the graph
    AstarNode* startNode = new AstarNode(start);
    AstarNode* endNode = new AstarNode(end);
    //found them
    AstarNode *startNeighbor = tree.kNN(startNode, 1)[0];
    AstarNode *endNeighbor = tree.kNN(endNode, 1)[0];
    delete endNode;
    delete startNode;

    //Now do the Astar search
    QSet<AstarNode*> closedSet = QSet<AstarNode*>();
    QSet<AstarNode*> openSet = QSet<AstarNode*>();
    openSet.insert(startNeighbor);
    unordered_map<AstarNode*, AstarNode*> cameFrom = unordered_map<AstarNode*, AstarNode*>();
    unordered_map<AstarNode*, int> gScore = unordered_map<AstarNode*, int>();
    gScore[startNeighbor] = 0;
    unordered_map<AstarNode*, int> fScore = unordered_map<AstarNode*, int>();
    fScore[startNeighbor] = distance(startNeighbor, endNeighbor);
    while(openSet.size() > 0){
        AstarNode* current = *openSet.begin();
        for(auto it = ++openSet.begin(); it != openSet.end(); ++it){
            AstarNode* node = *it;
            if(current == 0 || fScore[node] < fScore[current]){
                current = node;
            }
        }
        if(current->x() == endNeighbor->x() && current->y() == endNeighbor->y()){
            vector<QPoint*> totalPath = vector<QPoint*>();
            totalPath.push_back(new QPoint(current->x(), current->y()));
            while(cameFrom.find(current) != cameFrom.end()){
                current = cameFrom[current];
                totalPath.insert(totalPath.begin(), new QPoint(current->x(), current->y()));
            }
            return totalPath;
        }

        openSet.remove(current);
        closedSet += (current);
        unordered_set<AstarNode*> neighbors = current->getNeighbors();
        for(auto i = neighbors.begin(); i != neighbors.end(); i++){
            AstarNode* neighbor = *i;
            if(closedSet.contains(neighbor)){
                continue;
            }
            int tentGScore = gScore[current] + distance(current, neighbor);
            if(!openSet.contains(neighbor)){
               openSet += neighbor;
            }
            else if(tentGScore >= gScore[neighbor]){
                continue;
            }
            cameFrom[neighbor] = current;
            gScore[neighbor] = tentGScore;
            fScore[neighbor] = tentGScore + distance(endNeighbor, neighbor);
        }
    }
    return vector<QPoint*>();
}

int AstarGraph::getNodeDist(){
    return this->nodeDist;
}
