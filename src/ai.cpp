#include "ai.h"

ai::ai(/* args */)
{
}

ai::~ai()
{
}

void ai::get_movable_pieces(bool player_move, bool first_player)
{
    // first_player bool is to know, which way to calculate the possible positions.
    // player = 1 if black piece is going
    // player = 2 if white piece is going
    int(*board)[8] = state::game_state;

    int player = (player_move == false) ? 2 : 1;

    // std::cout << player << std::endl;
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            // Check if the piece at the current position is movable
            if (board[i][j] == player)
            {
                // When checking game state, i is row, and j is column. x is row, y is collumn. When rendering x is column, and y is row such as axis
                piece current_piece;
                current_piece.value = player;
                current_piece.x = i;
                current_piece.y = j;
                int opponent, x, y;
                bool must_take = false;

                int temp = 1;
                if (!first_player)
                {
                    temp = 2;
                }

                opponent = (player == 1) ? 2 : 1;
                // std::cout << player <<" "<< opponent<< std::endl;

                // FIXME: Change x and y, for better readabilitty
                // y = i;
                // x = j;
                x = i;
                y = j;

                // Calculate the possible moves for the selected piece
                if (player == temp)
                {
                    if (y > 0)
                    {
                        // Check if opponent is in way. Left and right
                        if (y > 1 && x > 1 && board[y - 1][x - 1] == opponent && board[y - 2][x - 2] == 0)
                        {
                            current_piece.possible_moves.emplace_back(x - 2, y - 2);
                            must_take = true;
                        }
                        if (y > 1 && x < 6 && board[y - 1][x + 1] == opponent && board[y - 2][x + 2] == 0)
                        {
                            current_piece.possible_moves.emplace_back(x + 2, y - 2);
                            must_take = true;
                        }
                        // Check UP diagnally left and right.
                        if (!must_take && x > 0 && board[y - 1][x - 1] == 0)
                        {
                            current_piece.possible_moves.emplace_back(x - 1, y - 1);
                        }
                        if (!must_take && x < 7 && board[y - 1][x + 1] == 0)
                        {
                            current_piece.possible_moves.emplace_back(x + 1, y - 1);
                        }
                    }
                }
                else
                {
                    // Check if opponent is in way. Left and right
                    if (y < 6 && x > 1 && board[y + 1][x - 1] == opponent && board[y + 2][x - 2] == 0)
                    {
                        current_piece.possible_moves.emplace_back(x - 2, y + 2);
                        must_take = true;
                    }
                    if (y < 6 && x < 6 && board[y + 1][x + 1] == opponent && board[y + 2][x + 2] == 0)
                    {
                        current_piece.possible_moves.emplace_back(x + 2, y + 2);
                        must_take = true;
                    }
                    // Check DOWN diagnally left and right.
                    if (y < 7)
                    {
                        if (!must_take && x > 0 && board[y + 1][x - 1] == 0)
                        {
                            current_piece.possible_moves.emplace_back(x - 1, y + 1);
                        }
                        if (!must_take && x < 7 && board[y + 1][x + 1] == 0)
                        {
                            current_piece.possible_moves.emplace_back(x + 1, y + 1);
                        }
                    }
                }
                movable_pieces.emplace_back(current_piece);

            }
        }
    }
}
                // for (const auto &move : current_piece.possible_moves)
                // {
                //     // std::cout << "Possible Move: (" << move.first << ", " << move.second << ")" << std::endl;
                //     // state::update_game_state(move.second, move.first, current_piece.y, current_piece.x, player_move, first_player);
                //     std::cout << "Current piece x : y " << current_piece.x << " : " << current_piece.y << std::endl;
                //     // std::cout << "possible moves" << move.first << " : " << move.second << std::endl;
                // }
                // // state::update_game_state(3,0, 2,1,player_move, first_player);

                // // std::cout << current_piece.x << " : " << current_piece.y << std::endl; //correct

void ai::create_possible_states()
{
    // Create a temporary copy of the game state
    int temp_board[8][8];
    memcpy(temp_board, state::game_state, sizeof(state::game_state));

    // // Loop through each movable piece
    // for (const piece &p : movable_pieces)
    // {
    //     int player = p.value;
    //     int x = p.x;
    //     int y = p.y;

    //     // Loop through each possible move for the current piece
    //     for (const std::pair<int, int> &move : p.possible_moves)
    //     {
    //         int new_x = move.first;
    //         int new_y = move.second;

    //         // Update the temporary game state with the current move
    //         temp_board[y][x] = 0;
    //         temp_board[new_y][new_x] = player;

    //         // Create a new possible state with the updated game state and player
    //         int(*new_state)[8] = new int[8][8];
    //         memcpy(new_state, temp_board, sizeof(temp_board));

    //         possible_states new_possible_state;
    //         new_possible_state.states.emplace_back(new_state);
    //         new_possible_state.player = player;

    //         // Add the new possible state to the all_states vector
    //         all_states.states.emplace_back(new_possible_state);
    //     }
    // }
}
