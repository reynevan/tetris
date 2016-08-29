#include "block.h"

const int Block::size;

Block::Block()
{
    _x = -1;
    _y = -1;
    _active = false;
}

Block::Block(int x, int y, bool active) : _x(x), _y(y), _active(active)
{
}

int Block::getX()
{
    return _x;
}

int Block::getY()
{
    return _y;
}

void Block::setX(int x)
{
    _x = x;
}

void Block::setY(int y)
{
    _y = y;
}

void Block::render()
{
    rect(_x*Block::size + 1, _y*Block::size + 1, Block::size - 2, Block::size - 2);
}

bool Block::isActive()
{
    return _active;
}

void Block::setActive(bool active)
{
    _active = active;
}
