#if !defined(GAME_STATE_H)
#define GAME_STATE_H

#include "templates.h"
#include <stdexcept>

namespace state
{
    extern int game_state[8][8];

    void init_game_state(bool first_player);
    bool update_game_state(int next_x, int next_y, int prev_x, int prev_y, bool player_move);
}

#endif // GAME_STATE_H
