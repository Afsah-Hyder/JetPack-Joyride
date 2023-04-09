#include "Zapper.hpp"    

#include <iostream>
#include "JetpackJoyride.hpp"
using namespace std;

Zapper::Zapper(SDL_Renderer* rend, SDL_Texture* ast, SDL_Rect mov):  Unit(rend, ast), mover(mov){
    cout<<"Zapper created"<<endl;
    src = {0,445, 223, 72};    //constructor, calls the parent class constructor and saves data to its own attributes too
}

void Zapper::draw(){
    Unit::draw(src, mover); 
    
    mover.x -=4;
    animation();
    frame++;
}

void Zapper::collision(int barry_x, int barry_y){
    // int character_x = Barry::barry_x_pos();
    // int character_y = Barry::barry_y_pos();

    if (barry_x>mover.x-10 and barry_x<(mover.x+mover.w+10)){
        if ((barry_y<mover.y+(mover.h/2))and (barry_y>mover.y-(mover.h/2))){
            cout<<"Barry collided"<<endl;
        }
    }
}

Zapper::~Zapper(){
    cout<<"Zapper destroyed"<<endl;
}

bool Zapper::zapper_delete(){
    if (mover.x < -150){
        return true;
    }

    else{
    return false;
    }
}

void Zapper::animation(){
    if (frame==1*frame_speed){
        src = {0,445, 223, 72};
        // SDL_Delay(40);
        // frames++;
    }

    else if (frame==2*frame_speed){
        src = {1,520,223,80};
        // SDL_Delay(40);
        frame=0;
    }
}