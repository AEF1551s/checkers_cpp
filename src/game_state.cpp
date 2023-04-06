#include "game_state.h"
#include <iostream>
int gamestate::game_state[8][8];

void gamestate::init_game_state(bool first_player)
{
    switch (first_player)
    {
    case true:
        init_game_state_templ<true>(gamestate::game_state);
        break;
    case false:
        init_game_state_templ<false>(gamestate::game_state);
        break;
    default:
        throw std::invalid_argument("error in game_state.cpp");
        break;
    }
}