#include "event_manager.h"

event_manager::event_manager()
{
}

void event_manager::events(SDL_bool &done)
{
    done = SDL_FALSE;
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            done = SDL_TRUE;
            break;

        case SDL_MOUSEBUTTONDOWN:
            if (event.button.button == SDL_BUTTON_LEFT)
            {
                handle_click(event.button.x, event.button.y);
                //TODO: Show possible moves, if pressed on a piece.
                //TODO: If pressed on possible move, update game_state
            }
            break;
            // TODO: Add button to reset, quit, change first player
        default:
            break;
        }
    }
}

void event_manager::handle_click(int x, int y)
{
    // Relative position to window
    pos_x = x;
    pos_y = y;

    // Rectangle position from 0 - 7
    if (pos_x >= 640 || pos_y >= 640)
    {
        // handle menu screen stuff
    }
    else
    {
        rect_x = pos_x / 80;
        rect_y = pos_y / 80;
    }
}