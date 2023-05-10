#pragma once
#include "unit.hpp"
// #include "barry.hpp"
#include "collectables.hpp"

class Coins: public Collectables,public Unit{
    SDL_Rect src, mover;
    int frame=0;  //to animate the coins
    int frame_speed=9;  //coin animation soeed
    bool coll_check=false;
    bool invisible=false;  //to make the coin disappear upon collision
    bool collect_once_only=false;  //to ensure each coin is collected once only
    public:
    Coins(SDL_Renderer* rend, SDL_Texture* ast, SDL_Rect mov);  //constructor
    void draw(); //to draw the object on the screen

    int collision(int barry_x, int barry_y) override;  //overided collision function
    void animation();  //to animate the coins
    bool coin_delete() override;  //overided delete function
    ~Coins();
};