#include "game_manager.h"

int game_manager::game_state[8][8];

game_manager::game_manager(SDL_Window &window, SDL_Renderer &renderer)
{
    this->window = &window;
    this->renderer = &renderer;
}

void game_manager::init_game_state(bool first_player)
{
    if (first_player)
        init_game_state_templ<true>(game_state);
    else
        init_game_state_templ<false>(game_state);
}

void game_manager::game_loop()
{
    // Game loop
    SDL_bool done = SDL_FALSE;
    init_game_state(true);
    // TODO: Add option to change first player
    while (!done)
    {

    }


    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}