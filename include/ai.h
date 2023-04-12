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

struct possible_state
{
    int state[8][8];
    int player; // MIN or MAX
    int value;
    bool win;
};

class ai
{
private:
    std::vector<piece> movable_pieces;
    std::vector<possible_state> all_possible_states;
    int current_game_state[8][8];
public:
    ai(/* args */);
    ~ai();
    void get_movable_pieces(bool player_move, bool first_player);
    void create_possible_states(int next_x, int next_y, int prev_x, int prev_y, bool player_move, bool first_player);
    void create_game_tree(bool first_player);
    int value_state(int state[8][8], bool first_player);
    bool check_win(int state[8][8], bool first_player);
};

#endif // AI_H
