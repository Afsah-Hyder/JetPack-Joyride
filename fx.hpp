#pragma once
#include <SDL.h>
#include <SDL_mixer.h>

class FX{
    Mix_Music *bgMusic = NULL;
    Mix_Music *menuMusic=NULL;
    Mix_Chunk *jetpack = NULL;
    Mix_Chunk *zapped = NULL;
    Mix_Chunk *coin = NULL;
    Mix_Chunk *missile = NULL;
    // Mix_Chunk *stomp = NULL;

public:
    
    void initialize();
    void load();
    void destroy();
    void effect(char);

};