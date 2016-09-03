#ifndef TETRIMINO_H
#define TETRIMINO_H

#include "consts.h"
#include "block.h"
#include "board.h"
#include "color.h"
#include "shape.h"
#include <vector>
#include <cstdlib>
#include <ctime>

class Tetrimino
{
public:
    Tetrimino();
    bool moveDown(Board*);
    void horizontalMove(int key, Board* board);
    void render();
    void moveToBoard(Board *board);

private:
    std::vector<Block> _blocks;
    bool _checkMoveDown(Board*);
    bool _checkHorizontalMove(int direction, Board* board);
    void _clearBoard(Board*);
    void _fillBoard(Board*);
};

#endif // TETRIMINO_H
