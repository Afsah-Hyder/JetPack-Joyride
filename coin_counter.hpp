#pragma once
#include "unit.hpp"
// #include "barry.hpp"

// #include "Killers.hpp"


class CoinCounter:public Unit{

    SDL_Rect src, mover;
    int frame=0;
    
    
    public:
    CoinCounter(SDL_Renderer* rend, SDL_Texture* ast, SDL_Rect mov);
    void draw();
    bool trigger=false;
    int counter=0;
    // int zapper_x = mover.x;
    // int barry_y;
    // void collision(int barry_x, int barry_y) override;
    
    // void animation();
    ~CoinCounter();
    void operator++();
    // bool delete_item() override;


};