#include "Laser.hpp"
#include <iostream>
#include "JetpackJoyride.hpp"
using namespace std;

Lasers::Lasers(SDL_Renderer *rend, SDL_Texture *ast, SDL_Rect mov) : Unit(rend, ast), mover(mov)
{
    cout << "laser created" << endl;
    src = {255, 545, 405, 45};
    mover.h=mover.h+20;
    sound.initialize();
    sound.load();
}

void Lasers::draw()
{
    Unit::draw(src, mover);
    // mover.x -= 2;
    // animation();
    if (time_to_fire<500){
        time_to_fire++;
        sound.effect('w');
    }
    // time_to_fire++;
    if (time_to_fire>=500){
        animation();
        frame++;
        running_time++;
        // cout<<"Laser running for: "<<running_time<<endl;
    }
}

bool Lasers::collision(int barry_x, int barry_y)
{   if (running_time!=0){
    if (barry_x > mover.x - 100 && barry_x < (mover.x + mover.w + 100))
    {
        if ((barry_y < mover.y + (mover.h / 2)) && (barry_y > mover.y - (mover.h / 2)))
        {
            cout << "Barry collided with the laser" << endl;
            return true;
        }
    }
    }
    return false;
}

Lasers::~Lasers()
{
    cout << "Laser destroyed" << endl;
}

bool Lasers::delete_item()
{   
    if (running_time>=400){
    return true;
    }
    else{
    return false;}
}

void Lasers::animation()
{   sound.effect('l');
    

    if (frame == 1 * frame_speed)
    {
        src = {260, 440, 397, 35};
    }
    else if (frame == 2 * frame_speed)
    {
        src = {260, 496, 395, 35};
        frame = 1;
    }
}

