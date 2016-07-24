#ifndef ATTACKSTATISTICS_H
#define ATTACKSTATISTICS_H


class AttackStatistics
{
public:
    AttackStatistics(int, int, int, bool, int, int speed, bool isMelee);
    int getHeight();
    int getWidth();
    int getDuration();
    int getDamage();
    bool isAlly();
    bool isMelee();
    int getSpeed();
private:
    int height;
    int damage;
    int width;
    int maxDuration;
    bool ally;
    bool melee;
    int speed;
};

#endif // ATTACKSTATISTICS_H
