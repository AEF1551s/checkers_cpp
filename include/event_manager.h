#if !defined(event_manager_H)
#define event_manager_H

#include <vector>
#include <SDL2/SDL.h>
#include "game_state.h"
#include "ai.h"

class event_manager
{
private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    ai ai_player;

    std::vector<std::pair<int, int>> moves;
    int rect_x, rect_y;
    int pos_x, pos_y;
    int next_x, next_y;
    int prev_x, prev_y;
    bool first_click_on_piece;
    bool player_move;

public:
    event_manager(SDL_Window &window, SDL_Renderer &renderer, bool &player_move, ai &ai_player);
    void events(SDL_bool &done);
    void events(SDL_bool &done, SDL_bool &reset);
    void events(SDL_bool &done, SDL_bool &reset, bool &first_player);
    void handle_click(int x, int y, SDL_bool &reset);
    void possible_moves(bool first_player);
//TODO: check for consecutive moves
    void check_consecutive_jumps(int x, int y, int dx, int dy, int opponent);
    bool check_if_clicked_piece();
    bool check_if_possible_move();
    bool handle_reset_click(int x, int y, SDL_bool &reset, bool &first_player);
    bool check_button_press(int mouse_x, int mouse_y, int x, int y, int w, int h);
};

#endif // event_manager_H
