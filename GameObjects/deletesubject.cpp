#include "deletesubject.h"

DeleteSubject::DeleteSubject()
{
    this->observers = std::vector<DeleteObserver*>();
}

void DeleteSubject::registerObserver(DeleteObserver * obs){
    observers.push_back(obs);
}

void DeleteSubject::updateObservers(){
    for(int i = 0; i < observers.size(); i++){
        observers[i]->onDelete(this);
    }
}

void DeleteSubject::removeObserver(DeleteObserver * obs){
    this->observers.erase(std::remove(observers.begin(), observers.end(), obs));
}
