#include "tetrimino.h"


Tetrimino::Tetrimino()
{
    srand(time(NULL));
    Shape shape = Shape(rand() % Shape::SHAPES_COUNT + 1);
    std::vector<Block> blocks = shape.getBlocks();
    for (auto block = blocks.begin(); block != blocks.end(); ++block){
        block->setX(block->getX() + BOARD_X / 2);
        _blocks.push_back(*block);
    }
}

void Tetrimino::render()
{
    for (auto block = _blocks.begin(); block != _blocks.end(); ++block){
        block->render();
    }
}

void Tetrimino::moveToBoard(Board *board)
{
    for (auto block = _blocks.begin(); block != _blocks.end(); ++block){
        board->pushBlock(*block);
    }
}


bool Tetrimino::moveDown(Board* board)
{
    if (!_checkMoveDown(board)){
        return false;
    }
    for (auto block = _blocks.begin(); block != _blocks.end(); ++block){
        block->setY(block->getY() + 1);
    }
    return true;
}

bool Tetrimino::_checkMoveDown(Board* board)
{
    for (auto block = _blocks.begin(); block != _blocks.end(); ++block){
       if (block->getY() >= BOARD_Y - 1){
           return false;
       }
       if (board->isBlockAt(block->getX(), block->getY() + 1)){
           return false;
       }
    }
    return true;
}

void Tetrimino::horizontalMove(int key, Board *board)
{
    int direction = 0;
    if (key == GLUT_KEY_LEFT){
        direction = -1;
    } else if (key == GLUT_KEY_RIGHT){
        direction = 1;
    }
    if (!_checkHorizontalMove(direction, board)){
        return;
    }

    for (auto block = _blocks.begin(); block != _blocks.end(); ++block){
        block->setX(block->getX() + direction);
    }
}

bool Tetrimino::_checkHorizontalMove(int direction, Board *board)
{
    for (auto block = _blocks.begin(); block != _blocks.end(); ++block){
       if ((block->getX() == 0 && direction == -1) || (block->getX() == BOARD_X - 1 && direction == 1)){
           return false;
       }
       bool blockOnLeft = board->isBlockAt(block->getX() - 1, block->getY());
       if (blockOnLeft && direction == -1){
           return false;
       }
       bool blockOnRight = board->isBlockAt(block->getX() + 1, block->getY());
       if (blockOnRight && direction == 1){
           return false;
       }
    }
    return true;
}
