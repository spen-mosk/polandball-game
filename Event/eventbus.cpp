#include "eventbus.h"
#include <QMetaObject>
#include <QMetaMethod>
#include <string>
#include <cstring>

void EventBus::registerObject(QObject * obj){
    const QMetaObject *meta = obj->metaObject();
    for(int i = 0; i < meta->methodCount(); i++){
        QMetaMethod method = meta->method(i);
        if(strcmp(method.tag(), "EVENT_BUS") != 0){
            continue;
        }
        if(method.methodType() == QMetaMethod::Slot){
            std::vector<QObject*> objs;
            if(qobjects.find(method.parameterTypes()) != qobjects.end()){
                objs = qobjects.at(method.parameterTypes());
            }
            else{
                objs = std::vector<QObject*>();
            }
            for(int a = 0; a < objs.size(); a++){
                std::vector<QMetaMethod> theSignals = getSignals(objs[a], method.parameterTypes());
                for(int b = 0; b < theSignals.size(); b++){
                    std::string signal = std::string("2") + theSignals[b].methodSignature().constData();
                    std::string slot = std::string("1") + method.methodSignature().constData();
                    this->connect(objs[a], signal.c_str(), obj, slot.c_str());
                }
            }
            objs.push_back(obj);
            qobjects[method.parameterTypes()] = objs;
        }
        if(method.methodType() == QMetaMethod::Signal){
            std::vector<QObject*> objs;
            if(qobjects.find(method.parameterTypes()) != qobjects.end()){
                objs = qobjects.at(method.parameterTypes());
            }
            else{
                objs = std::vector<QObject*>();
            }
            for(int a = 0; a < objs.size(); a++){
                std::vector<QMetaMethod> theSlots = getSlots(objs[a], method.parameterTypes());
                for(int b = 0; b < theSlots.size(); b++){
                    std::string slot = std::string("1") + theSlots[b].methodSignature().constData();
                    std::string signal = std::string("2") + method.methodSignature().constData();
                    this->connect(obj, signal.c_str(), objs[a], slot.c_str());
                }
            }
            objs.push_back(obj);
            qobjects[method.parameterTypes()] = objs;
        }
    }
}

std::vector<QMetaMethod> EventBus::getSlots(QObject * obj, QList<QByteArray> params){
    const QMetaObject *meta = obj->metaObject();
    std::vector<QMetaMethod> theSlots = std::vector<QMetaMethod>();
    for(int i = 0; i < meta->methodCount(); i++){
        if(meta->method(i).parameterTypes() == params && meta->method(i).methodType() == QMetaMethod::Slot
                && strcmp(meta->method(i).tag(), "EVENT_BUS") == 0){
            theSlots.push_back(meta->method(i));
        }
    }
    return theSlots;
}

std::vector<QMetaMethod> EventBus::getSignals(QObject * obj, QList<QByteArray> params){
    const QMetaObject *meta = obj->metaObject();
    std::vector<QMetaMethod> theSlots = std::vector<QMetaMethod>();
    for(int i = 0; i < meta->methodCount(); i++){
        if(meta->method(i).parameterTypes() == params && meta->method(i).methodType() == QMetaMethod::Signal
                && strcmp(meta->method(i).tag(), "EVENT_BUS") == 0){
            theSlots.push_back(meta->method(i));
        }
    }
    return theSlots;
}
