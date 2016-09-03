#ifndef BLOCK_H
#define BLOCK_H

#include "lutil.h"
#include "color.h"

class Block
{
public:
    Block();
    Block(int, int, const Color, bool active = false);
    int getX() const;
    int getY() const;
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
    Color _color;
};

#endif // BLOCK_H
