#pragma once
#include "unit.hpp"
#include "fx.hpp"
#include "Killers.hpp"


class Missile:public Killers, public Unit{

    SDL_Rect src, mover;
    int frame=0;
    bool seeking_on=true;  //to stop the missile from moving after it has locked on
    bool warning_sign=false;  //to control the appearance of the warning sign
    int timer=0;  //to time how long the warning symbol appears
    int frame_speed = 6;  //to control the speed of the bullet animations

    public:
    Missile(SDL_Renderer* rend, SDL_Texture* ast, SDL_Rect mov);  //constructor

    void draw();  //to draw the object
    
    bool collision(int barry_x, int barry_y) override;  //to check for collisions with barry
    
    void animation();  //to animate the missile
    
    bool delete_item() override;  //overided delete item function
    void position_seeker(int barry_x, int barry_y);  //function to seek barry's position
    FX launch_s;  //a sound class object
    void launch_sound();
    
    ~Missile();  //destructor


};