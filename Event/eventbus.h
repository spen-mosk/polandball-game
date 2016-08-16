#ifndef EVENTBUS_H
#define EVENTBUS_H

#include <QObject>
#include <QMetaMethod>
#include <vector>
#include <map>
#include <QList>
#include <QByteArray>



//Singleton class, follows same template as AstarGraph
//To register both a classes slots and signals, include eventbus
//and then use the REGISTER macro in the constructor
class EventBus : public QObject
{
    Q_OBJECT

public:
    static EventBus& getInstance(){
        static EventBus instance;
        return instance;
    }

    void registerObject(QObject *);

public slots:

signals:

private:
    EventBus(){};
    EventBus(EventBus const&) = delete;
    void operator=(EventBus const&)  = delete;
    std::vector<QMetaMethod> getSlots(QObject*, QList<QByteArray>);
    std::vector<QMetaMethod> getSignals(QObject*, QList<QByteArray>);
    std::map<QList<QByteArray>, std::vector<QObject*>> qobjects;

};

#define REGISTER EventBus::getInstance().registerObject(this);

#endif // EVENTBUS_H
