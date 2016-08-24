#include "levelwriter.h"
#include <sstream>
#include <string>
#include <fstream>
#include "GameObjects/Platforms/platform.h"
#include "GameObjects/Platforms/movingplatform.h"
#include "GameObjects/Actors/enemy.h"

void writeLevel(std::vector<GameObject *> objs, const char* filename){
    std::ofstream stream(filename);
    for(int i = 0; i < objs.size(); i++){
        objs[i]->write(&stream);
    }
}

std::vector<GameObject*> readLevel(const char *filename){
    std::ifstream file(filename);
    std::string line;
    std::vector<GameObject*> objects;
    while(std::getline(file, line)){
        std::vector<string> splits = split(line);
        //If we decide to have types other than this
        //we will need to change this
        if(splits[0] == "platform"){
            int params[4];
            for(int a = 1; a < 5; a++){
                istringstream convert(splits[a]);
                convert >> params[a-1];
            }
            objects.push_back(new Platform(params[0], params[1], params[2], params[3]));
        }
        else if(splits[0] == "enemy"){
            int params[17];
            for(int b = 1; b < 18; b++){
                istringstream convert(splits[b]);
                convert >> params[b-1];
            }
            objects.push_back(new Enemy(params[0], params[1], new EnemyStatistics(params[2], params[3], params[4],
                                        params[5] == 1, params[6], new AttackStatistics(params[7], params[8], params[9],
                                        params[10] == 1, params[11], params[12], params[13] == 1, params[14]), params[15],
                                        params[16])));
        }
        else if(splits[0] == "movingplatform"){
            int params[6];
            for(int a = 1; a < 7; a++){
                istringstream convert(splits[a]);
                convert >> params[a-1];
            }
            istringstream toConvert(splits[5]);
            int numPoints;
            toConvert >> numPoints;
            int start = 6;
            std::vector<int*> points = std::vector<int*>();
            for(int b = 0; b < numPoints; b++){
                int point[2];
                istringstream xStream(splits[start++]);
                istringstream yStream(splits[start++]);
                xStream >> point[0];
                yStream >> point[1];
                points.push_back(point);
            }
            objects.push_back(new MovingPlatform(params[0], params[1], params[2], params[3], params[4],
                                                 params[5], points));
        }
    }
    return objects;
}

//Splits based on tab characters
std::vector<std::string> split(std::string toSplit){
    stringstream ss(toSplit);
    string item;
    std::vector<string> elems;
    //Hope that the tab character is consistent across
    //operating systems
    while(std::getline(ss, item, '\t')){
        elems.push_back(item);
    }
    return elems;
}
