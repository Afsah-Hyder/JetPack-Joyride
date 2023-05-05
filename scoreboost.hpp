#pragma once
#include "unit.hpp"
#include "barry.hpp"
#include "collectables.hpp"


class Score_booster:public Collectables, public Unit{
    SDL_Rect src, mover;
    int frame=0;
    int frame_speed=16;
    bool coll_check=false;
    bool invisible=false;
    bool collect_once_only=false;
    public:
    Score_booster(SDL_Renderer* rend, SDL_Texture* ast, SDL_Rect mov);
    void draw();
    bool collision(int barry_x, int barry_y) override;
    void animation();
    bool coin_delete() override;
    bool collected=false;
    ~Score_booster();
    

};