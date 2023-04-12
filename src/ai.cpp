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

    for (const auto &current_piece : movable_pieces)
    {
        // Accessing possible_moves vector values for current_piece
        for (const auto &move : current_piece.possible_moves)
        {
            create_possible_states(move.first, move.second, current_piece.x, current_piece.y, player_move, first_player);
        }
    }
}

void ai::create_possible_states(int next_x, int next_y, int prev_x, int prev_y, bool player_move, bool first_player)
{
    // Create a temporary copy of the current game state

    memcpy(current_game_state, state::game_state, sizeof(state::game_state));

    int piece = player_move ? 1 : 2;

    int x = abs(next_x - prev_x);
    int y = abs(next_y - prev_y);

    current_game_state[prev_x][prev_y] = 0;
    current_game_state[next_x][next_y] = piece;

    // Check if a piece has jumped over an opponent's piece
    if (abs(next_x - prev_x) == 2 && abs(next_y - prev_y) == 2)
    {
        // Calculate the x and y coordinates of the jumped-over piece
        int jumped_x = (next_x + prev_x) / 2;
        int jumped_y = (next_y + prev_y) / 2;

        // Update the game state to remove the jumped-over piece
        current_game_state[jumped_x][jumped_y] = 0;
    }
    // check_queens(x, y, first_player);

    // Create a new possible state with the updated game state
    possible_state new_state;
    memcpy(new_state.state, current_game_state, sizeof(current_game_state));

    new_state.value = value_state(new_state.state, first_player);
    // new_state.win
    new_state.player = piece; // min max

    // Add the new possible state to the list of all possible states
    all_possible_states.push_back(new_state);
}

bool ai::check_win(int state[8][8], bool first_player)
{
    // TODO: check win
    return false;
}

int ai::value_state(int state[8][8], bool first_player)
{
    int value = 0; // Initialize value to 0

    // Loop through the 8x8 array in the game state
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            int piece = state[i][j]; // Get the piece at current position

            if (first_player) // If first player is true, update scores for black and white pieces
            {
                if (piece == 1) // Black piece
                {
                    value--;   // Decrement value by 1
                    if (i < 4) // If black piece is closer to opponent's side
                    {
                        value -= 2; // Decrement value by 2
                    }
                }
                else if (piece == 2) // White piece
                {
                    value++;   // Increment value by 1
                    if (i > 3) // If white piece is closer to player's side
                    {
                        value += 2; // Increment value by 2
                    }
                }
            }
            else // If first player is false, update scores for white and black pieces
            {
                if (piece == 1) // White piece
                {
                    value--;   // Decrement value by 1
                    if (i > 3) // If white piece is closer to opponent's side
                    {
                        value -= 2; // Decrement value by 2
                    }
                }
                else if (piece == 2) // Black piece
                {
                    value++;   // Increment value by 1
                    if (i < 4) // If black piece is closer to player's side
                    {
                        value += 2; // Increment value by 2
                    }
                }
            }
        }
    }

    return value; // Return the calculated value
}

void ai::create_game_tree(bool first_player)
{

}
