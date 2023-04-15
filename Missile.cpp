#include "Missile.hpp"    
#include "barry.hpp"
#include <iostream>
#include "JetpackJoyride.hpp"
using namespace std;

Missile::Missile(SDL_Renderer* rend, SDL_Texture* ast, SDL_Rect mov):  Unit(rend, ast), mover(mov){
    cout<<"Missile created"<<endl;
    src = {575,278, 55, 55}; 

    //what you will now see if a very bad programming practise. Creating the audio class to play a single sound
    // launch_s = new FX();   //constructor, calls the parent class constructor and saves data to its own attributes too
    launch_s.initialize();
    launch_s.load();
}

void Missile::draw(){
    timer++;  //to shoot missile
    Unit::draw(src, mover); 
    // cout<<"Missile drawn"<<endl;
    // mover.x -=4;
    if (timer==400){
        seeking_on=false;
    }
    if(seeking_on==false){

        animation();
        mover.x-=10;
        frame++;
        
        
    }
    // position_seeker(Barry:barry_x_pos(),Barry:barry_y_pos());
    // animation();
    // frame++;
}

void Missile::position_seeker(int barry_x, int barry_y){
    if (barry_y>mover.y and seeking_on==true){
        mover.y++;
    }
    else if(barry_y<mover.y and seeking_on==true){
        mover.y--;
    }

}


void Missile::collision(int barry_x, int barry_y){
    if (seeking_on==true){
    position_seeker(barry_x,barry_y);
    }
    if (barry_y>mover.y-2 and barry_y<(mover.y+mover.h+2)){
        if ((barry_x<mover.x+(mover.w/2))and (barry_x>mover.x-(mover.w/2))){
            cout<<"Barry collided with Missile"<<endl;
        }
    }
}

Missile::~Missile(){
    cout<<"Missile destroyed"<<endl;
    // ~launch_s();

}


void Missile::animation(){
    if (frame<=2*frame_speed and warning_sign==false){
        src = {571,349, 55, 55};
        launch_sound();
        warning_sign=true;  //condition to break out of this condition
        
        mover.x=900;
        // SDL_Delay(200);
        
        
        // JetpackJoyride::audio->effects('m');
    }

    else if (frame==2*frame_speed){
        
        src = {418,113,117,66};
        mover.h =51;
        mover.w = 90;
        // frame=0;
    }

    else if (frame==3*frame_speed){
        src = {429,194,117,66};
        // frame=0;
    }
    else if (frame==4*frame_speed){
        src = {435,268,117,66};
        // frame=0;
    }

    else if (frame==5*frame_speed){
        src = {434,344,117,66};
        // frame=0;
    }

    else if (frame==6*frame_speed){
        src = {558,195,117,66};
        frame=0;
    }
}



bool Missile::delete_item(){
    if (mover.x<0){
        return true;
    }
    else{
        return false;
    }
}

void Missile::launch_sound(){
    launch_s.effect('m');
}