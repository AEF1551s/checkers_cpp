#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "game.h"

int main(int argc, char *argv[]) {

    game game(640, 640);

    game.init();
    game.draw_board();
    game.loop();
    

    return 0;
}