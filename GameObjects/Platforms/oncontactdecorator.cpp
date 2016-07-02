#include "oncontactdecorator.h"

OnContactDecorator::OnContactDecorator(SurfaceDecorator * dec, int x, int y, int w, int h):Platform(x, y, w,h)
{
    decorator = dec;
}

void OnContactDecorator::onContact(Actor * actor){

}

void OnContactDecorator::surfaceEffect(Actor * actor){
    decorator->surfaceEffect(actor);
}






