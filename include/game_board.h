#if !defined(GAME_BOARD_H)
#define GAME_BOARD_H

#include <SDL2/SDL.h>

// Renders game pieces based on game_state
// TODO: Show possible moves when pressed on game piece
class game_board
{
private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    static int game_state[8][8];

public:
    game_board(SDL_Window &window, SDL_Renderer &renderer);
    void render_game_state();
};

#endif // GAME_BOARD_H
