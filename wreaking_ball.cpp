#include "wreaking_ball.hpp"    
// #include "barry.hpp"
#include <iostream>

using namespace std;

WreakingBall::WreakingBall(SDL_Renderer* rend, SDL_Texture* ast, SDL_Rect mov):  Unit(rend, ast), mover(mov){ //constructor
    // cout<<"WreakingBall created"<<endl;
    src = {575,278, 55, 55};  //selecting the image from asset file

    launch_s.initialize();
    launch_s.load();
}

void WreakingBall::draw(){
    timer++;  //to shoot WreakingBall
    Unit::draw(src, mover);  //draw the wreaking ball on the screen using the provided src coordinates
    
    if (timer>=200){    //condition for the ball to start moving on the screen
        warning_sign=false;  //switch off the warning symbol
        animation();  //start making the ball roll
        launch_sound();  //play the fireball sound
        mover.x-=10;  //move the ball at a speed of 10 pixels to the left
        frame++; //move from one frame to the other
    }
    if(timer<200){  //while the ball hasn't started rolling
        warning_sign=true;  //keep the warning sign on the screen
        animation();  //animate the warning sign
        frame++; //transition from one warning sign frame to the next
        
        
    }
    
}


bool WreakingBall::collision(int barry_x, int barry_y){   //collision detection function for the ball
    if (barry_y>mover.y-2 and barry_y<(mover.y+mover.h+2)){   //barry's y pos should lie between the upper and lower ends of the ball
        if ((barry_x<mover.x+(mover.w/2)-3)and (barry_x>mover.x-(mover.w/2)+3)){  //barry's x pos should be between the right and left ends of the ball
            // cout<<"Barry collided with WreakingBall"<<endl;
            return true;  //barry has collided
        }
    }
        return false; //barry has not collided
}

WreakingBall::~WreakingBall(){   //destructor
    // cout<<"WreakingBall destroyed"<<endl;

}


void WreakingBall::animation(){

    if (warning_sign==true){
        if (frame == 1*frame_speed){
            src = {768, 228, 63, 63};  //selecting the image from asset file
        }

        else if(frame == 2*frame_speed){
            src = {833, 228, 63, 63};  //selecting the image from asset file
        }

        else if(frame == 3*frame_speed){
            src = {900, 228, 63, 63};  //selecting the image from asset file
        }

        else if(frame == 4*frame_speed){
            src = {964, 228, 63, 63};  //selecting the image from asset file
            frame=0;
        }
    }

    else{
    
    //re-sizing the object so that the ball is large enough.
        mover.y = 300;
        mover.h =134;
        mover.w = 210;
        if (frame==1*frame_speed){
            
            src = {770,152,105,67}; //selecting the image from asset file
        }

        else if (frame==2*frame_speed){
            src = {877,152,105,67}; //selecting the image from asset file
        
        }
        else if (frame==3*frame_speed){
            src = {985,152,105,67}; //selecting the image from asset file
        }

        else if (frame==4*frame_speed){
            src = {1091,152,105,67}; //selecting the image from asset file
            frame=0;
        }
        
    }
}


bool WreakingBall::delete_item(){
    if (mover.x<-150){  //if the object has left the screen and its x coordinates are less than -150
        return true;  //the object left the screen
    }
    else{
        return false; //the object has not left the screen
    }
}

void WreakingBall::launch_sound(){
    launch_s.effect('b');  //play the fireball sound
}