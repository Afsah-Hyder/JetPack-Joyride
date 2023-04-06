#include "Unit.hpp"
#pragma once

class Barry: public Unit{
    SDL_Rect src, mover;
    public:
    int gravity=3;
    bool drop=0;
    int frames;
    int frame_speed=7;
    Barry(SDL_Renderer* rend, SDL_Texture* ast, SDL_Rect mov);
    void draw();
    void running();
    void flying();
    void falling();
    void move_up();
    void move_down();
    
};