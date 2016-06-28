#include "camera.h"
#include <QSize>

Camera::Camera(int meters, double pix, QWidget * parent)
{
    metersPerScreen = meters;
    pixPerMeter = pix;
    QSize size = parent->frameSize();
    screenWidth = size.width();
    screenHeight = size.height();
}

std::vector<GameObject *> * Camera::snapshot(GameObject * center, std::vector<GameObject *> actors){
    int leftX = center->getX() - (metersPerScreen / 2);
    int bottomY = center->getY() - (metersPerScreen / 2);
    int rightX = center->getX() + (metersPerScreen / 2);
    int topY = center->getY() + (metersPerScreen / 2);
    std::vector<GameObject *> * toDraw = new std::vector<GameObject*>();
    for(std::vector<GameObject *>::iterator it = actors.begin(); it != actors.end(); ++it) {
        GameObject * current = *it;
        if(current->getX() > leftX && current->getY() < rightX){
            if(current->getY() < topY && current->getY() > bottomY){
                //convert
                //add to a list somehow
                int xDisplacement = current->getX() - leftX;
                int yDisplacement = topY - current->getY();
                double xPixels = xDisplacement * pixPerMeter;
                double yPixels = yDisplacement * pixPerMeter;
                current->drawingX = xPixels;
                current->drawingY = yPixels;
                toDraw->push_back(current);
            }
        }
    }
    return toDraw;
}
