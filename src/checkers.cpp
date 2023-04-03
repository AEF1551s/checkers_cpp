#include "checkers.h"
#include "texture_manager.h"

const SDL_Texture *checkers::texture_black, *checkers::texture_black_q,
    *checkers::texture_white, *checkers::texture_white_q;

checkers::checkers(SDL_Window *window, SDL_Renderer *renderer)
{
    this->renderer = renderer;
    this->window = window;
}

void checkers::load_textures()
{
    texture_black = texture_manager::load_texture("black_piece", renderer);
    texture_black_q = texture_manager::load_texture("black_piece_q", renderer);
    texture_white = texture_manager::load_texture("white_piece", renderer);
    texture_white_q = texture_manager::load_texture("white_piece_q", renderer);
}