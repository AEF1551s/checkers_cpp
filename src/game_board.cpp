#include "game_board.h"

int game_board::game_state[8][8];

game_board::game_board(SDL_Window &window, SDL_Renderer &renderer)
{
    this->window = &window;
    this->renderer = &renderer;
}

void game_board::render_game_state()
{
    // draw pieces on the board where the game state piece are
}
