#if !defined(GAME_BOARD_H)
#define GAME_BOARD_H

#include "templates.h"

class game_board
{
private:
    static int game_state[8][8];

public:
    game_board(/* args */);
    void init_game_state(bool first_player);
    void render_game_state();
};

#endif // GAME_BOARD_H
