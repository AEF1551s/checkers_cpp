#include "event_manager.h"
#include <iostream>

event_manager::event_manager()
{
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

                        // TODO: Show possible moves, if pressed on a piece.
                        // TODO: If pressed on possible move, update game_state
                        /*
            TODO: if pressed second time, check if allowed, and move piece,
            change gamestate::game_state array. set event_loop_done = true
            otherwise event_loop_done = false, so there is no need to update the pieces on the table
            if nothing has moved.
            */
                        event_loop_done = SDL_TRUE;
                    }
                    else if (handle_reset_click(event.button.x, event.button.y, reset, first_player))
                        event_loop_done = SDL_TRUE;
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
    // Menu screen
    if (x >= 640 && x <= 1000 && y >= 0 && y <= 640)
    {
        if (check_button_press(x, y, 700, 290, 140, 60))
            reset = SDL_TRUE;
    }
    else
    {
        // Rectangle position from 0 - 7
        rect_x = x / 80;
        rect_y = y / 80;
    }
    std::cout << rect_x << " : " << rect_y << std::endl;
    std::cout << x << " : " << y << std::endl;
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