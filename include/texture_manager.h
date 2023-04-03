#if !defined(TEXTURE_MANAGER_H)
#define TEXTURE_MANAGER_H

#include <string>
#include <vector>
#include <SDL2/SDL.h>

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