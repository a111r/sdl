#include "sdl_easy.h"

void it_horizontalLine(SDL_Renderer *render, int x, int y, int length){
    int cursorMove;
    if(length >= 0)
        cursorMove = 1;
    else{
        cursorMove = -1;
        length *= - 1;
    }
    for(int i = 0; i < length; i++){
        SDL_RenderDrawPoint(render, x, y);
        x += cursorMove;
    }
