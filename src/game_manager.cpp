#include "game_manager.h"

#include <iostream>
int game_manager::game_state[8][8];

game_manager::game_manager(SDL_Window &window, SDL_Renderer &renderer)
{
    this->window = &window;
    this->renderer = &renderer;
}

// void game_manager::init_game_state(bool first_player)
// {
//     if (first_player)
//         init_game_state_templ<true>(game_state);
//     else
//         init_game_state_templ<false>(game_state);
// }

void game_manager::game_loop()
{
    // Create nessecery objects for game_loop
    game_window game_window(*window, *renderer);
    event_manager event_manager;
    game_board game_board(*window, *renderer);

    SDL_bool done = SDL_FALSE;
    bool first_player = true;

    // Load piece textures
    game_board.load_textures();

    gamestate::init_game_state(first_player);

    // Render starting game piece textures
    game_window.draw_board(first_player);
    game_board.render_game_state();

    //bool chosen_player;
    // draw ask signs, and ask if first player.
    //  
    //     //Create and render window

    while (!done)
    {
        // TODO: Add option to change first player
    
        event_manager.events(done);

        // game_board.render_game_state();
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
