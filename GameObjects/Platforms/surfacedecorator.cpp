#include "surfacedecorator.h"


SurfaceDecorator::SurfaceDecorator(Platform* plat, int x, int y, int w, int h):Platform(x, y, w, h)
{
    movementPlat = plat;
}

void SurfaceDecorator::update(){
    movementPlat->update();
}

void SurfaceDecorator::surfaceEffect(Actor * actor){

}
