#include "platform.h"
#include "astargraph.h"

int Platform::num = 0;

Platform::Platform(int x, int y, int h, int w) :
        GameObject(x, y, h, w, 1, "Plat"+std::to_string(Platform::num++)){
    AstarGraph& graph = AstarGraph::getInstance();
    graph.addPlat(this);
    std::vector<AstarNode*> nodes = vector<AstarNode*>();
    int start = x+1;
    while(start < x + w-1){
        nodes.push_back(new AstarNode(new QPoint(start, y + 1)));
        start += 3;
    }
    nodes.push_back(new AstarNode(new QPoint(x + w, y + 1)));
    graph.addNodes(nodes);
}

void Platform::draw(QPainter * painter){
    painter->setBrush(Qt::white);
    QPoint *point = getDrawingPosition();
    painter->drawRect(point->x(), point->y(), drawingWidth, drawingHeight);
}

void Platform::handleCollision(GameObject * obj){
    if(Platform *p = dynamic_cast<Platform*>(obj)){
        return;
    }
    int x = obj->x();
    int y = obj->y();
    int w = obj->getWidth();
    int h = obj->getHeight();
    int centerX = x + obj->getWidth() / 2;
    int centerY = y + obj->getHeight() / 2;
    int actorLeft = x;
    int actorRight = x + w;
    int actorTop = y;
    int actorBottom = y - h;
    int platLeft = this->x();
    int platRight = this->x() + this->getWidth();
    int platTop = this->y();
    int platBottom = this->y() - this->getHeight();
    obj->setGrav(true && obj->getGrav());
    if(actorLeft > platLeft && actorLeft < platRight
            && centerY < platTop && centerY > platBottom){
        int offsetX = this->x() + this->getWidth() - actorLeft;
        obj->setX(x + offsetX);
    }
    else if(actorRight < platRight && actorRight > platLeft
            && centerY < platTop && centerY > platBottom){
        int offsetX = actorRight - platLeft;
        obj->setX(x - offsetX);
    }
    else if(actorTop < platTop && actorTop > platBottom
            && centerX < platRight && centerX > platLeft){
        int offsetY = actorTop - platBottom;
        obj->setY(y - offsetY);
    }
    else if(actorBottom <= platTop + obj->getHeight() && actorBottom > platBottom
            && centerX < platRight && centerX > platLeft){
        obj->setGrav(false);
        int offsetY = this->y() - actorBottom;
        obj->setY(platTop + obj->getHeight());
    }
}

void Platform::update(){}
