#include "level.h"
#include "player.h"

Level::Level(Player * player)
{
    objects.push_back(player);
    Player * test = new Player(5, 0, 20, 20);
    objects.push_back(test);
}

std::vector<GameObject *> Level::getObjects(){
    return objects;
}

void Level::update(){
    /*DO:
     * Update all actors
     */
    for(int i = 0; i < objects.size(); i++){
        objects[i]->update();
    }

}
