#include "ZapperV.hpp"    

#include <iostream>
#include "JetpackJoyride.hpp"
using namespace std;

Zapper_v::Zapper_v(SDL_Renderer* rend, SDL_Texture* ast, SDL_Rect mov):  Unit(rend, ast), mover(mov){
    cout<<"Zapper created"<<endl;
    src = {10,227, 73, 199};    //constructor, calls the parent class constructor and saves data to its own attributes too
}

void Zapper_v::draw(){
    Unit::draw(src, mover); 
    
    mover.x -=4;
    animation();
    frame++;
}

void Zapper_v::collision(int barry_x, int barry_y){
    if (barry_y>mover.y-10 and barry_y<(mover.y+mover.h+10)){
        if ((barry_x<mover.x+(mover.w/2))and (barry_x>mover.x-(mover.w/2))){
            cout<<"Barry collided vertical zapper"<<endl;
        }
    }
}

Zapper_v::~Zapper_v(){
    cout<<"Vertical Zapper destroyed"<<endl;
}

bool Zapper_v::delete_item(){
    if (mover.x < -150){
        return true;
    }

    else{
    return false;
    }
}

void Zapper_v::animation(){
    if (frame==1*frame_speed){
        src = {10,227, 73, 199};
    }

    else if (frame==2*frame_speed){
        src = {323,236,70,190};
        frame=0;
    }
}