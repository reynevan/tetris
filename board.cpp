#include "board.h"
#include <iostream>

Board::Board()
{
    int x = BOARD_X, y = BOARD_Y;

    for (int i = 0; i < x * y; i++){
        _board.push_back(Block(i % x, i / x));
    }
}

void Board::render()
{
    for (std::vector<Block>::iterator block = _board.begin(); block != _board.end(); ++block){
        if (block->isActive()){
            block->render();
        }
    }
}

Block& Board::at(int x, int y)
{
    return _board[BOARD_X * y + x];
}
