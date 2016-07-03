#include "level.h"
#include "GameObjects/gameobject.h"
#include "GameObjects/Actors/actor.h"
#include "GameObjects/Platforms/platform.h"
#include "GameObjects/Actors/player.h"
#include <vector>

Level::Level(Player * player)
{
    objects.push_back(player);
    Player * test = new Player(5, 0, 3, 3);
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
    this->ActorPlatformCollisions();

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
            if((center->y() + actors[i]->getRadius() > plats[b]->GameObject::getY() && center->y()+ actors[i]->getRadius() < plats[b]->GameObject::getY() + plats[b]->getHeight()) && (center->x()>= plats[b]->getX() && center->x()<= plats[b]->getX() + plats[b]->getWidth())){
                Platform* plat = plats[b];
                if(actors[i]->getPreviousLocation()[1] - actors[i]->getRadius()> plat->getY() + plat->getHeight()){
                    actors[i]->setY(plat->GameObject::getY() + plat->GameObject::getHeight() + actors[i]->getRadius());
                }
                if(actors[i]->getPreviousLocation()[1] + actors[i]->getRadius() < plat->getY()){
                    actors[i]->setY(plat->GameObject::getY() - actors[i]->getRadius());
                }
                if(actors[i]->getPreviousLocation()[0] + actors[i]->getRadius() < plat->getX()){
                    actors[i]->setX(plat->GameObject::getX() - actors[i]->getRadius());
                }
                if(actors[i]->getPreviousLocation()[0] - actors[i]->getRadius() > plat->getX()){
                    actors[i]->setX(plat->GameObject::getX() + actors[i]->getRadius());
                }
            }
        }
        }
    }

