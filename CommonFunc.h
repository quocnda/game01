#ifndef COMMON_FUNC_H_
#define COMMON_FUNC_H_

#include <SDL_image.h>
#include <SDL.h>
#include<iostream>

static SDL_Window* gWindow=NULL;
static SDL_Renderer* gScreen=NULL;
static SDL_Texture* gText=NULL;
static SDL_Event gevent;

const int SCREEN_WIDTH=700;
const int SCREEN_HEIGHT=700;

typedef struct Input{
    int left;
    int right;
    int up;
    int down;
};

#endif // COMMON_FUNC_H_
