#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include "flappy.h"

/*I followed Matsson's guide to set up this c environment + SDL canvas*/

const int WIDTH = 640;
const int HEIGHT = 480;
const int FPS = 60;
const int SIZE = 30;

int main(int argc, char *argv[])
{
    jump();
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        printf("Error initializing SDL %s\n", SDL_GetError());
        system("pause");
        return 0;
    }
    printf("SDL successfully initialized\n");

    /*create a window!*/
    SDL_Window* wind = SDL_CreateWindow("Flappy Bird",
                                      SDL_WINDOWPOS_CENTERED,
                                      SDL_WINDOWPOS_CENTERED,
                                      WIDTH, HEIGHT, 0);
  if (!wind)
  {
    printf("Error creating window: %s\n", SDL_GetError());
    system("pause");
    SDL_Quit();
    return 0;
  }
  /* Create a renderer */
  Uint32 render_flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
  SDL_Renderer* rend = SDL_CreateRenderer(wind, -1, render_flags);
  if (!rend)
  {
    printf("Error creating renderer: %s\n", SDL_GetError());
    system("pause");
    SDL_DestroyWindow(wind);
    SDL_Quit();
    return 0;
  }
  bool running = true, jumpPressed = false;
  SDL_Rect rect = {(int) 0, (int) 0, SIZE, SIZE};

  SDL_Event event;
  while (running)
  {
    /* Process events */
    while (SDL_PollEvent(&event))
    {
      switch (event.type)
      {
        case SDL_QUIT:
          running = false;
          break;
        case SDL_KEYDOWN:
          switch (event.key.keysym.scancode)
          {
            case SDL_SCANCODE_SPACE:
              jumpPressed = true;
              break;
            case SDL_SCANCODE_A:
            case SDL_SCANCODE_LEFT:
              break;
            }
          break;
        case SDL_KEYUP:
          switch (event.key.keysym.scancode)
          {
            case SDL_SCANCODE_SPACE:
              jumpPressed = false;
              break;
            case SDL_SCANCODE_A:
            case SDL_SCANCODE_LEFT:
              break;
            }
          break;
        default:
          break;
      }
    }
    rect.x = (int) 20;
    rect.y = (int) 20;
    /* Clear screen */
    SDL_SetRenderDrawColor(rend, 0, 0, 0, 255);
    SDL_RenderClear(rend);

    /* Draw the rectangle */
    SDL_SetRenderDrawColor(rend, 255, 0, 0, 255);
    SDL_RenderFillRect(rend, &rect);
    /* Draw to window and loop */
    SDL_RenderPresent(rend);
    SDL_Delay(1000/FPS);
  }
  printf("closing window");
  SDL_DestroyRenderer(rend);
  SDL_DestroyWindow(wind);
  SDL_Quit();
  return 0;
}