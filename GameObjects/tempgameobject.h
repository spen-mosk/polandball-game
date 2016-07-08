#ifndef TEMPGAMEOBJECT_H
#define TEMPGAMEOBJECT_H
#include <GameObjects/gameobject.h>

class TempGameObject : public GameObject{
public:
    TempGameObject(int, int, int, int, int);
    int getDuration();


private:
    int duration;

};

#endif // TEMPGAMEOBJECT_H
