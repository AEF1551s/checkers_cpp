#if !defined(GAME_H_INCLUDED)
#define GAME_H_INCLUDED
#include <SDL2/SDL.h>

class game
{
private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    int size_x, size_y;
    int pos_xy[2], rect_xy[2];

public:
    game(int size_x, int size_y);
    void init();
    void draw_board(bool first_player);
    void events();
};

#endif // GAME_H_INCLUDED
