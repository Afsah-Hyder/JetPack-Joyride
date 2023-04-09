#pragma once
#include "unit.hpp"
#include "barry.hpp"

#include "Killers.hpp"


class Zapper:public Killers, public Unit{

    SDL_Rect src, mover;
    int frame=0;
    int frame_speed=6;
    public:
    Zapper(SDL_Renderer* rend, SDL_Texture* ast, SDL_Rect mov);
    void draw();
    
    int zapper_x = mover.x;
    // int barry_y;
    void collision(int barry_x, int barry_y) override;
    
    void animation();
    ~Zapper();
    bool zapper_delete() override;


};