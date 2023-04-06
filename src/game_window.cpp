#include "game_window.h"

SDL_Texture *game_window::texture_reset_button, *game_window::texture_first_player_button,
    *game_window::texture_second_player_button, *game_window::texture_you_lost, *game_window::texture_you_won;

game_window::game_window(SDL_Window &window, SDL_Renderer &renderer)

{
    this->window = &window;
    this->renderer = &renderer;
}

game_window::~game_window()
{

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}

void game_window::draw_board(bool first_player)
{
    // TODO: draw buttons - reset, and choose first player
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
    //Draw reset button
    SDL_Rect reset_rect = {700, 290, 140, 60};
    SDL_RenderCopy(renderer, texture_reset_button, NULL, &reset_rect);

}

void game_window::reset()
{
    // TODO: Render pretty backround, with game name etc.
    // Render black backround
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    SDL_Rect first_rect = {260, 290, 140, 60};
    SDL_Rect sec_rect = {600, 290, 140, 60};

    SDL_RenderCopy(renderer, texture_first_player_button, NULL, &first_rect);
    SDL_RenderCopy(renderer, texture_second_player_button, NULL, &sec_rect);

    SDL_RenderPresent(renderer);
}

void game_window::load_textures()
{
    texture_reset_button = texture_manager::load_texture("reset.bmp", renderer);
    texture_first_player_button = texture_manager::load_texture("first_player_button.bmp", renderer);
    texture_second_player_button = texture_manager::load_texture("second_player_button.bmp", renderer);
    texture_you_lost = texture_manager::load_texture("you_lost.bmp", renderer);
    texture_you_won = texture_manager::load_texture("you_won.bmp", renderer);
}