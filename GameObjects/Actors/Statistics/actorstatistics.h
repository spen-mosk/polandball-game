#ifndef ACTORSTATISTICS_H
#define ACTORSTATISTICS_H


class ActorStatistics
{
public:
    ActorStatistics(int, int, int, bool, int);
    int getRadius();
    int getSpeed();
    int getMaxHealth();
    bool isAlly();
    void setHealth(int);
    int getGravity();
private:
    int radius;
    int speed;
    int maxhealth;
    bool ally;
    int grav;
};

#endif // ACTORSTATISTICS_H
