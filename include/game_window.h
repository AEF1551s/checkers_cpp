#if !defined(GAME_WINDOW_H)
#define GAME_WINDOW_H

#include <SDL2/SDL.h>
#include <texture_manager.h>

// Renders main game window, checkered board, menu screen.
class game_window
{
private:
    SDL_Window *window;
    SDL_Renderer *renderer;

    static SDL_Texture *texture_reset_button, *texture_first_player_button,
        *texture_second_player_button, *texture_you_lost, *texture_you_won;

    int first_player_button_x, first_player_button_y, first_player_button_h, first_player_button_w;

public:
    game_window(SDL_Window &window, SDL_Renderer &renderer);
    void draw_board(bool first_player);
    void reset();
    void load_textures();
    ~game_window();
};
#endif // GAME_WINDOW_Hs
