#include "Unit.hpp"
#pragma once

class Barry: public Unit{
    SDL_Rect src, mover;
    public:
    int gravity=3;
    bool drop=0;
    int frames;
    int frame_speed=7;
    int rise=3;
    int score=0;
    Barry(SDL_Renderer* rend, SDL_Texture* ast, SDL_Rect mov);
    int barry_y_pos();
    int barry_x_pos();
    void draw();
    void running();
    void flying();
    void falling();
    void move_up();
    void move_down();
    
};