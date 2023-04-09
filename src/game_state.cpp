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