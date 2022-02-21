#include <SDL.h>
#include <iostream>
#include <cmath>
#define WINDOW_SIZE 1000
#define WINDOW_WIDTH 1000

using namespace std;

void line_DDA(float x1, float y1, float x2, float y2, SDL_Renderer* renderer)
{
    int iX1 = roundf(x1);
    int iY1 = roundf(y1);
    int iX2 = roundf(x2);
    int iY2 = roundf(y2);
    int deltaX = abs(iX1 - iX2);
    int deltaY = abs(iY1 - iY2);
    int lenght = fmax(deltaX, deltaY);
    if( lenght == 0)
    {
        SDL_RenderDrawPoint(renderer, iX1, iY1);
        return;
    }
    double dX = (x2 - x1) / lenght;
    double dY = (y2 - y1) / lenght;
    double x = x1;
    double y = y1;
    lenght++;
    while (lenght--)
    {
        x += dX;
        y += dY;
        SDL_RenderDrawPoint(renderer, roundf(x), roundf(y));
    }
}

int main(int argc, char* args[])
{
    SDL_Renderer *renderer;
    SDL_Window *window;
    SDL_Init( SDL_INIT_VIDEO);


    SDL_CreateWindowAndRenderer(WINDOW_WIDTH, WINDOW_WIDTH, 0, &window, &renderer);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);

    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);

    line_DDA(100,100, 900,100,renderer);

    line_DDA(900,100, 900,400,renderer);// kvadrat
    line_DDA(900,400, 600 ,400,renderer);
    line_DDA(600,400, 600,100,renderer);

    line_DDA(100,100, 100,300,renderer);// pryamougol'nik
    line_DDA(100,300, 600,300,renderer);

    line_DDA(150,300, 150,350,renderer);// kvadrat1
    line_DDA(150,350, 200,350,renderer);
    line_DDA(200,350, 200,300,renderer);

    line_DDA(550,300, 550,350,renderer);// kvadrat2
    line_DDA(550,350, 500,350,renderer);
    line_DDA(500,350, 550,350,renderer);
    line_DDA(500,350, 500,300,renderer);

    line_DDA(700,400, 700,500,renderer); //kvadrat3
    line_DDA(700,500, 800,500,renderer);
    line_DDA(800,500, 800,400,renderer);

    line_DDA(275,150, 425,150,renderer);
    line_DDA(425,150, 425,175,renderer);
    line_DDA(425,175, 275,175,renderer);
    line_DDA(275,175, 275,150,renderer);

    SDL_RenderPresent(renderer);

    SDL_RenderClear(renderer);
    SDL_Delay(100000);
    SDL_Quit();
    return 0;
}

