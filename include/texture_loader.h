#if !defined(TEXTURE_LOADER_H)
#define TEXTURE_LOADER_H

#include <string>
#include <vector>
#include <SDL2/SDL.h>

class texture_loader
{
private:
    static std::vector<SDL_Texture *> list_textures_loaded;
    static const std::string ASSETS_PATH;

public:
    static SDL_Texture *load_texture(std::string filename, SDL_Renderer *renderer);
    static void deallocate_textures();
    
};

#endif // TEXTURE_LOADER_H