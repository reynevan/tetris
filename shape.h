#ifndef SHAPE_H
#define SHAPE_H

#include <vector>
#include "block.h"
#include "color.h"

class Shape
{
public:
    Shape();
    Shape(char type);
    const static char SHAPE_I = 1;
    const static char SHAPE_T = 2;
    const static char SHAPE_O = 3;
    const static char SHAPE_L = 4;
    const static char SHAPE_J = 5;
    const static char SHAPE_S = 6;
    const static char SHAPE_Z = 7;
    const static char SHAPES_COUNT = 7;

    std::vector<Block> getBlocks();

private:
    std::vector<Block> _blocks;
};

#endif // SHAPE_H
