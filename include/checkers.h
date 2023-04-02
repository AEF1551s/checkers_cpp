#if !defined(CHECKERS_H_INCLUDED)
#define CHECKERS_H_INCLUDED

#include <SDL2/SDL.h>

class checkers
{
private:
    SDL_Window *window;
    SDL_Renderer *renderer;

    static const SDL_Texture *texture_black, *texture_black_q,
        *texture_white, *texture_white_q;

    int game_state[8][8];

public:
    checkers(SDL_Window *window, SDL_Renderer *renderer);
    void load_textures();
    //TODO: Show possible moves with green overlay
};

#endif // CHECKERS_H_INCLUDED
