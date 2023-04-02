#include "game.h"
#include "templates.cpp"
#include <iostream>

int game::game_state[8][8];

game::game(SDL_Window *window, SDL_Renderer *renderer)
{
    this->renderer = renderer;
    this->window = window;
}

void game::init_game_state(bool first_player)
{
    init_game_state_templ<true>(game_state);
}

void game::draw_board(bool first_player)
{
    if (first_player)
    {
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    }
    else
    {
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    }

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if ((i + j) % 2 == 0)
            {
                SDL_Rect rect = {i * 80, j * 80, 80, 80};
                SDL_RenderFillRect(renderer, &rect);
            }
        }
    }

    // Right menu screen
    SDL_SetRenderDrawColor(renderer, 0, 102, 0, 255);
    SDL_Rect menu_rect = {640, 0, 360, 640};
    SDL_RenderFillRect(renderer, &menu_rect);

    SDL_RenderPresent(renderer);
}

void game::render_game_state()
{
    // TODO: Draw piecies based on game_state
}

void game::game_loop()
{
    // Game loop
    SDL_bool done = SDL_FALSE;
    init_game_state(true);
    while (!done)
    {
        // Gets input from mouse to rect_xy
        events(done);
        render_game_state();
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void game::events(SDL_bool &done)
{

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
                // Relative position to window
                pos_xy[0] = event.button.x;
                pos_xy[1] = event.button.y;

                // Rectangle position from 0 - 7
                if (pos_xy[0] >= 640 || pos_xy[1] >= 640)
                    break; // if in menu screen

                rect_xy[0] = pos_xy[0] / 80;
                rect_xy[1] = pos_xy[1] / 80;

                /*
                If press is on piece, run method checkers::show_possible_moves,
                if next press is on valid next move, then update game_state to current
                */

                // TODO: Add button to reset, quit, change first player
            }
        default:
            break;
        }
    }
}