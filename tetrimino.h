#ifndef TETRIMINO_H
#define TETRIMINO_H

#include "consts.h"
#include "block.h"
#include "board.h"
#include <vector>

class Tetrimino
{
public:
    Tetrimino();
    void move(Board*);
    void horizontalMove(int key, Board* board);

private:
    std::vector<Block> _blocks;
    bool _checkMoveDown(Board *board);
    bool _checkHorizontalMove(Board *board, int direction);
    void _moveDown(Board *);
    void _clearBoard(Board*);
    void _fillBoard(Board*);
};

#endif // TETRIMINO_H
