#pragma once
#include "unit.hpp"
#include "Background_Elements.hpp"

class Scientist:public Unit, public Background_Elements{

    SDL_Rect src, mover;
    int frame=0;   //to animate the scientist
    int frame_speed=10;  //to control the speed of animation
    public:
    Scientist(SDL_Renderer* rend, SDL_Texture* ast, SDL_Rect mov);  //constructor
    void draw();  //draw the scientist
    
    void animation();  //animate the scientist
    ~Scientist(); //destructor
    bool delete_item() override;
};