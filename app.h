#ifndef APP_H
#define APP_H

#include "consts.h"
#include "lutil.h"
#include "tetrimino.h"
#include "board.h"
#include <iostream>

class App
{
public:
    App();
    void run(int value = 0);

private:
    Board _board;
    Tetrimino* _tetrimino;
    GLfloat color = 0.f;
    static App* _appInstance;
    static void  _renderCallback();
    static void _renderCallback(int val = 0);
    static void _handleKeysCallback(unsigned char key, int x, int y );
    static void _handleSpecialCallback(int key, int x, int y );
    static void _updateCallback(int);
    void _update(int);
    void _render(int);
    void _handleKeys(unsigned char key, int x, int y );
    void _handleSpecial(int key, int x, int y );
};

#endif // APP_H
