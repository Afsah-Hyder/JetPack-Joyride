#include "Unit.hpp"
#pragma once

class obstacles: public Unit{            //parent class, all the types of obstacles will be child classes
    SDL_Rect src, mover;
    public:
    obstacles(SDL_Renderer* rend, SDL_Texture* ast, SDL_Rect mov);
    void draw();
    
};