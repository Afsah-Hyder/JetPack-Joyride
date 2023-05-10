#pragma once
#include "unit.hpp"
// #include "barry.hpp"
#include "fx.hpp"
#include "Killers.hpp"

class Lasers:public Killers, public Unit
{
    SDL_Rect src, mover;
    int frame = 0;   //to animate the laser
    int time_to_fire=0;  //count to when the laser will start 
    int running_time=0;  //to count the time the laser has been running for
    public:
    Lasers(SDL_Renderer* rend, SDL_Texture* ast, SDL_Rect mov);
    void draw();  //to draw the laser

    int laser_x = mover.x;

    bool collision(int barry_x, int barry_y) override;  //overided collision function

    void animation(); //to animate the laser
    ~Lasers();  //destructor
    FX sound;  //sound class object
    bool delete_item() override;  //overided delete function
};