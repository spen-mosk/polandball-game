#ifndef DELETESUBJECT_H
#define DELETESUBJECT_H
#include <vector>
#include <algorithm>
#include "deleteobserver.h"


class DeleteSubject
{
public:
    DeleteSubject();
    void registerObserver(DeleteObserver *);
    void removeObserver(DeleteObserver*);
    void updateObservers();
private:
    std::vector<DeleteObserver*> observers;
};

#endif // DELETESUBJECT_H
