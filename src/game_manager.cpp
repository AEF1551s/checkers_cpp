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
    // Create nessecery objects for game_loop
    game_window game_window(*window, *renderer);
    event_manager event_manager;
    game_board game_board(*window, *renderer);

    SDL_bool done = SDL_FALSE;
    SDL_bool reset = SDL_TRUE;
    bool first_player = false;

    // Load piece textures
    game_board.load_textures();
    // Load reset and player button textures
    game_window.load_textures();

    while (!done)
    { // Draws reset window with buttons
        while (reset)
        {
            game_window.reset();
            event_manager.events(done, reset, first_player);
        }
        gamestate::init_game_state(first_player);

        game_window.draw_board(first_player);
        game_board.render_game_state();
        event_manager.events(done, reset);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
