#ifndef ATTACKSTATISTICS_H
#define ATTACKSTATISTICS_H


class AttackStatistics
{
public:
    AttackStatistics(int, int, int, bool);
    int getHeight();
    int getWidth();
    int getDuration();
    bool isAlly();
private:
    int height;
    int width;
    int maxDuration;
    bool ally;
};

#endif // ATTACKSTATISTICS_H
