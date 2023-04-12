// #include "Unit.hpp"
#pragma once

class Collectables{            //parent class, all the types of collectables will be child classes
    // SDL_Rect src, mover;
    public:
    // Collectables(SDL_Renderer* rend, SDL_Texture* ast, SDL_Rect mov);
    Collectables();
    virtual void draw()=0;
    virtual bool collision(int barry_x, int barry_y)=0;
    virtual bool coin_delete()=0;
    
};