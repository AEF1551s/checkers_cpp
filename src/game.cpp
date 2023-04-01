#include "game.h"
#include <iostream>

game::game(int size_x, int size_y)
{
    this->size_x = size_x;
    this->size_y = size_y;
}

void game::init()
{
    window = SDL_CreateWindow("Checkers", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, size_x, size_y, 0);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

void game::draw_board(bool first_player)
{
    if (first_player)
    {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    }else{
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    }


    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if ((i + j) % 2 == 0)
            {
                SDL_Rect rect = {i * 80, j * 80, 80, 80};
                SDL_RenderFillRect(renderer, &rect);
            }
        }
    }
    
    


    SDL_RenderPresent(renderer);
}

void game::events()
{
    SDL_bool done = SDL_FALSE;
    while (!done)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                done = SDL_TRUE;
                break;

            case SDL_MOUSEBUTTONDOWN:
                if (event.button.button == SDL_BUTTON_LEFT)
                {
                    //relative position to window
                    pos_xy[0] = event.button.x;
                    pos_xy[1] = event.button.y;

                    //rectangle position from 0 - 7
                    rect_xy[0] = pos_xy[0] / 80;
                    rect_xy[1] = pos_xy[1] / 80;
                }
            default:
                break;
            }
        }

        // SDL_GetMouseState();
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}