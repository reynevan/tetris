#include "block.h"

const int Block::size;

Block::Block()
{
    _x = -1;
    _y = -1;
    _active = false;
}

Block::Block(int x, int y, const Color color, bool active) : _x(x), _y(y), _color(color), _active(active)
{
}

int Block::getX() const
{
    return _x;
}

int Block::getY() const
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
    glColor3f(_color.red, _color.green, _color.blue);
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
