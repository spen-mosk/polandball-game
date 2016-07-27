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
    void initialCollision(GameObject*);
    void secondCollision(GameObject*);
    virtual void update() = 0;
    int getX();
    int getY();
    int getHeight();
    int getWidth();
    void setX(int);
    void setY(int);
    int drawingX;
    int getCollRadius();
    int drawingY;
    void setGrav(bool grav);
    bool getGrav();
    int drawingWidth;
    int drawingHeight;
    QPoint * getDrawingPosition();
    QPoint * getPosition();

protected:
    virtual void handleCollision(GameObject*, bool) = 0;

private:
    int xPos;
    int yPos;
    int height;
    int width;
    int collRad;
    bool grav;

};

#endif // GAMEOBJECT_H
