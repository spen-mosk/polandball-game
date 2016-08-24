#ifndef LEVELWRITER_H
#define LEVELWRITER_H
#include <vector>
#include "GameObjects/gameobject.h"

void writeLevel(std::vector<GameObject*>, const char * filename);

std::vector<GameObject*> readLevel(const char * filename);

std::vector<std::string> split(std::string);

#endif // LEVELWRITER_H
