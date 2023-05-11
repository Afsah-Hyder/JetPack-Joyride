#pragma once
#include "unit.hpp"
// #include "barry.hpp"

// #include "Killers.hpp"


class ScoreCounter:public Unit{

    SDL_Rect src, mover;
    int frame=0;
    
    
    public:
    int counter=0;
    ScoreCounter(SDL_Renderer* rend, SDL_Texture* ast, SDL_Rect mov, int cnt=0);
    void draw();
    bool trigger=false;
 
    ~ScoreCounter();
    void operator++();
    void reposition(int x, int y);
};