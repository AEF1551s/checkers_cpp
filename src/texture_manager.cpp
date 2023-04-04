#include "texture_manager.h"
#include <iostream>

std::vector<SDL_Texture *> texture_manager::list_textures_loaded;
const std::string texture_manager::ASSETS_PATH = "assets/";

SDL_Texture *texture_manager::load_texture(std::string filename, SDL_Renderer *renderer)
{
    /*
    Base path: /home/roboros/Documents/checkers_cpp/build
    Needed path /home/roboros/Documents/checkers_cpp   /assets
    */
    const std::string project_path = "/home/roboros/Documents/checkers_cpp/";

    // Setup the relative file_path to the images folder using the input filename.
    std::string file_path = project_path + ASSETS_PATH + filename;

    // Try to create a surface using the file_path.
    SDL_Surface *surface_temp = SDL_LoadBMP(file_path.c_str());
    if (surface_temp != nullptr)
    {
        // The surface was created successfully so attempt to create a texture with it.
        SDL_Texture *texture_output = SDL_CreateTextureFromSurface(renderer, surface_temp);
        // Free the surface because it's no longer needed.
        SDL_FreeSurface(surface_temp);

        if (texture_output != nullptr)
        {
            // Enable transparency for the texture.
            SDL_SetTextureBlendMode(texture_output, SDL_BLENDMODE_BLEND);
            
            // Add the texture to the list of loaded textures to keep track of it for clean-up purposes.
            list_textures_loaded.push_back(texture_output);
            return texture_output;

        }
    }
    throw std::invalid_argument("could not load texture in texture_manager.cpp");
    return nullptr;
}

void texture_manager::deallocate_textures()
{
    // Destroy all the textures on the list.
    while (list_textures_loaded.size() > 0)
    {
        if (list_textures_loaded[0] != nullptr)
            SDL_DestroyTexture(list_textures_loaded[0]);

        list_textures_loaded.erase(list_textures_loaded.begin());
    }
}