#include "app.h"

App* App::_appInstance;

App::App()
{    
    _appInstance = this;
    _tetrimino = new Tetrimino();

    glutKeyboardFunc(App::_handleKeysCallback);
    glutSpecialFunc(App::_handleSpecialCallback);
    glutDisplayFunc(App::_renderCallback);

    glutTimerFunc( 1000 / FPS, App::_renderCallback, 0);
    glutTimerFunc(INTERVAL, App::_updateCallback, 0);

    glutMainLoop();
}

void App::_renderCallback()
{
    _appInstance->_render(0);
}

void App::_renderCallback(int val)
{
    _appInstance->_render(val);
}

void App::_updateCallback(int val)
{
    _appInstance->_update(val);
}

void App::_handleKeysCallback(unsigned char key, int x, int y)
{
    _appInstance->_handleKeys(key, x, y);
}

void App::_handleSpecialCallback(int key, int x, int y)
{
    _appInstance->_handleSpecial(key, x, y);
}

void App::_update(int val)
{
    //std::cout <<"update"<<std::endl;
    bool moved = _tetrimino->moveDown(&_board);
    if (!moved){
        _tetrimino->moveToBoard(&_board);
        delete _tetrimino;
        _tetrimino = new Tetrimino();
    }
    glutTimerFunc(INTERVAL, App::_updateCallback, val);
}

void App::_render(int val)
{
    //std::cout <<"render"<<std::endl;
    glClear( GL_COLOR_BUFFER_BIT );

    glLoadIdentity();

    glColor3f( 1.f, color, 0.f );
    _board.render();
    _tetrimino->render();

    glutSwapBuffers();

    glutTimerFunc( 1000 / FPS, App::_renderCallback, val);
}


void App::_handleKeys(unsigned char key, int x, int y)
{
    std::cout << key << " x:"<<x<<" y:"<<y<<std::endl;
    if (key == 'a'){
        color = 1.0f;
    } else if (key == 's'){
        color = 0.f;
    }
}

void App::_handleSpecial(int key, int x, int y)
{
    std::cout << key << " x:"<<x<<" y:"<<y<<std::endl;
    _tetrimino->horizontalMove(key, &_board);
}
