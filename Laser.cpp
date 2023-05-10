#include "Laser.hpp"
#include <iostream>
// #include "JetpackJoyride.hpp"
using namespace std;

Lasers::Lasers(SDL_Renderer *rend, SDL_Texture *ast, SDL_Rect mov) : Unit(rend, ast), mover(mov)
{
    // cout << "laser created" << endl;
    src = {255, 545, 405, 45};  //selecting the image from asset file
    mover.h=mover.h+20;  //resizing the laser
    sound.initialize();  //initialize the sound object
    sound.load();   //load the sound files
}

void Lasers::draw()
{
    Unit::draw(src, mover);
  
    if (time_to_fire<500){   //before the laser has started
        time_to_fire++;   //increment the time
        sound.effect('w');  //laser charging sound effect
    }

    if (time_to_fire>=500){  //after the timer has recahed 500
        animation();  //start animating the laser
        frame++; 
        running_time++;
        
    }
}

bool Lasers::collision(int barry_x, int barry_y)
{   if (running_time!=0){


    //conditions for collision
    if (barry_x > mover.x - 100 && barry_x < (mover.x + mover.w + 100))
    {
        if ((barry_y < mover.y + (mover.h / 2)) && (barry_y > mover.y - (mover.h / 2)))
        {
            // cout << "Barry collided with the laser" << endl;
            return true;  //barry has collided with the laser
        }
    }
    }
    return false;  //barry has not collided
}

Lasers::~Lasers()  //destructor
{
    // cout << "Laser destroyed" << endl;
}

bool Lasers::delete_item()
{   
    //if the laser has run for a long time
    if (running_time>=370){  //to start the laser
    return true;
    }
    else{
    return false;}
}

void Lasers::animation()
{   sound.effect('l');  //play the laser sound
    

    if (frame == 1 * frame_speed)
    {
        src = {263, 440, 386, 40}; //selecting the image from asset file
    }
    else if (frame == 2 * frame_speed)
    {
        src = {263, 496, 383, 38}; //selecting the image from asset file
        frame = 1;
    }
}

