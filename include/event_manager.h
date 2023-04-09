#if !defined(event_manager_H)
#define event_manager_H

#include <vector>
#include <SDL2/SDL.h>
#include "game_state.h"

class event_manager
{
private:
    SDL_Window *window;
    SDL_Renderer *renderer;

    int rect_x, rect_y;
    int pos_x, pos_y;

public:
    event_manager(SDL_Window &window, SDL_Renderer &renderer);
    void events(SDL_bool &done);
    void events(SDL_bool &done, SDL_bool &reset);
    void events(SDL_bool &done, SDL_bool &reset, bool &first_player);
    void handle_click(int x, int y, SDL_bool &reset);
    void possible_moves();
    bool check_if_clicked_piece();
    bool handle_reset_click(int x, int y, SDL_bool &reset, bool &first_player);
    bool check_button_press(int mouse_x, int mouse_y, int x, int y, int w, int h);
};

#endif // event_manager_H
