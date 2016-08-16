#include "deleteevent.h"

DeleteEvent::DeleteEvent(GameObject* obj)
{
    this->toDelete = obj;
}

GameObject * DeleteEvent::getObject(){
    return toDelete;
}
