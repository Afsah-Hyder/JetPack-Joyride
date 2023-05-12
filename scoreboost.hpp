#pragma once
#include "unit.hpp"
#include "barry.hpp"
#include "collectables.hpp"


class Score_booster:public Collectables, public Unit{
    SDL_Rect src, mover;
    int frame=0; //frame controller
    int frame_speed=14;  //to control how fast the frames change. The higher the slower
    bool coll_check=false;  //collision checker
    bool invisible=false; //to make the coin disppear after it is collected
    bool collect_once_only=false;  //so that each coin is collected once only
    int up_down_movt=2;
    int direction;
    public:
    Score_booster(SDL_Renderer* rend, SDL_Texture* ast, SDL_Rect mov);
    void draw();
    int collision(int barry_x, int barry_y) override;
    void animation();
    bool coin_delete() override;
    bool collected=false;
    ~Score_booster();
    

};