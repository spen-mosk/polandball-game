#ifndef ACTORSTATISTICS_H
#define ACTORSTATISTICS_H


class ActorStatistics
{
public:
    ActorStatistics(int, int, int, int, int, int, bool);
    int getX();
    int getY();
    int getRadius();
    int getSpeed();
    int getHealth();
    bool isAlly();
private:
    int x;
    int y;
    int radius;
    int speed;
    int health;
    bool ally;
};

#endif // ACTORSTATISTICS_H
