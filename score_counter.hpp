#pragma once
#include "unit.hpp"
// #include "barry.hpp"

// #include "Killers.hpp"


class ScoreCounter:public Unit{

    SDL_Rect src, mover;
    int frame=0;
    int counter=0;
    
    public:
    ScoreCounter(SDL_Renderer* rend, SDL_Texture* ast, SDL_Rect mov, int cnt=0);
    void draw();
    bool trigger=false;
    // int zapper_x = mover.x;
    // int barry_y;
    // void collision(int barry_x, int barry_y) override;
    
    // void animation();
    ~ScoreCounter();
    void operator++();
    void reposition(int x, int y);
    // bool delete_item() override;


};