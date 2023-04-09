#include "game_state.h"
#include <iostream>
int state::game_state[8][8];

void state::init_game_state(bool first_player)
{
    switch (first_player)
    {
    case true:
        init_game_state_templ<true>(state::game_state);
        break;
    case false:
        init_game_state_templ<false>(state::game_state);
        break;
    default:
        throw std::invalid_argument("error in game_state.cpp");
        break;
    }
}

void state::update_game_state(int next_x, int next_y, int prev_x, int prev_y, bool player_move)
{
    int piece = player_move ? 1 : 2;

    game_state[prev_x][prev_y] = 0;
    game_state[next_x][next_y] = piece;


}
