#include "tetrimino.h"

Tetrimino::Tetrimino()
{
    _blocks.push_back(Block(0,0));
    _blocks.push_back(Block(1,0));
    _blocks.push_back(Block(2,0));
    _blocks.push_back(Block(3,0));
}

void Tetrimino::move(Board *board)
{
    _clearBoard(board);
    _moveDown(board);
    _fillBoard(board);
}

void Tetrimino::horizontalMove(int key, Board *board)
{
    int direction = 0;
    if (key == GLUT_KEY_LEFT){
        direction = -1;
    } else if (key == GLUT_KEY_RIGHT){
        direction = 1;
    }
    if (!_checkHorizontalMove(board, direction)){
        return;
    }
    _clearBoard(board);
    for (auto block = _blocks.begin(); block != _blocks.end(); ++block){
        block->setX(block->getX() + direction);
    }
    _fillBoard(board);
}

bool Tetrimino::_checkHorizontalMove(Board *board, int direction)
{
    bool valid = true;
    for (auto block = _blocks.begin(); block != _blocks.end(); ++block){
       if ((block->getX() == 0 && direction == -1) || (block->getX() == BOARD_X - 1 && direction == 1)){
           return false;
       }
    }
    return true;
}

bool Tetrimino::_checkMoveDown(Board *board)
{
    bool valid = true;
    for (auto block = _blocks.begin(); block != _blocks.end(); ++block){
       if (block->getY() >= BOARD_Y - 1){
           return false;
       }
    }
    return true;
}

void Tetrimino::_moveDown(Board *board)
{
    if (!_checkMoveDown(board)){
        return;
    }
    for (auto block = _blocks.begin(); block != _blocks.end(); ++block){
        block->setY(block->getY() + 1);
    }
}

void Tetrimino::_clearBoard(Board *board)
{
    for (auto block = _blocks.begin(); block != _blocks.end(); ++block){
        board->at(block->getX(), block->getY()).setActive(false);
    }
}

void Tetrimino::_fillBoard(Board *board)
{
    for (auto block = _blocks.begin(); block != _blocks.end(); ++block){
        board->at(block->getX(), block->getY()).setActive(true);
    }
}
