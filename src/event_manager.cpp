#include "event_manager.h"
#include <iostream>
#include <vector>
event_manager::event_manager(SDL_Window &window, SDL_Renderer &renderer, bool &player_move, ai &ai_player)
{
    this->window = &window;
    this->renderer = &renderer;
    this->player_move = player_move;
    this->ai_player = ai_player;
    rect_x = 0, rect_y = 0;
    first_click_on_piece = false;
}

void event_manager::events(SDL_bool &done)
{
    SDL_bool reset = SDL_FALSE;
    bool first_player = false;
    events(done, reset, first_player);
}

void event_manager::events(SDL_bool &done, SDL_bool &reset)
{
    // TODO: ATM this is not used.
    bool first_player = false;
    events(done, reset, first_player);
}

void event_manager::events(SDL_bool &done, SDL_bool &reset, bool &first_player)
{
    SDL_bool event_loop_done = SDL_FALSE;

    SDL_Event event;

    do
    {
        if (SDL_PollEvent(&event) != 0)
        {
            switch (event.type)
            {
            case SDL_QUIT:
                done = SDL_TRUE;
                event_loop_done = SDL_TRUE;
                break;
            case SDL_MOUSEBUTTONDOWN:
                if (event.button.button == SDL_BUTTON_LEFT)
                {
                    if (!reset)
                    {
                        prev_x = rect_x;
                        prev_y = rect_y;

                        if (player_move == 0)
                        {
                            ai_player.get_movable_pieces(player_move, first_player);
                            
                            //create tree
                            //do move based on tree
                        }
                        handle_click(event.button.x, event.button.y, reset);
                        if (first_click_on_piece)
                        {
                            if (check_if_possible_move())
                            {
                                state::update_game_state(next_x, next_y, prev_x, prev_y, player_move, first_player);
                                player_move = !player_move;
                            }

                            event_loop_done = SDL_TRUE;
                            first_click_on_piece = false;
                            break;
                        }
                        if (check_if_clicked_piece())
                        {
                            possible_moves(first_player);
                            first_click_on_piece = true;
                        }
                        event_loop_done = SDL_TRUE;
                    }
                    else if (handle_reset_click(event.button.x, event.button.y, reset, first_player))
                    {
                        state::init_game_state(first_player);
                        player_move = true;
                        event_loop_done = SDL_TRUE;
                    }
                }
                break;
            default:
                break;
            }
        }
    } while (!done && !event_loop_done);
}

void event_manager::handle_click(int x, int y, SDL_bool &reset)
{
    pos_x = x;
    pos_y = y;
    // Menu screen
    if (x >= 640 && x <= 1000 && y >= 0 && y <= 640)
    {
        if (check_button_press(x, y, 700, 290, 140, 60))
            reset = SDL_TRUE;
    }
    else
    {
        // Rectangle position from 0 - 7
        rect_x = y / 80;
        rect_y = x / 80;
    }
}

bool event_manager::handle_reset_click(int x, int y, SDL_bool &reset, bool &first_player)
{

    if (check_button_press(x, y, 260, 290, 140, 60))
    {
        first_player = true;
        reset = SDL_FALSE;
        return true;
    }

    if (check_button_press(x, y, 600, 290, 140, 60))
    {
        first_player = false;
        reset = SDL_FALSE;
        return true;
    }
    return false;
}

bool event_manager::check_button_press(int mouse_x, int mouse_y, int x, int y, int w, int h)
{
    if (mouse_x >= x && mouse_x <= (x + w) && mouse_y >= y && mouse_y <= (y + h))
        return true;
    return false;
}

bool event_manager::check_if_clicked_piece()
{
    int piece = state::game_state[rect_x][rect_y];

    if (pos_x > 640 || piece == 0)
        return false;

    if ((player_move && piece == 1) || (!player_move && piece == 2))
        return true;

    return false;
}

bool event_manager::check_if_possible_move()
{
    for (auto move : moves)
    {
        int mx = move.first;
        int my = move.second;

        if (rect_y == mx && rect_x == my)
        {
            next_x = rect_x;
            next_y = rect_y;
            return true;
        }
    }
    return false;
}

void event_manager::possible_moves(bool first_player)
{

    using namespace state;

    moves.clear();
    // Get the game state and the selected piece's position
    int(*board)[8] = game_state;

    int x = rect_y;
    int y = rect_x;
    int opponent;

    bool must_take = false;
    // Check if the selected piece is white or black
    int player = board[y][x];

    int temp = 1;
    if (!first_player)
    {
        temp = 2;
    }

    opponent = (player == 1) ? 2 : 1;

    // Calculate the possible moves for the selected piece
    if (player == temp)
    {
        if (y > 0)
        {
            // Check if opponent is in way. Left and right
            if (y > 1 && x > 1 && board[y - 1][x - 1] == opponent && board[y - 2][x - 2] == 0)
            {

                moves.emplace_back(x - 2, y - 2);
                must_take = true;
            }
            if (y > 1 && x < 6 && board[y - 1][x + 1] == opponent && board[y - 2][x + 2] == 0)
            {
                moves.emplace_back(x + 2, y - 2);
                must_take = true;
            }
            // Check UP diagnally left and right.
            if (!must_take && x > 0 && board[y - 1][x - 1] == 0)
            {
                moves.emplace_back(x - 1, y - 1);
            }
            if (!must_take && x < 7 && board[y - 1][x + 1] == 0)
            {
                moves.emplace_back(x + 1, y - 1);
            }
        }
    }
    else
    {
        // Check if opponent is in way. Left and right
        if (y < 6 && x > 1 && board[y + 1][x - 1] == opponent && board[y + 2][x - 2] == 0)
        {
            moves.emplace_back(x - 2, y + 2);
            must_take = true;
        }
        if (y < 6 && x < 6 && board[y + 1][x + 1] == opponent && board[y + 2][x + 2] == 0)
        {
            moves.emplace_back(x + 2, y + 2);

            must_take = true;
        }
        // Check DOWN diagnally left and right.
        if (y < 7)
        {
            if (!must_take && x > 0 && board[y + 1][x - 1] == 0)
            {
                moves.emplace_back(x - 1, y + 1);
            }
            if (!must_take && x < 7 && board[y + 1][x + 1] == 0)
            {
                moves.emplace_back(x + 1, y + 1);
            }
        }
    }

    // Color the possible moves green
    // TODO: Moves this to game_board.
    for (auto move : moves)
    {
        int mx = move.first;
        int my = move.second;
        // std::cout << mx << "  " << my << std::endl;

        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255); // Green color

        SDL_Rect rect = {mx * 80, my * 80, 80, 80};
        SDL_RenderFillRect(renderer, &rect);
    }
}

void event_manager::check_consecutive_jumps(int x, int y, int dx, int dy, int opponent)
{
    int inext_x = x + dx;
    int inext_y = y + dy;

    // Check if opponent is in the way
    if (inext_x >= 0 && inext_x < 8 && inext_y >= 0 && inext_y < 8 && state::game_state[inext_x][inext_y] == opponent)
    {
        int jump_x = inext_x + dx;
        int jump_y = inext_y + dy;

        // Check if the square after opponent is empty
        if (jump_x >= 0 && jump_x < 8 && jump_y >= 0 && jump_y < 8 && state::game_state[jump_y][jump_x] == 0)
        {
            // Add the possible consecutive jump move
            moves.emplace_back(jump_x, jump_y);

            // Recursively check for more consecutive jumps
            check_consecutive_jumps(jump_x, jump_y, dx, dy, opponent);
        }
    }
}
