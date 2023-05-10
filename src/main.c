#include <stdio.h>
#include <SDL2/SDL.h>

int main(int argc, char *argv[])
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        printf("Error initializing SDL %s\n", SDL_GetError());
        system("pause");
        return 0;
    }
    printf("SDL successfully initialized\n");
    system("pause");
    return 0;
    

}