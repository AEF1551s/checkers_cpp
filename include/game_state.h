#if !defined(GAME_STATE_H)
#define GAME_STATE_H

#include "templates.h"
#include "tree.h"
#include <stdexcept>

namespace state
{

    // Define a struct to represent the game state
    struct game_state
    {
        // Define your game state variables here
    };

    extern int game_state[8][8];

    void init_game_state(bool first_player);
    void update_game_state(int next_x, int next_y, int prev_x, int prev_y, bool player_move, bool first_player);
    void check_queens(int x, int y, bool first_player);
}

#endif // GAME_STATE_H
