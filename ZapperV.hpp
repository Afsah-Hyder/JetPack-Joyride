#pragma once
#include "unit.hpp"
#include "barry.hpp"
#include "Killers.hpp"


class Zapper_v:public Killers, public Unit{

    SDL_Rect src, mover;
    int frame=0;
    public:
    Zapper_v(SDL_Renderer* rend, SDL_Texture* ast, SDL_Rect mov);
    void draw();
    int zapper_x = mover.x;
    bool collision(int barry_x, int barry_y) override;
    void animation();
    ~Zapper_v();
    bool delete_item() override;
};