#pragma once
#include "unit.hpp"
#include "barry.hpp"

#include "Killers.hpp"


class Zapper_h:public Killers, public Unit{
    SDL_Rect src, mover;
    int frame=0;
    public:
    Zapper_h(SDL_Renderer* rend, SDL_Texture* ast, SDL_Rect mov);
    void draw();
    int zapper_x = mover.x;
    bool collision(int barry_x, int barry_y) override;
    void animation();
    ~Zapper_h();
    bool delete_item() override;
};