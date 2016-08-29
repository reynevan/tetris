#ifndef BLOCK_H
#define BLOCK_H

#include "lutil.h"

class Block
{
public:
    Block();
    Block(int, int, bool active = false);
    int getX();
    int getY();
    void setX(int);
    void setY(int);
    void render();
    bool isActive();
    void setActive(bool);
    const static int size = 20;

private:
    int _x;
    int _y;
    bool _active;
};

#endif // BLOCK_H
