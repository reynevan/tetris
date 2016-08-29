#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "block.h"
#include "consts.h"

class Board
{
public:
    Board();
    void render();
    Block& at(int, int);

private:
    std::vector<Block>_board;
};

#endif // BOARD_H
