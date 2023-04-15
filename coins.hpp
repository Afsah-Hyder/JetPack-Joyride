#pragma once
#include "unit.hpp"
#include "barry.hpp"
#include "collectables.hpp"

class Coins: public Collectables,public Unit{
    SDL_Rect src, mover;
    int frame=0;
    int frame_speed=9;
    bool coll_check=false;
    bool invisible=false;
    public:
    Coins(SDL_Renderer* rend, SDL_Texture* ast, SDL_Rect mov);
    void draw();
    // void disappear();
    bool collision(int barry_x, int barry_y) override;
    void animation();
    bool coin_delete() override;
    bool collected=false;
    ~Coins();
};