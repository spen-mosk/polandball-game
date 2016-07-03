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
        }else{
        if(Platform* v = dynamic_cast<Platform*>(objects[i])) {
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
        }else{
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
    this->applyGravity();

}

void Level::applyGravity(){
    for(int i = 0; i < actors.size(); i++){
        bool applyGrav = true;
        for (int b = 0; b < plats.size(); i++){
            if(actors[i]->getY() == plats[i]->getY() + actors[i]->getRadius() && (actors[i]->getX() >= plats[i]->getX() && actors[i]->getX() <= plats[i]->getX() + plats[i]->getWidth())){
                applyGrav = false;
            }
        }
        if (applyGrav){
            actors[i]->Actor::updateLocation(0,gravity);
        }
    }
}
