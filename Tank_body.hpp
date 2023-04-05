#include "Unit.hpp"
#pragma once
class Tank_body:public Unit{
    SDL_Rect src, mover;
    public:

    Tank_body(SDL_Renderer* rend, SDL_Texture* ast, SDL_Rect mov);  //constructor for the tank body

    void draw();  //to draw the tank
    




};