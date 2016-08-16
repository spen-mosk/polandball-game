#ifndef KEYPRESSEVENT_H
#define KEYPRESSEVENT_H


class KeyEvent
{
public:
    KeyEvent(int, bool);
    int getKey();
    bool getType();

private:
    int key;
    bool press;
};

#endif // KEYPRESSEVENT_H
