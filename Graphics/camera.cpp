#include "camera.h"
#include <QSize>
#include "GameObjects/Actors/player.h"

Camera::Camera(int meters, QWidget * parent)
{
    metersPerScreen = meters;
    QSize size = parent->frameSize();
    screenWidth = size.width();
    screenHeight = size.height();
    pixPerMeter = screenWidth / meters;
}

Camera::~Camera(){
}

std::vector<GameObject *> * Camera::snapshot(Player * center, std::vector<GameObject *> actors){
    double leftX = center->getCenter()->x() - (metersPerScreen / 2);
    double rightX = center->getCenter()->x() + (metersPerScreen / 2);
    double bottomY = center->getCenter()->y() - ((screenHeight / pixPerMeter) / 2);
    double topY = center->getCenter()->y() + ((screenHeight / pixPerMeter) / 2);
    std::vector<GameObject *> * toDraw = new std::vector<GameObject*>();
    for(std::vector<GameObject *>::iterator it = actors.begin(); it != actors.end(); ++it) {
        GameObject * current = *it;
        if(current->getX() + current->getWidth() > leftX && current->getX() < rightX){
            if(current->getY() - current->getHeight() < topY && current->getY() > bottomY){
                //convert
                //add to a list somehow
                double xDisplacement = current->getX() - leftX;
                double yDisplacement = topY - current->getY();
                double xPixels = xDisplacement * pixPerMeter;
                double yPixels = yDisplacement * pixPerMeter;
              //  printf("%d",pixPerMeter);
               // printf("x: %d, y: %d\n", xDisplacement * pixPerMeter, yDisplacement * pixPerMeter);
                current->drawingX = xPixels;
                current->drawingY = yPixels;
                double heightPixels = current->getHeight() * pixPerMeter;
                double widthPixels = current->getWidth() * pixPerMeter;
                current->drawingWidth = widthPixels;
                current->drawingHeight = heightPixels;
                toDraw->push_back(current);
            }
        }
    }
    center->drawingX = screenWidth / 2;
    center->drawingY = screenHeight / 2;
    center->drawingHeight = center->getHeight() * pixPerMeter;
    center->drawingWidth = center->getWidth() * pixPerMeter;
    toDraw->push_back(center);
    return toDraw;
}
