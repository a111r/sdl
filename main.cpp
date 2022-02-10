#include "sdl_easy.h"
#define WINDOW_SIZE 1000

using namespace std;

int main(int argc, char* args[])
{
    SDL_Renderer *renderer;
    SDL_Window *window;
    SDL_Init( SDL_INIT_VIDEO);


    SDL_CreateWindowAndRenderer(WINDOW_WIDTH, WINDOW_WIDTH, 0, &window, &renderer);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);

    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
    it_horizontalLine(renderer, 500, 500 , 100);

    SDL_RenderPresent(renderer);

    SDL_RenderClear(renderer);
    SDL_Delay(3000);
    SDL_Quit();
    return 0;
}
