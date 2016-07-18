#ifndef ACTORSTATISTICS_H
#define ACTORSTATISTICS_H


class ActorStatistics
{
public:
    ActorStatistics(int, int, int, bool);
    int getRadius();
    int getSpeed();
    int getMaxHealth();
    bool isAlly();
    void setHealth(int);
private:
    int radius;
    int speed;
    int maxhealth;
    bool ally;
};

#endif // ACTORSTATISTICS_H
