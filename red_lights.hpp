#pragma once
#include "unit.hpp"
#include "Background_Elements.hpp"

class RedLights:public Unit, public Background_Elements{

    SDL_Rect src, mover;
    int frame=0;   //to animate the RedLights
    int frame_speed=7;  //to control the speed of animation
    public:
    RedLights(SDL_Renderer* rend, SDL_Texture* ast, SDL_Rect mov);  //constructor
    void draw();  //draw the RedLights
    
    void animation();  //animate the RedLights
    ~RedLights(); //destructor
    bool delete_item() override;
    
};