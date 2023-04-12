#if !defined(AI_H)
#define AI_H

#include <vector>
#include "game_state.h"
#include "tree.h"
#include <iostream>

struct piece
{
    int x, y, value;
    std::vector<std::pair<int, int>> possible_moves;
};

struct possible_states
{
    std::vector<int (*)[8]> states;
    int player; //MIN or MAX
};

class ai
{
private:
    std::vector<piece> movable_pieces;
    possible_states all_states;

public:
    ai(/* args */);
    ~ai();
    void get_movable_pieces(bool player_move, bool first_player);
    void create_possible_states();
    void create_game_tree();
};

#endif // AI_H
