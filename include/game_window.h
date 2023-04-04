#if !defined(GAME_WINDOW_H)
#define GAME_WINDOW_H

#include <SDL2/SDL.h>

// Renders main game window, checkered board, menu screen.
class game_window
{
private:
    SDL_Window *window;
    SDL_Renderer *renderer;

public:
    game_window(SDL_Window &window, SDL_Renderer &renderer);
    void draw_board(bool first_player);
    ~game_window();
};
#endif // GAME_WINDOW_H
