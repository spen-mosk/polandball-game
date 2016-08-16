#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <QPoint>
#include <QObject>
#include <QPainter>
#include <string>

class GameObject : public QObject
{
    Q_OBJECT

public:
    GameObject(int, int, int, int, int, std::string);
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
    bool equals(GameObject*);
    int drawingX;
    int drawingY;
    int getCollRadius();
    void setGrav(bool grav);
    bool operator <(const GameObject* rhs) const{
        return collRad < rhs->collRad;
    }
    bool getGrav();
    int drawingWidth;
    int drawingHeight;
    QPoint * getDrawingPosition();
    QPoint * getPosition();

private:
    std::string name;
    int xPos;
    int yPos;
    int height;
    int width;
    int collRad;
    bool grav;
};

#endif // GAMEOBJECT_H
