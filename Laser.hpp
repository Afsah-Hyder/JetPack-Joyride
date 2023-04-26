#pragma once
#include "unit.hpp"
#include "barry.hpp"
#include "fx.hpp"
#include "Killers.hpp"

class Lasers:public Killers, public Unit
{
    SDL_Rect src, mover;
    int frame = 0;
    int time_to_fire=0;
    bool deleter=false;
    int running_time=0;
    public:
    Lasers(SDL_Renderer* rend, SDL_Texture* ast, SDL_Rect mov);
    void draw();

    int laser_x = mover.x;

    bool collision(int barry_x, int barry_y) override;

    void animation();

    ~Lasers();
    FX sound;
    bool delete_item() override;
};