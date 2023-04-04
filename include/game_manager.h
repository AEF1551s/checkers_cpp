#if !defined(GAME_MANAGER_H)
#define GAME_MANAGER_H

#include "templates.h"
#include <SDL2/SDL.h>

class game_manager
{
private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    static int game_state[8][8];
public:
    game_manager(SDL_Window &window, SDL_Renderer &renderer);
    void init_game_state(bool first_player);
    void game_loop();
};


#endif // GAME_MANAGER_H