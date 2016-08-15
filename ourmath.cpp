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

bool contains(int * one, int * two){
    return one[0] <= two[0] && one[2] >= two[2] && one[1] >= two[1] && one[3] <= two[3];
}

bool intersects(int * one, int * two){
    bool rightX = one[2] >= two[0] && one[2] <= two[2];
    bool leftX = one[0] >= two[0] && one[0] <= two[2];
    bool topY = one[1] >= two[3] && one[1] <= two[1];
    bool bottomY = one[3] >= two[3] && one[3] <= two[1];
    if(rightX){
        if(topY){
            return true;
        }
        if(bottomY){
            return true;
        }
        if(one[1] >= two[1] && one[3] <= two[3]){
            return true;
        }
    }
    if(leftX){
        if(topY){
            return true;
        }
        if(bottomY){
            return true;
        }
        if(one[1] >= two[1] && one[3] <= two[3]){
            return true;
        }
    }
    if(topY){
        if(one[0] <= two[0] && one[2] >= two[2]){
            return true;
        }
    }
    if(bottomY){
        if(one[0] <= two[0] && one[2] >= two[2]){
            return true;
        }
    }
    return false;
}

double distance(GameObject * one, GameObject*two){
    int x1 = one->x();
    int y1 = one->y();
    int xr1 = x1 +one->getWidth();
    int yb1 = y1 - one->getHeight();
    int x2 = two->x();
    int y2 = two->y();
    int xr2 = x2 +two->getWidth();
    int yb2 = y2 - two->getHeight();
    bool top = y2 < yb1;
    bool right = xr2 < x1;
    bool left = x2 > xr1;
    bool bottom = yb2 > y1;
    int dx = 0;
    int dy = 0;
    if(left){
        dx = x2 - xr1;
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
