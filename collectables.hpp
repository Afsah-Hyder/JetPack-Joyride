#include "Unit.hpp"
#pragma once

class Collectables: public Unit{            //parent class, all the types of collectables will be child classes
    SDL_Rect src, mover;
    public:
    Collectables(SDL_Renderer* rend, SDL_Texture* ast, SDL_Rect mov);
    void draw();
    
};