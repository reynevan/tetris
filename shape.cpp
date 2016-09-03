#include "shape.h"

const char Shape::SHAPE_I;
const char Shape::SHAPE_T;
const char Shape::SHAPE_O;
const char Shape::SHAPE_L;
const char Shape::SHAPE_J;
const char Shape::SHAPE_S;
const char Shape::SHAPE_Z;
const char Shape::SHAPES_COUNT;

Shape::Shape()
{

}

Shape::Shape(char type){
    //TODO: refactor
    Color color;
    switch (type){
        case Shape::SHAPE_I:
            color = Color(1.0f, 0.0f, 0.0f);
            _blocks.push_back(Block(0,-3, color));
            _blocks.push_back(Block(0,-2, color));
            _blocks.push_back(Block(0,-1, color));
            _blocks.push_back(Block(0, 0, color));
            break;
        case Shape::SHAPE_T:
            color = Color(0.7f, 0.7f, 0.7f);
            _blocks.push_back(Block(-1,-1, color));
            _blocks.push_back(Block(0,-1, color));
            _blocks.push_back(Block(1,-1, color));
            _blocks.push_back(Block(0, 0, color));
            break;
        case Shape::SHAPE_O:
            color = Color(0.0f, 1.0f, 1.0f);
            _blocks.push_back(Block(-1,-1, color));
            _blocks.push_back(Block(0, -1, color));
            _blocks.push_back(Block(-1, 0, color));
            _blocks.push_back(Block(0, 0, color));
            break;
        case Shape::SHAPE_L:
            color = Color(1.0f, 1.0f, 0.0f);
            _blocks.push_back(Block(0,-2, color));
            _blocks.push_back(Block(0, -1, color));
            _blocks.push_back(Block(0, 0, color));
            _blocks.push_back(Block(1, 0, color));
            break;
        case Shape::SHAPE_J:
            color = Color(1.0f, 0.0f, 1.0f);
            _blocks.push_back(Block(1,-2, color));
            _blocks.push_back(Block(1, -1, color));
            _blocks.push_back(Block(1, 0, color));
            _blocks.push_back(Block(0, 0, color));
            break;
        case Shape::SHAPE_S:
            color = Color(0.0f, 0.0f, 1.0f);
            _blocks.push_back(Block(-1, 0, color));
            _blocks.push_back(Block(0, -1, color));
            _blocks.push_back(Block(0, 0, color));
            _blocks.push_back(Block(1, -1, color));
            break;
        case Shape::SHAPE_Z:
            color = Color(0.0f, 1.0f, 0.0f);
            _blocks.push_back(Block(-1,-1, color));
            _blocks.push_back(Block(0, -1, color));
            _blocks.push_back(Block(0, 0, color));
            _blocks.push_back(Block(1, 0, color));
            break;

    }
}

std::vector<Block> Shape::getBlocks()
{
       return _blocks;
}
