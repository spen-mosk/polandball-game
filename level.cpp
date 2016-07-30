#include "level.h"
#include "GameObjects/gameobject.h"
#include "GameObjects/Actors/actor.h"
#include "GameObjects/Platforms/platform.h"
#include "GameObjects/Actors/player.h"
#include <vector>
#include <math.h>

Level::Level(Player * player)
{
    this->player = player;
    tree= KDTree<GameObject*> ();
    tree.insert(player);
    this->gravity = -1;
}

Level::Level(Player * player, std::vector<GameObject *> levelObs, int grav){
    gravity = grav;
    //allObjs = KDTree();
    for(int i = 0; i < levelObs.size(); i++){
        tree.insert(levelObs[i]);
    }
    tree.insert(player);
    this->player = player;
}

Level::~Level(){
}

KDTree<GameObject*> * Level::getObjects(){
    return &tree;
}

void Level::update(){
    /*DO:
     * Update all actors
     * Apply gravity
     */
    int size = tree.size();
    for(int i = 0; i < size; i++){
        GameObject * obj = tree.get(i);
        obj->update();
    }
    this->checkCollisions();
    //this->ActorPlatformCollisions();
}

void Level::handlePress(int key){
    player->addKey(key);
    if(key == Qt::Key_Z){
        TempGameObject * attack = player->primaryAttack();
        attack->registerObserver(this);
        tree.insert(attack);
    }
    if(key == Qt::Key_X){
        TempGameObject *attack = player->secondaryAttack();
        attack->registerObserver(this);
        tree.insert(attack);
    }
}

void Level::onDelete(DeleteSubject * willDelete){
    TempGameObject* toDelete = (TempGameObject*)willDelete;
    tree.remove(toDelete);
}

void Level::handleRelease(int key){
    player->removeKey(key);
}


void Level::checkCollisions(){
    std::vector<GameObject*> objs = std::vector<GameObject*>();
    int size = tree.size();
    for(int i = 0; i < size; i++){
        GameObject * obj = tree.get(0);
        int radius = obj->getCollRadius();
        tree.remove(obj);
        objs.push_back(obj);
        std::vector<GameObject *> list = tree.rangeSearch(obj, radius);
        for(int a = 0; a < list.size(); a++){
            list[a]->handleCollision(obj);
            obj->handleCollision(list[a]);
        }
    }
    for(int b = 0; b < objs.size(); b++){
        tree.insert(objs[b]);
    }
}

void Level::actorCollisions(Actor * actor, GameObject * plat){
    QPoint * p = actor->getCenter();
    int actorLeft = p->x() - actor->getRadius();
    int actorRight = p->x() + actor->getRadius();
    int actorTop = p->y() + actor->getRadius();
    int actorBottom = p->y() - actor->getRadius();
    int platLeft = plat->x();
    int platRight = plat->x() + plat->getWidth();
    int platTop = plat->y();
    int platBottom = plat->y() - plat->getHeight();
    if(actorLeft > platLeft && actorLeft < platRight
            && p->y() < platTop && p->y() > platBottom){
        int offsetX = plat->x() + plat->getWidth() - actorLeft;
        actor->updateLocation(offsetX,0);
    }
    else if(actorRight < platRight && actorRight > platLeft
            && p->y() < platTop && p->y() > platBottom){
        int offsetX = actorRight - platLeft;
        actor->updateLocation(-offsetX,0);
   //     printf("Collision from the left %d\n", numCollisions++);
    }
    else if(actorTop < platTop && actorTop > platBottom
            && p->x() < platRight && p->x() > platLeft){
        int offsetY = actorTop - platBottom;
        actor->updateLocation(0, -offsetY);
//        printf("Collision from the bottom %d\n", numCollisions++);
    }
    else if(actorBottom < platTop && actorBottom > platBottom
            && p->x() < platRight && p->x() > platLeft){
        int offsetY = platTop - actorBottom;
        actor->updateLocation(0, offsetY);
 //       printf("Collision from the top %d\n", numCollisions++);
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
            int platLeft = plat->x();
            int platRight = plat->x() + plat->getWidth();
            int platTop = plat->y();
            int platBottom = plat->y() - plat->getHeight();
//            printf("actorTop: %d, actorBottom: %d, actorLeft: %d, actorRight %d\n", actorTop, actorBottom, actorLeft, actorRight);
            if(actorLeft > platLeft && actorLeft < platRight
                    && p->y() < platTop && p->y() > platBottom){
                printf("Collision from the right\n");
                int offsetX = plat->x() + plat->getWidth() - actorLeft;
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
/*
void Level::applyGravity(){
    for(int i = 0; i < tree.size(); i++){
 //       printf("APPLYING GRAV\n");
        QPoint * p = actors[i]->getCenter();
        int actorBottom = p->y() - actors[i]->getRadius();
        bool applyGrav = true;
        for (int b = 0; b < plats.size(); b++){
            if(actorBottom == plats[b]->y()&& (actors[i]->x() >= plats[b]->x() && actors[i]->x() <= plats[b]->x() + plats[b]->getWidth())){
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
*/
