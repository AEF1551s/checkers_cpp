#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "game.h"
#include "templates.cpp"



int main(int argc, char *argv[])
{
    const int disp_size_x = 1000;
    const int disp_size_y = 640;

    int game_state[8][8];
    
    init_game_state<true>(game_state);

    //TODO: catch exceptions 
    SDL_Window *window = SDL_CreateWindow("Checkers", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, disp_size_x, disp_size_y, 0);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    game game(window, renderer);
    game.draw_board(true);
    game.events();

    return 0;
}