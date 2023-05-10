#pragma once
#include "unit.hpp"
// #include "barry.hpp"
#include "fx.hpp"
#include "Killers.hpp"


class WreakingBall:public Killers, public Unit{

    SDL_Rect src, mover;
    int frame=0;  //to control the animations
    // bool bowling_on=true;  //to stop the WreakingBall from moving after it has locked on
    bool warning_sign=false;  //to display/stop displaying the warning sign
    int timer=0;  
    int frame_speed = 9;  //to control the wreaking ball rolling speed

    public:
    WreakingBall(SDL_Renderer* rend, SDL_Texture* ast, SDL_Rect mov); //constructor
    void draw();  //draw function
    bool collision(int barry_x, int barry_y) override;  //overided collision function
    
    void animation();  //fucntion to animate the object
    
    bool delete_item() override;  //overided fucntion
    FX launch_s;  //sound class object
    void launch_sound();  //launch sound function that plays the sound
    
    ~WreakingBall();   //destructor


};