#include "level.h"
#include "GameObjects/gameobject.h"
#include "GameObjects/Actors/actor.h"
#include "GameObjects/Platforms/platform.h"
#include "GameObjects/Actors/player.h"
#include <vector>

Level::Level(Player * player)
{
    objects.push_back(player);
    Player * test = new Player(20, 0, 3, 3);
    objects.push_back(test);
    this->gravity = -5;
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

Level::Level(Player * player, std::vector<GameObject *> levelObs){
    this->objects = levelObs;
    objects.push_back(player);
    this->gravity = -5;
    for(int i = 0; i < objects.size(); i++){
        if(Actor* v = dynamic_cast<Actor*>(objects[i])) {
           actors.push_back(v);
        }
        else{
            if(Platform* v = dynamic_cast<Platform*>(objects[i])) {
               plats.push_back(v);
            }
        }
    }
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
        objects[i]->update();
    }
    //this->applyGravity();
    //this->ActorPlatformCollisions();
    this->checkCollisions();
}

void Level::checkCollisions(){
    for(int i = 0; i < actors.size(); i++){
        for (int b = 0; b < plats.size(); b++){
            Actor * actor = actors[i];
            Platform * plat = plats[b];
            QPoint * p = actor->getCenter();
            int actorLeft = p->x() - actor->getRadius();
            int actorRight = p->x() + actor->getRadius();
            int actorTop = p->y() + actor->getRadius();
            int actorBottom = p->y() - actor->getRadius();
            int platLeft = plat->getX();
            int platRight = plat->getX() + plat->getWidth();
            int platTop = plat->getY();
            int platBottom = plat->getY() - plat->getHeight();
            if(actorLeft >= platLeft && actorLeft <= platRight
                    && p->y() <= platTop && p->y() >= platBottom){
                printf("Collision from the right\n");
                int offsetX = plat->getX() + plat->getWidth() - actorLeft;
                actor->updateLocation(offsetX,0);
            }
            else if(actorRight >= platRight && actorRight <= platRight
                    && p->y() <= platTop && p->y() >= platBottom){
                int offsetX = actorRight - plat->getX() + plat->getWidth();
                actor->updateLocation(-offsetX,0);
                printf("Collision from the left\n");
            }
            else if(actorTop <= platTop && actorTop >= platBottom
                    && p->x() <= platRight && p->x() >= platLeft){
                int offsetY = actorTop - plat->getY() - plat->getHeight();
                actor->updateLocation(0, -offsetY);
                printf("Collision from the bottom\n");
            }
            else if(actorBottom <= platTop && actorBottom >= platBottom
                    && p->x() <= platRight && p->x() >= platLeft){
                int offsetY = plat->getY() - actorBottom;
                actor->updateLocation(0, offsetY);
                printf("Collision from the top\n");
            }
        }
    }

}

void Level::applyGravity(){
    for(int i = 0; i < actors.size(); i++){
        bool applyGrav = true;
        for (int b = 0; b < plats.size(); b++){
            if(actors[i]->getY() + actors[i]->getRadius() == plats[b]->getY()&& (actors[i]->getX() >= plats[b]->getX() && actors[i]->getX() <= plats[b]->getX() + plats[b]->getWidth())){
                applyGrav = false;
                break;
            }
        }
        if (applyGrav){
            actors[i]->Actor::updateLocation(0,gravity);
        }
    }
}

void Level::ActorPlatformCollisions(){
      for(int i = 0; i < actors.size(); i++){
        for (int b = 0; b < plats.size(); b++){
            QPoint * center = actors[i]->getCenter();
            if(((center->y() - actors[i]->getRadius() < plats[b]->GameObject::getY() && center->y()- actors[i]->getRadius() > plats[b]->GameObject::getY() - plats[b]->getHeight())
                            || (center->y() + actors[i]->getRadius() < plats[b]->GameObject::getY() && center->y()+ actors[i]->getRadius() > plats[b]->GameObject::getY() - plats[b]->getHeight()))
                            && (center->x()>= plats[b]->getX() && center->x()<= plats[b]->getX() + plats[b]->getWidth())){
                printf("WE HAVE A COLLISION");
                Platform* plat = plats[b];
                if(actors[i]->getPreviousLocation()[1] + actors[i]->getRadius()< plat->getY() - plat->getHeight()){
                    int offsetY = plat->GameObject::getY() + plat->GameObject::getHeight() + actors[i]->getRadius() - center->y();
                    actors[i]->updateLocation(0, offsetY);
                }
                if(actors[i]->getPreviousLocation()[1] - actors[i]->getRadius() > plat->getY()){
                    int offsetY = plat->GameObject::getY() + actors[i]->getRadius() - center->y() ;
                    actors[i]->updateLocation(0, offsetY);
                }
                if(actors[i]->getPreviousLocation()[0] + actors[i]->getRadius() < plat->getX()){
                    int offsetX = plat->GameObject::getX() - actors[i]->getRadius() - center->x();
                    actors[i]->updateLocation(offsetX, 0);
                }
                if(actors[i]->getPreviousLocation()[0] - actors[i]->getRadius() > plat->getX()){
                    int offsetX = plat->GameObject::getX() + actors[i]->getRadius() - center->x();
                    actors[i]->updateLocation(offsetX, 0);
                }
            }
        }
        }
    }

