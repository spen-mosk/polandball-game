#include "level.h"
#include "GameObjects/gameobject.h"
#include "GameObjects/Actors/actor.h"
#include "GameObjects/Platforms/platform.h"
#include "GameObjects/Actors/player.h"
#include <vector>
#include <math.h>

Level::Level(Player * player)
{
    objects.push_back(player);
    this->player = player;
    this->gravity = -1;
    for(int i = 0; i < objects.size(); i++){
        if(Actor* v = dynamic_cast<Actor*>(objects[i])) {
           actors.push_back(v);
        }
        else{
            if(Platform* v = dynamic_cast<Platform*>(objects[i])){
               plats.push_back(v);
            }
        }
    }
}

Level::Level(Player * player, std::vector<GameObject *> levelObs, int grav){
    this->objects = levelObs;
    gravity = grav;
    objects.push_back(player);
    this->player = player;
    actors.push_back(player);
    for(int i = 0; i < objects.size(); i++){
        if(Actor* v = dynamic_cast<Actor*>(objects[i])) {
           actors.push_back(v);
        }
        else{
            if(Platform* v = dynamic_cast<Platform*>(objects[i])) {
               plats.push_back(v);
               tree.insert(v);
            }
        }
    }
}

Level::~Level(){
}

std::vector<GameObject *> Level::getObjects(){
    return objects;
}

void Level::update(){
    /*DO:
     * Update all actors
     * Apply gravity
     */
    for(int i = 0; i < objects.size(); i++){
        printf("BUT DOES THIS HAPPEN\n");
        objects[i]->update();
    }
    this->applyGravity();
    //this->ActorPlatformCollisions();
    this->checkCollisions();
}

void Level::handlePress(int key){
    player->addKey(key);
}

void Level::handleRelease(int key){
    player->removeKey(key);
}

int distance(Actor * one, GameObject*two){
   QPoint * point = one->getCenter();
   int maxX2 = two->getX() + two->getWidth();
   int minY2 = two->getY() - two->getHeight();
   int minX2 = two->getX();
   int maxY2 = two->getY();
   int dx = (minX2 - point->x() > point->x() - maxX2) ? minX2 - point->x() : point->x() - maxX2;
   dx = (dx > 0) ? dx : 0;
   int dy = (minY2 - point->y() > point->y() - maxY2) ? minY2 - point->y() : point->y() - maxY2;
   dy = (dy > 0) ? dy : 0;
   return sqrt(dx*dx + dy*dy);
}

void Level::checkCollisions(){
    for(int i = 0; i < actors.size(); i++){
        std::vector<GameObject *> list = std::vector<GameObject*>();
        int num = 5;
        bool haveCollision = false;
        std::vector<GameObject*> near;
        do{
           near = (tree.kNN(actors[i], num));
           printf("SIZE %d\n", near.size());
           for(int a = near.size()-1; a >=0; a--){
              printf("NEAR[%d] x:%d y:%d\n", a, near[a]->getX(), near[a]->getY());
              if(distance(actors[i], near[a]) < actors[i]->getRadius()){
                  actorCollisions(actors[i], near[a]);
                  haveCollision = true;
              }
              else{
                  haveCollision = false;
              }
           }
           num *= 2;
        }while(haveCollision && near.size() == num);
    }
}

void Level::actorCollisions(Actor * actor, GameObject * plat){
    printf("WE HAVE A COLLISION\n");
    static int numCollisions = 0;
    QPoint * p = actor->getCenter();
    int actorLeft = p->x() - actor->getRadius();
    int actorRight = p->x() + actor->getRadius();
    int actorTop = p->y() + actor->getRadius();
    int actorBottom = p->y() - actor->getRadius();
    int platLeft = plat->getX();
    int platRight = plat->getX() + plat->getWidth();
    int platTop = plat->getY();
    int platBottom = plat->getY() - plat->getHeight();
    printf("%d, %d, %d, %d\n", actorRight, platRight, actorRight, platLeft);
    if(actorLeft > platLeft && actorLeft < platRight
            && p->y() < platTop && p->y() > platBottom){
        printf("Collision from the right: %d\n", numCollisions++);
        int offsetX = plat->getX() + plat->getWidth() - actorLeft;
        actor->updateLocation(offsetX,0);
    }
    else if(actorRight < platRight && actorRight > platLeft
            && p->y() < platTop && p->y() > platBottom){
        int offsetX = actorRight - platLeft;
        actor->updateLocation(-offsetX,0);
        printf("Collision from the left %d\n", numCollisions++);
    }
    else if(actorTop < platTop && actorTop > platBottom
            && p->x() < platRight && p->x() > platLeft){
        int offsetY = actorTop - platBottom;
        actor->updateLocation(0, -offsetY);
        printf("Collision from the bottom %d\n", numCollisions++);
    }
    else if(actorBottom < platTop && actorBottom > platBottom
            && p->x() < platRight && p->x() > platLeft){
        int offsetY = platTop - actorBottom;
        actor->updateLocation(0, offsetY);
        printf("Collision from the top %d\n", numCollisions++);
    }
}
    /*
    for(int i = 0; i < actors.size(); i++){
        for (int b = 0; b < plats.size(); b++){
            Actor * actor = actors[i];
            Platform * plat = plats[b];
            QPoint * p = actor->getCenter();
//            printf("actorRadius: %d, actorX: %d, actorY: %d\n",actor->getRadius(), p->x(), p->y());
            int actorLeft = p->x() - actor->getRadius();
            int actorRight = p->x() + actor->getRadius();
            int actorTop = p->y() + actor->getRadius();
            int actorBottom = p->y() - actor->getRadius();
            int platLeft = plat->getX();
            int platRight = plat->getX() + plat->getWidth();
            int platTop = plat->getY();
            int platBottom = plat->getY() - plat->getHeight();
//            printf("actorTop: %d, actorBottom: %d, actorLeft: %d, actorRight %d\n", actorTop, actorBottom, actorLeft, actorRight);
            if(actorLeft > platLeft && actorLeft < platRight
                    && p->y() < platTop && p->y() > platBottom){
                printf("Collision from the right\n");
                int offsetX = plat->getX() + plat->getWidth() - actorLeft;
                actor->updateLocation(offsetX,0);
            }
            else if(actorRight < platRight && actorRight > platLeft
                    && p->y() < platTop && p->y() > platBottom){
                int offsetX = actorRight - platLeft;
                actor->updateLocation(-offsetX,0);
                printf("Collision from the left\n");
            }
            else if(actorTop < platTop && actorTop > platBottom
                    && p->x() < platRight && p->x() > platLeft){
                int offsetY = actorTop - platBottom;
                actor->updateLocation(0, -offsetY);
                printf("Collision from the bottom\n");
            }
            else if(actorBottom < platTop && actorBottom > platBottom
                    && p->x() < platRight && p->x() > platLeft){
                int offsetY = platTop - actorBottom;
                actor->updateLocation(0, offsetY);
              //  printf("Collision from the top\n");
            }
        }
    }

}
*/
void Level::applyGravity(){
    for(int i = 0; i < actors.size(); i++){
        printf("APPLYING GRAV\n");
        QPoint * p = actors[i]->getCenter();
        int actorBottom = p->y() - actors[i]->getRadius();
        bool applyGrav = true;
        for (int b = 0; b < plats.size(); b++){
            if(actorBottom == plats[b]->getY()&& (actors[i]->getX() >= plats[b]->getX() && actors[i]->getX() <= plats[b]->getX() + plats[b]->getWidth())){
                applyGrav = false;
                actors[i]->resetJump();
                break;
            }
        }
        if (applyGrav){
            actors[i]->maximizeJump();
            actors[i]->Actor::updateLocation(0,gravity);
        }
    }
}
