#include "lutil.h"
#include "app.h"

void runMainLoop( int val );


int main( int argc, char* args[] )
{
    glutInit( &argc, args );
    if( !initGL() )
    {
        return 1;
    }

    App app;

    return 0;
}
