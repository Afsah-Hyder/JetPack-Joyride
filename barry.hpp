#include "Unit.hpp"
#pragma once

class Barry: public Unit{
    SDL_Rect src, mover;
    public:
    Barry(SDL_Renderer* rend, SDL_Texture* ast, SDL_Rect mov);
    void draw();
    
};