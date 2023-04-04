#if !defined(GAME_MANAGER_H)
#define GAME_MANAGER_H

// #include "templates.h"
#include <SDL2/SDL.h>

#include "game_window.h"
#include "event_manager.h"
#include "game_board.h"
// #include "game_state.h"

//Manages the game_loop
//TODO: Update game_state based on played mode
class game_manager
{
private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    static int game_state[8][8];
public:
    game_manager(SDL_Window &window, SDL_Renderer &renderer);
    // void init_game_state(bool first_player);
    void game_loop();
};


#endif // GAME_MANAGER_H
