#include "Unit.hpp"
#pragma once
class Bullet: public Unit{
    SDL_Rect src, mover;
    
    public:
    int frame=0;  //variable to keep track of the frames of the bullet
    bool bullet_enable=false; //to allow the bullet to move
    // bool destroy=false; 
    Bullet(SDL_Renderer* rend, SDL_Texture* ast, SDL_Rect mov);

    ~Bullet();  //destructor for the bullet
    void draw();  //draw function
    void fire(); //function that moves the bullet
    bool bullet_remove();

    
};