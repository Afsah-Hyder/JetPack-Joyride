#pragma once
#include "unit.hpp"
// #include "barry.hpp"
#include "Background_Elements.hpp"
// #include "Killers.hpp"


class Scientist:public Unit, public Background_Elements{

    SDL_Rect src, mover;
    int frame=0;
    int frame_speed=10;
    public:
    Scientist(SDL_Renderer* rend, SDL_Texture* ast, SDL_Rect mov);
    void draw();
    
    // int zapper_x = mover.x;
    // int barry_y;
    // bool collision(int barry_x, int barry_y) override;
    
    void animation();
    ~Scientist();
    // bool delete_item() override;


};