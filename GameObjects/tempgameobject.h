#ifndef TEMPGAMEOBJECT_H
#define TEMPGAMEOBJECT_H
#include <vector>
#include "GameObjects/gameobject.h"
#include "deletesubject.h"
class TempGameObject : public GameObject, public DeleteSubject{

public:
    TempGameObject(int, int, int, int, int);
    int getDuration();
    int getExistence();
    virtual void update();
    void handleCollision(GameObject*);

private:
    static int num;
    int duration;
    int existence = 0;
};

#endif // TEMPGAMEOBJECT_H
