#include "ourmath.h"
#include <math.h>

double inline square(int x){
    return pow(x, 2);
}

double distance(AstarNode * one, AstarNode * two){
   QPoint * first = new QPoint(one->x(), one->y());
   QPoint * second = new QPoint(two->x(), two->y());
   return distance(first, second);
}

double distance(QPoint * one, QPoint * two){
    return sqrt(square(one->x() - two->x()) + square(one->y() - two->y()));
}

double distance(GameObject * one, GameObject*two){
    int x1 = one->x();
    int y1 = one->y();
    int xr1 = x1 +one->getWidth();
    int yb1 = y1 - one->getHeight();
    int x2 = one->x();
    int y2 = one->y();
    int xr2 = x2 +one->getWidth();
    int yb2 = y2 - one->getHeight();
    bool top = y2 < yb1;
    bool right = xr2 < x1;
    bool left = x2 > xr1;
    bool bottom = yb2 > y1;
    int dx = 0;
    int dy = 0;
    if(left){
        dx = x2 - xr2;
    }
    if(right){
        dx = xr2 - x1;
    }
    if(top){
        dy = y2-yb1;
    }
    if(bottom){
       dy = yb2 -y1;
    }
    return sqrt(square(dx) + square(dy));
}
