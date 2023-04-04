#include "game_board.h"

int game_board::game_state[8][8];

game_board::game_board(/* args */)
{
}

void game_board::init_game_state(bool first_player)
{

    if (first_player)
    {
        init_game_state_templ<true>(game_state);
    }
    else
    {
        init_game_state_templ<false>(game_state);
    }
}
void game_board::render_game_state(){
    //draw pieces on the board where the game state piece are

}
