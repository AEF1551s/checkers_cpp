#include "game_board.h"


#include <iostream>
// int game_board::game_state[8][8];

SDL_Texture *game_board::texture_black, *game_board::texture_black_q,
    *game_board::texture_white, *game_board::texture_white_q,
    *game_board::texture_reset_button, 
    *game_board::texture_first_player_button, *game_board::texture_second_player_button, 
    *game_board::texture_you_lost, *game_board::texture_you_won;

game_board::game_board(SDL_Window &window, SDL_Renderer &renderer)
{
    this->window = &window;
    this->renderer = &renderer;
}

void game_board::render_game_state()
{
    // Render game pieces on board
    for (int i = 0; i < 8; i++)
    {
        std::cout << std::endl;
        for (int j = 0; j < 8; j++)
        {
            SDL_Rect piece_rect = {j * 80, i * 80, 80, 80};
            //FIXME: need vertical rendering, not horizontal
            int piece = gamestate::game_state[i][j];
            std:: cout << piece;
            switch (piece)
            {
            case 1: // white piece
                SDL_RenderCopy(renderer, texture_white, NULL, &piece_rect);
                break;
            case 2: // black piece
                SDL_RenderCopy(renderer, texture_black, NULL, &piece_rect);
                break;
            case 3: // white queen
                SDL_RenderCopy(renderer, texture_white_q, NULL, &piece_rect);
                break;
            case 4: // black queen
                SDL_RenderCopy(renderer, texture_black_q, NULL, &piece_rect);
                break;
            default:   // empty space
                break; // do nothing
            }
        }
    }
    SDL_RenderPresent(renderer);
}

void game_board::load_textures()
{
    texture_black = texture_manager::load_texture("black_piece.bmp", renderer);
    texture_black_q = texture_manager::load_texture("black_piece_q.bmp", renderer);
    texture_white = texture_manager::load_texture("white_piece.bmp", renderer);
    texture_white_q = texture_manager::load_texture("white_piece_q.bmp", renderer);
    texture_reset_button = texture_manager::load_texture("reset.bmp", renderer);
    texture_first_player_button = texture_manager::load_texture("first_player_button.bmp", renderer);
    texture_second_player_button = texture_manager::load_texture("second_player_button.bmp", renderer);
    texture_you_lost = texture_manager::load_texture("you_lost.bmp", renderer);
    texture_you_won = texture_manager::load_texture("you_won.bmp", renderer);
}
