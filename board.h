#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "block.h"
#include "consts.h"
#include <algorithm>

class Board
{
public:
    Board();
    void render();
    bool isBlockAt(const int x, const int y) const;
    void pushBlock(Block block);
    bool removeFullRows();

private:
    std::vector<Block>_board;
    bool _isRowFull(int y);
    void _removeRow(int y);
    void _dropBlocks();
};

#endif // BOARD_H
