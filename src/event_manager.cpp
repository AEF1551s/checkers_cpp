#include "event_manager.h"
#include <iostream>

event_manager::event_manager(SDL_Window &window, SDL_Renderer &renderer)
{
    this->window = &window;
    this->renderer = &renderer;
}

void event_manager::events(SDL_bool &done)
{
    SDL_bool reset = SDL_FALSE;
    bool first_player = NULL;
    events(done, reset, first_player);
}

void event_manager::events(SDL_bool &done, SDL_bool &reset)
{
    bool first_player = NULL;
    events(done, reset, first_player);
}

void event_manager::events(SDL_bool &done, SDL_bool &reset, bool &first_player)
{

    SDL_bool event_loop_done = SDL_FALSE;

    SDL_Event event;

    // TODO: ADD player 1 and player 2 input events.
    // IF its players move, then do this, if its computers move, do computer class stuff.
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
                        handle_click(event.button.x, event.button.y, reset);

                        if (check_if_clicked_piece())
                        {
                            possible_moves();
                        }

                        // TODO: If pressed on possible move, update game_state
                        /*
            TODO: if pressed second time, check if allowed, and move piece,
            change state::game_state array. set event_loop_done = true
            otherwise event_loop_done = false, so there is no need to update the pieces on the table
            if nothing has moved.
            */
                        event_loop_done = SDL_TRUE;
                    }
                    else if (handle_reset_click(event.button.x, event.button.y, reset, first_player))
                    {
                        state::init_game_state(first_player);
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
    if (pos_x > 640)
        return false;

    if (state::game_state[rect_x][rect_y] != 0)
    {
        // std::cout << "clicked piece " << std::endl;
        return true;
    }
    return false;
}

void event_manager::possible_moves()
{

    using namespace state;

    // Get the game state and the selected piece's position
    int(*board)[8] = game_state;

    int x = rect_y;
    int y = rect_x;

    // std::cout << board[y][x] << " " << x << " " << y << std::endl;

    // Check if the selected piece is white or black
    int player = board[y][x];
    int opponent = (player == 1) ? 2 : 1;

    // Calculate the possible moves for the selected piece
    std::vector<std::pair<int, int>> moves;

    if (player == 1)
    {
        // Check moves for white piece
        if (y > 0)
        {
            if (x > 0 && board[y - 1][x - 1] == 0)
            {
                moves.emplace_back(x - 1, y - 1);
            }
            if (x < 7 && board[y - 1][x + 1] == 0)
            {
                moves.emplace_back(x + 1, y - 1);
            }
        }
        if (y > 1 && x > 1 && board[y - 1][x - 1] == opponent && board[y - 2][x - 2] == 0)
        {
            moves.emplace_back(x - 2, y - 2);
        }
        if (y > 1 && x < 6 && board[y - 1][x + 1] == opponent && board[y - 2][x + 2] == 0)
        {
            moves.emplace_back(x + 2, y - 2);
        }
    }
    else
    {
        // Check moves for black piece
        if (y < 7)
        {
            if (x > 0 && board[y + 1][x - 1] == 0)
            {
                moves.emplace_back(x - 1, y + 1);
            }
            if (x < 7 && board[y + 1][x + 1] == 0)
            {
                moves.emplace_back(x + 1, y + 1);
            }
        }
        if (y < 6 && x > 1 && board[y + 1][x - 1] == opponent && board[y + 2][x - 2] == 0)
        {
            moves.emplace_back(x - 2, y + 2);
        }
        if (y < 6 && x < 6 && board[y + 1][x + 1] == opponent && board[y + 2][x + 2] == 0)
        {
            moves.emplace_back(x + 2, y + 2);
        }
    }

    // Color the possible moves green
    // TODO: Moves this to game_board.
    for (auto move : moves)
    {
        int mx = move.first;
        int my = move.second;

        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255); // Green color

        SDL_Rect rect = {mx * 80, my * 80, 80, 80};
        SDL_RenderFillRect(renderer, &rect);
    }
}
