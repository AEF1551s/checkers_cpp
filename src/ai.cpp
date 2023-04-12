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

    for (int x = 0; x < 8; ++x)
    {
        for (int y = 0; y < 8; ++y)
        {
            // Check if the piece at the current position is movable
            if (board[x][y] == player)
            {
                // When checking game state, x is row, and y is column. x is row, y is column when rendering.
                piece current_piece;
                current_piece.value = player;
                current_piece.x = x;
                current_piece.y = y;
                int opponent;
                bool must_take = false;

                int temp = 1;
                if (!first_player)
                {
                    temp = 2;
                }

                opponent = (player == 1) ? 2 : 1;

                // Calculate the possible moves for the selected piece
                if (player == temp)
                {
                    if (x > 0)
                    {
                        // Check if opponent is in the way. Left and right
                        if (x > 1 && y > 1 && board[x - 1][y - 1] == opponent && board[x - 2][y - 2] == 0 && x - 2 >= 0 && y - 2 >= 0)
                        {
                            current_piece.possible_moves.emplace_back(x - 2, y - 2);
                            must_take = true;
                        }
                        if (x > 1 && y < 6 && board[x - 1][y + 1] == opponent && board[x - 2][y + 2] == 0 && x - 2 >= 0 && y + 2 < 8)
                        {
                            current_piece.possible_moves.emplace_back(x - 2, y + 2);
                            must_take = true;
                        }
                        // Check UP diagonally left and right.
                        if (!must_take && y > 0 && board[x - 1][y - 1] == 0 && x - 1 >= 0 && y - 1 >= 0)
                        {
                            current_piece.possible_moves.emplace_back(x - 1, y - 1);
                        }
                        if (!must_take && y < 7 && board[x - 1][y + 1] == 0 && x - 1 >= 0 && y + 1 < 8)
                        {
                            current_piece.possible_moves.emplace_back(x - 1, y + 1);
                        }
                    }
                }
                else
                {
                    if (y < 7)
                    {
                        // Check if opponent is in the way. Left and right
                        if (y < 6 && x > 1 && board[x + 1][y + 1] == opponent && board[x + 2][y + 2] == 0 && x + 2 < 8 && y + 2 < 8)
                        {
                            current_piece.possible_moves.emplace_back(x + 2, y + 2);
                            must_take = true;
                        }
                        if (y < 6 && x < 6 && board[x + 1][y - 1] == opponent && board[x + 2][y - 2] == 0 && x + 2 < 8 && y - 2 >= 0)
                        {
                            current_piece.possible_moves.emplace_back(x + 2, y - 2);
                            must_take = true;
                        }
                        // Check DOWN diagonally left and right.
                        if (!must_take && x < 7 && board[x + 1][y + 1] == 0 && x + 1 < 8 && y + 1 < 8)
                        {
                            current_piece.possible_moves.emplace_back(x + 1, y + 1);
                        }
                        if (!must_take && x < 7 && board[x + 1][y - 1] == 0 && x + 1 < 8 && y - 1 >= 0)
                        {
                            current_piece.possible_moves.emplace_back(x + 1, y - 1);
                        }
                    }
                }
                movable_pieces.emplace_back(current_piece);
            }
        }
    }
    // for (const auto &current_piece : movable_pieces)
    // {
    //     // Accessing possible_moves vector values for current_piece
    //     std::cout << "Possible moves for piece at (" << current_piece.x << ", " << current_piece.y << "): ";
    //     for (const auto &move : current_piece.possible_moves)
    //     {
    //         std::cout << "(" << move.first << ", " << move.second << ") ";
    //     }
    //     std::cout << std::endl;
    // }
}

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
