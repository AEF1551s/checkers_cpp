#if !defined(GAME_BOARD_H)
#define GAME_BOARD_H

#include <SDL2/SDL.h>
#include "texture_manager.h"
#include "game_manager.h"
#include "game_state.h"

// Renders game pieces based on game_state
class game_board
{
private:
    SDL_Window *window;
    SDL_Renderer *renderer;

    static SDL_Texture *texture_black, *texture_black_q,
        *texture_white, *texture_white_q;

public:
    game_board(SDL_Window &window, SDL_Renderer &renderer);
    void render_game_state();
    void load_textures();
};

#endif // GAME_BOARD_H
