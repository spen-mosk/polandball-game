#include "surfacedecorator.h"

SurfaceDecorator::SurfaceDecorator(Platform plat)
{
    movementPlat = plat;
}

SurfaceDecorator::update(){
    movementPlat.update();
}
