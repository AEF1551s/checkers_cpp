#if !defined(GAME_STATE_H)
#define GAME_STATE_H

#include "templates.h"

namespace gamestate
{
    extern int game_state[8][8];

    void init_game_state(bool first_player);

}

#endif // GAME_STATE_H
