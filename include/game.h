#if !defined(GAME_H_INCLUDED)
#define GAME_H_INCLUDED
#include <SDL2/SDL.h>
#include "checkers.h"

class game
{
private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    int pos_xy[2], rect_xy[2];
    static int game_state[8][8];

public:
    game(SDL_Window *window, SDL_Renderer *renderer);
    void init_game_state(bool first_player);
    void draw_board(bool first_player);
    void render_game_state(); //TODO: Render all pieces on board based on game_state
    void events(SDL_bool &done);
    void game_loop();
};

#endif // GAME_H_INCLUDED
