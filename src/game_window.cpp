#include "game_window.h"

game_window::game_window(SDL_Window &window, SDL_Renderer &renderer)
{
    this->window = &window;
    this->renderer = &renderer;
}

game_window::~game_window(){

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}

void game_window::draw_board(bool first_player)
{
    if (first_player)
    {
        // Set backround colour to black
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        // Set next used colour to white
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    }
    else
    {
        // Set backround colour to white
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);
        // Set next used colour to black
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    }

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if ((i + j) % 2 == 0)
            {
                SDL_Rect rect = {i * 80, j * 80, 80, 80};
                // Render filled rectangle
                SDL_RenderFillRect(renderer, &rect);
            }
        }
    }

    // Right menu screen
    SDL_SetRenderDrawColor(renderer, 0, 102, 0, 255);
    SDL_Rect menu_rect = {640, 0, 360, 640};
    SDL_RenderFillRect(renderer, &menu_rect);

    //TODO: Render buttons to choose first or second player, reset game, quit game. 

    SDL_RenderPresent(renderer);
}
