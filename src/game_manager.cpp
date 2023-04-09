#include "game_manager.h"

#include <iostream>
int game_manager::game_state[8][8];

game_manager::game_manager(SDL_Window &window, SDL_Renderer &renderer)
{
    this->window = &window;
    this->renderer = &renderer;
}

void game_manager::game_loop()
{
    bool player_move;
    // Create nessecery objects for game_loop
    game_window game_window(*window, *renderer);
    event_manager event_manager(*window, *renderer, player_move);
    game_board game_board(*window, *renderer);

    SDL_bool done = SDL_FALSE;
    SDL_bool reset = SDL_TRUE;

    //1 is for white player, 0 is for black player
    bool first_player;

    // Load piece textures
    game_board.load_textures();
    // Load reset and player button textures
    game_window.load_textures();

    while (!done)
    { // Draws reset window with buttons
        while (reset && !done)
        {
            game_window.reset();
            event_manager.events(done, reset, first_player);
        }
        if (!done)
        {
            game_window.draw_board(first_player);
            game_board.render_game_state();
            event_manager.events(done, reset);
            SDL_RenderPresent(renderer);
        }
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
