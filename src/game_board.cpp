#include "game_board.h"

int game_board::game_state[8][8];

SDL_Texture *game_board::texture_black, *game_board::texture_black_q,
    *game_board::texture_white, *game_board::texture_white_q;

game_board::game_board(SDL_Window &window, SDL_Renderer &renderer)
{
    this->window = &window;
    this->renderer = &renderer;
}

void game_board::render_game_state()
{
    // draw pieces on the board where the game state piece are
}

void game_board::load_textures()
{
    texture_black = texture_manager::load_texture("black_piece", renderer);
    texture_black_q = texture_manager::load_texture("black_piece_q", renderer);
    texture_white = texture_manager::load_texture("white_piece", renderer);
    texture_white_q = texture_manager::load_texture("white_piece_q", renderer);
}
