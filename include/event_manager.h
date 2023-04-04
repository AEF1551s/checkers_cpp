#if !defined(event_manager_H)
#define event_manager_H

#include <SDL2/SDL.h>

class event_manager
{
private:
    int pos_x, pos_y;
    int rect_x, rect_y;
    
public:
    event_manager(/* args */);
    void events(SDL_bool &done);
    void handle_click(int x, int y);
};




#endif // event_manager_H
