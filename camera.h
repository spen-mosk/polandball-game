#ifndef CAMERA_H
#define CAMERA_H


class Camera
{
public:
    Camera();
    snapshot(Actor * actor, Level * level);

private:
    int metersPerScreen;
    double pixPerMeter;
    int screenSize;

};

#endif // CAMERA_H
