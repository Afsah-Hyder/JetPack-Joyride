#pragma once
#include "unit.hpp"
#include "barry.hpp"
#include "fx.hpp"
#include "Killers.hpp"


class WreakingBall:public Killers, public Unit{

    SDL_Rect src, mover;
    int frame=0;
    bool bowling_on=true;  //to stop the WreakingBall from moving after it has locked on
    bool warning_sign=false;
    int timer=0;
    int frame_speed = 10;

    public:
    WreakingBall(SDL_Renderer* rend, SDL_Texture* ast, SDL_Rect mov);

    void draw();
    bool collision(int barry_x, int barry_y) override;
    
    void animation();
    
    bool delete_item() override;
    FX launch_s;
    void launch_sound();
    
    ~WreakingBall();


};