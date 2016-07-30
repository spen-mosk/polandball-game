#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <QPoint>
#include <QObject>
#include <QPainter>

class GameObject : public QObject
{

public:
    GameObject(int, int, int, int, int);
    virtual ~GameObject(){};
    virtual void draw(QPainter *) = 0;
    virtual void update() = 0;
    virtual void handleCollision(GameObject*) = 0;
    int x();
    int y();
    int getHeight();
    int getWidth();
    void setX(int);
    void setY(int);
    int drawingX;
    int drawingY;
    int getCollRadius();
    void setGrav(bool grav);
    bool getGrav();
    int drawingWidth;
    int drawingHeight;
    QPoint * getDrawingPosition();
    QPoint * getPosition();

private:
    int xPos;
    int yPos;
    int height;
    int width;
    int collRad;
    bool grav;
};

#endif // GAMEOBJECT_H
