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

bool Board::removeFullRows()
{
    for (int y = 0; y < BOARD_Y; y++){
        if (_isRowFull(y)){
            _removeRow(y);
            _dropBlocks();
        }
    }
}

bool Board::_isRowFull(int y)
{
    for (int x = 0; x < BOARD_X; x++){
        if (!isBlockAt(x, y)){
            return false;
        }
    }
    return true;
}

void Board::_removeRow(int y)
{
    _board.erase(std::remove_if(
        _board.begin(), _board.end(),
        [y](Block block) {
            return block.getY() == y;
        }), _board.end());
}

void Board::_dropBlocks()
{
    bool dropped = false;
    for (auto block = _board.begin(); block != _board.end(); ++block){
        if (!isBlockAt(block->getX(), block->getY()+1) && block->getY() + 1 < BOARD_Y){
            block->incY();
            dropped = true;
        }
    }
    if (dropped){
        return _dropBlocks();
    }
}
