#include "ZapperH.hpp"    

#include <iostream>
#include "JetpackJoyride.hpp"
using namespace std;

Zapper_h::Zapper_h(SDL_Renderer* rend, SDL_Texture* ast, SDL_Rect mov):  Unit(rend, ast), mover(mov){
    cout<<"Zapper created"<<endl;
    src = {0,445, 223, 72};    //constructor, calls the parent class constructor and saves data to its own attributes too
}

void Zapper_h::draw(){
    Unit::draw(src, mover);          //draws the zapper every time for a new frame
    
    mover.x -=4;                     // zapper moves 4 units to the left each time it is drawn
    animation();                     
    frame++;                         //frame incremented
}

bool Zapper_h::collision(int barry_x, int barry_y){
    if (barry_x>mover.x-10 and barry_x<(mover.x+mover.w+10)){   
    //if barry x coordinated lie within the width of the zapper with +- 10 units uncertainity
        if ((barry_y<mover.y+(mover.h/2))and (barry_y>mover.y-(mover.h/2))){
            //and barry y coordinated lie within the height of the zapper 
            cout<<"Barry collided horizontal zapper"<<endl;     //then Barry has collided with the zapper
            return true;
        }
    }
    
    return false;
    
}

Zapper_h::~Zapper_h(){             
    cout<<"Horizontal Zapper destroyed"<<endl;      //destructor
}

bool Zapper_h::delete_item(){
    if (mover.x < -150){          //if x-coordinate of zapper is less than -150, that is it has moved out of the screen
        return true;              //then it needs to be deleted
    }

    else{
    return false;
    }
}

void Zapper_h::animation(){
    if (frame==1*frame_speed){
        src = {20,451, 180, 58};         //selecting the image from asset file
        // SDL_Delay(40);
        // frames++;
    }

    else if (frame==2*frame_speed){
        src = {20,530, 180, 58};        //selecting the image from asset file
        // SDL_Delay(40);
        // frame=0;
    }

    else if (frame==3*frame_speed){
        src = {771,450, 180, 58};       //selecting the image from asset file
        // SDL_Delay(40);
        // frame=0;
    }

    else if (frame==4*frame_speed){
        src = {772,529, 180, 58};       //selecting the image from asset file
        // SDL_Delay(40);
        frame=0;             //set to 0 so the animations keep repeating in the above order 
    }
}