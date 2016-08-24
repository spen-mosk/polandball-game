#ifndef TEMPGAMEOBJECT_H
#define TEMPGAMEOBJECT_H
#include <vector>
#include "GameObjects/gameobject.h"
#include "Event/eventbus.h"
#include "Event/deleteevent.h"
class TempGameObject : public GameObject
{
    Q_OBJECT

public:
    TempGameObject(int, int, int, int, int);
    int getDuration();
    int getExistence();
    virtual void update();
    virtual void write(FILE *out){};
    void handleCollision(GameObject*);

signals:
    EVENT_BUS void deleteEvent(DeleteEvent);

private:
    static int num;
    int duration;
    int existence = 0;
};

#endif // TEMPGAMEOBJECT_H
