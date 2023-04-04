#include "game_state.h"

int gamestate::game_state[8][8];

void gamestate::init_game_state(bool first_player)
{
    if (first_player)
        init_game_state_templ<true>(gamestate::game_state);
    else
        init_game_state_templ<false>(gamestate::game_state);
}