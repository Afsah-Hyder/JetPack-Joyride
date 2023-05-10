#include "ZapperV.hpp"    

#include <iostream>
#include "JetpackJoyride.hpp"
using namespace std;

Zapper_v::Zapper_v(SDL_Renderer* rend, SDL_Texture* ast, SDL_Rect mov):  Unit(rend, ast), mover(mov){
    cout<<"Zapper created"<<endl;
    src = {10,227, 73, 199};    //constructor, calls the parent class constructor and saves data to its own attributes too
}

void Zapper_v::draw(){
    Unit::draw(src, mover);         //draws the zapper every time for a new frame
    
    mover.x -=4;                    // zapper moves 4 units to the left each time it is drawn
    animation();
    frame++;                        //frame incremented
}       

bool Zapper_v::collision(int barry_x, int barry_y){
    if (barry_y>mover.y-5 and barry_y<(mover.y+mover.h+5)){
    //if barry y coordinated lie within the height of the zapper with +- 5 units uncertainity
        if ((barry_x<mover.x+(mover.w/2))and (barry_x>mover.x-(mover.w/2))){
             //and barry x coordinated lie within the width of the zapper 
            cout<<"Barry collided vertical zapper"<<endl;    //then Barry has collided with the zapper
            return true;
        }
    }
    return false;
}

Zapper_v::~Zapper_v(){
    cout<<"Vertical Zapper destroyed"<<endl;       //destructor
}

bool Zapper_v::delete_item(){
    if (mover.x < -150){        //if x-coordinate of zapper is less than -150, that is it has moved out of the screen
        return true;              //then it needs to be deleted
    }

    else{
    return false;
    }
}

void Zapper_v::animation(){
    if (frame==1*frame_speed){
        src = {18,234, 55, 185};    //selecting the image from asset file
    }

    else if (frame==2*frame_speed){
        src = {123,234, 55, 185};   //selecting the image from asset file
        // frame=0;
    }

    else if (frame==3*frame_speed){
        src = {230,234, 55, 185};   //selecting the image from asset file
        // frame=0;
    }
    else if (frame==4*frame_speed){
        src = {336,234, 55, 185};   //selecting the image from asset file
        frame=0;            //set to 0 so the animations keep repeating in the above order 
    }
}