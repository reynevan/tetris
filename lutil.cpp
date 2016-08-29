#include "lutil.h"
#include "app.h"
#include "block.h"

bool initGL()
{
    int width = BOARD_X * Block::size;
    int height = BOARD_Y * Block::size;
    glutInitContextVersion( 2, 1 );
    glutInitDisplayMode( GLUT_DOUBLE );
    glutInitWindowSize(width, height);
    glutCreateWindow( "OpenGL" );

    glViewport( 0.f, 0.f, width, height );
    //Initialize Projection Matrix
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    glOrtho( 0.0, width, height, 0.0, 1.0, -1.0 );

    //Initialize Modelview Matrix
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();

    //Initialize clear color
    glClearColor( 0.f, 0.f, 0.f, 1.f );

    //Check for error
    GLenum error = glGetError();
    if( error != GL_NO_ERROR )
    {
        printf( "Error initializing OpenGL! %s\n", gluErrorString( error ) );
        return false;
    }

    return true;
}

void rect(int x, int y, int w, int h)
{
    glBegin( GL_QUADS );
        glVertex2f(x, y);
        glVertex2f(x, y+h);
        glVertex2f(x+w, y+h);
        glVertex2f(x+w, y);
    glEnd();
}
