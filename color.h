#ifndef COLOR_H
#define COLOR_H

#include "lutil.h"

struct Color{
    GLfloat red;
    GLfloat green;
    GLfloat blue;

    Color(){}
    Color(GLfloat _red, GLfloat _green, GLfloat _blue) : red(_red), green(_green), blue(_blue)
    {
    }
};

#endif // COLOR_H
