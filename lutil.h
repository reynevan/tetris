#ifndef LUTIL_H
#define LUTIL_H

#include <GL/freeglut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>
#include "consts.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_FPS = 60;

bool initGL();

void rect(int x, int y, int w, int h);

#endif // LUTIL_H
