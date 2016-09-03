#include "board.h"
#include <iostream>

Board::Board()
{
}

void Board::render()
{
    for (std::vector<Block>::iterator block = _board.begin(); block != _board.end(); ++block){
        block->render();
    }
}

void Board::pushBlock(Block block)
{
    _board.push_back(block);
}

bool Board::isBlockAt(const int x, const int y) const
{
    for (auto block = _board.cbegin(); block != _board.cend(); ++block){
        if (block->getX() == x && block->getY() == y){
            return true;
        }
    }
    return false;
}
