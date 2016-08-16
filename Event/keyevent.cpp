#include "keyevent.h"

KeyEvent::KeyEvent(int key, bool press)
{
    this->key = key;
    this->press = press;
}

int KeyEvent::getKey(){
    return this->key;
}

bool KeyEvent::getType(){
    return this->press;
}
