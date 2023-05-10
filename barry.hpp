#include "Unit.hpp"
#pragma once

class Barry: public Unit{
    SDL_Rect src, mover;
    
    int gravity=3;
     //do not change
    int frames;
    int frame_speed=7;
    int die_frame_speed=10;
    

    int rise=3;  //jetpack thrust
    public:
    int score=0;
    bool drop=0;
    Barry(SDL_Renderer* rend, SDL_Texture* ast, SDL_Rect mov);
    int barry_y_pos();
    int barry_x_pos();
    void draw();
    void running();
    void flying();
    void move_down();
    bool death=false;
    void die();
};