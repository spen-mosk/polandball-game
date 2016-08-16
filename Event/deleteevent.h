#ifndef DELETEEVENT_H
#define DELETEEVENT_H
#include "GameObjects/gameobject.h"


class DeleteEvent
{
public:
    DeleteEvent(GameObject*);
    GameObject* getObject();

private:
    GameObject* toDelete;
};

#endif // DELETEEVENT_H
