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
    bool isBlockAt(const int x, const int y) const;
    void pushBlock(Block block);

private:
    std::vector<Block>_board;
};

#endif // BOARD_H
