#ifndef DELETEOBSERVER_H
#define DELETEOBSERVER_H

class DeleteSubject;

class DeleteObserver
{
public:
    virtual void onDelete(DeleteSubject*) = 0;
};

#endif // DELETEOBSERVER_H
