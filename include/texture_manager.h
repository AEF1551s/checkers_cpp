#if !defined(TEXTURE_MANAGER_H)
#define TEXTURE_MANAGER_H

#include <string>
#include <vector>
#include <SDL2/SDL.h>

//Loads .bmp images as textures and saves them in list_textures_loaded and return the current texture for use.
class texture_manager
{
private:
    static std::vector<SDL_Texture *> list_textures_loaded;
    static const std::string ASSETS_PATH;

public:
    static SDL_Texture *load_texture(std::string filename, SDL_Renderer *renderer);
    static void deallocate_textures();
    
};

#endif // TEXTURE_MANAGER_H