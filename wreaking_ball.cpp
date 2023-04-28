#include "wreaking_ball.hpp"    
#include "barry.hpp"
#include <iostream>
#include "JetpackJoyride.hpp"
using namespace std;

WreakingBall::WreakingBall(SDL_Renderer* rend, SDL_Texture* ast, SDL_Rect mov):  Unit(rend, ast), mover(mov){
    cout<<"WreakingBall created"<<endl;
    src = {575,278, 55, 55}; 

    //what you will now see if a very bad programming practise. Creating the audio class to play a single sound
    // launch_s = new FX();   //constructor, calls the parent class constructor and saves data to its own attributes too
    launch_s.initialize();
    launch_s.load();
}

void WreakingBall::draw(){
    timer++;  //to shoot WreakingBall
    Unit::draw(src, mover); 
    // cout<<"WreakingBall drawn"<<endl;
    // mover.x -=4;
    if (timer>=200){
        warning_sign=false;
        animation();
        launch_sound();
        mover.x-=10;
        frame++;
    }
    if(timer<200){
        warning_sign=true;
        animation();
        // mover.x-=8;
        frame++;
        
        
    }
    // position_seeker(Barry:barry_x_pos(),Barry:barry_y_pos());
    // animation();
    // frame++;
}

// void WreakingBall::position_seeker(int barry_x, int barry_y){
//     if (barry_y>mover.y and seeking_on==true){
//         mover.y++;
//     }
//     else if(barry_y<mover.y and seeking_on==true){
//         mover.y--;
//     }

// }


bool WreakingBall::collision(int barry_x, int barry_y){
    if (barry_y>mover.y-2 and barry_y<(mover.y+mover.h+2)){
        if ((barry_x<mover.x+(mover.w/2)-3)and (barry_x>mover.x-(mover.w/2)+3)){
            cout<<"Barry collided with WreakingBall"<<endl;
            return true;
        }
    }
        return false;
}

WreakingBall::~WreakingBall(){
    cout<<"WreakingBall destroyed"<<endl;
    // ~launch_s();

}


void WreakingBall::animation(){

    if (warning_sign==true){
        if (frame == 1*frame_speed){
            src = {768, 228, 63, 63};
        }

        else if(frame == 2*frame_speed){
            src = {833, 228, 63, 63};
        }

        else if(frame == 3*frame_speed){
            src = {900, 228, 63, 63};
        }

        else if(frame == 4*frame_speed){
            src = {964, 228, 63, 63};
            frame=0;
        }
    }

    else{
    
    mover.y = 300;
    mover.h =134;
    mover.w = 210;
    if (frame==1*frame_speed){
        
        src = {770,152,105,67};
        
        // frame=0;
    }

    else if (frame==2*frame_speed){
        src = {877,152,105,67};
        // frame=0;
    }
    else if (frame==3*frame_speed){
        src = {985,152,105,67};
        // frame=0;
    }

    else if (frame==4*frame_speed){
        src = {1091,152,105,67};
        frame=0;
    }
    
    }
}


bool WreakingBall::delete_item(){
    if (mover.x<-150){
        return true;
    }
    else{
        return false;
    }
}

void WreakingBall::launch_sound(){
    launch_s.effect('b');
}