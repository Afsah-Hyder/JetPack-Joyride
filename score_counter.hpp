#pragma once
#include "unit.hpp"
// #include "barry.hpp"

// #include "Killers.hpp"


class ScoreCounter:public Unit{

    SDL_Rect src, mover;
    int frame=0;
    
    
    public:
    int counter=0;
    ScoreCounter(SDL_Renderer* rend, SDL_Texture* ast, SDL_Rect mov, int cnt=0); //constructor
    void draw();  //draw function
    bool trigger=false;  
 
    ~ScoreCounter();
    void operator++();  //overloaded preincrement operator
    void reposition(int x, int y);  //to reposition the score counters to the middle of the screen
};