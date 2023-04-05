// Make composition of TankBody and TankTurret objects in Tank class
#pragma once
#include "Tank_turret.hpp"
#include "Tank_body.hpp"
#include "Unit.hpp"
// #include "Bullet.hpp"
// #include <list>
using namespace std;

class Tank:public Unit{
    SDL_Rect src, mover;
    int count;
    public:
   
    Tank_body* tb;
   

    Tank_turret* tt;
    Tank(SDL_Renderer* rend, SDL_Texture* ast, SDL_Rect mov);
    

    void draw();
    int tank_x_pos();
    int tank_y_pos();
    void fire();



};
