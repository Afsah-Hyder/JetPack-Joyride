#include "Missile.hpp"    
// #include "barry.hpp"
#include <iostream>
// #include "JetpackJoyride.hpp"
using namespace std;

Missile::Missile(SDL_Renderer* rend, SDL_Texture* ast, SDL_Rect mov):  Unit(rend, ast), mover(mov){
    // cout<<"Missile created"<<endl;
    src = {575,278, 55, 55}; 

    launch_s.initialize(); //initialize the audio object
    launch_s.load();  //load the audio files
}

void Missile::draw(){
    timer++;  //to shoot missile after a certain time
    Unit::draw(src, mover);  //draw the object
    if (timer==350){  //stop the warning symbol once the bullet timer reaches 350
        seeking_on=false;  //stop seeking barry
    }
    if(seeking_on==false){

        animation();  //animate the bullet
        mover.x-=8;  //move the bullet to the left at a speed of 9 pixels per function call
        frame++;  //increment the frame
        
    }
 
}

void Missile::position_seeker(int barry_x, int barry_y){
    if (barry_y>mover.y and seeking_on==true){
        mover.y++;   //move the object to locate barry
    }
    else if(barry_y<mover.y and seeking_on==true){
        mover.y--; //move the object tp=o locate barry
    }
}


bool Missile::collision(int barry_x, int barry_y){
    if (seeking_on==true){
    position_seeker(barry_x,barry_y);  //get barry's x and y coordinate to reposition

    }
    //conditions for collision detection
    if (barry_y>mover.y-2 and barry_y<(mover.y+mover.h+2)){
        if ((barry_x<mover.x+(mover.w/2)-3)and (barry_x>mover.x-(mover.w/2)+3)){
            // cout<<"Barry collided with Missile"<<endl;
            return true;  //barry has collided
        }
    }
        return false;  //barry has not collided
}

Missile::~Missile(){
    // cout<<"Missile destroyed"<<endl;

}


void Missile::animation(){
    if (frame<=2*frame_speed and warning_sign==false){
        src = {571,349, 55, 55};
        launch_sound();
        warning_sign=true;  //condition to break out of this condition
        mover.x=900;  //keep the warning sign at x=900
        
    }

    else if (frame==2*frame_speed){ 
        src = {418,113,117,66};  //selecting the image from asset file
        //resize the bullet object to now show the bullet instead of the warning symbol
        mover.h =51;
        mover.w = 90;

    }

    else if (frame==3*frame_speed){
        src = {429,194,117,66}; //selecting the image from asset file
        
    }
    else if (frame==4*frame_speed){
        src = {435,268,117,66};  //selecting the image from asset file
        
    }

    else if (frame==5*frame_speed){
        src = {434,344,117,66};  //selecting the image from asset file
        
    }

    else if (frame==6*frame_speed){
        src = {558,195,117,66};   //selecting the image from asset file
        frame=0;
    }
}



bool Missile::delete_item(){
    if (mover.x<-100){   //delete the missile once it leaves the screen
        return true;  //missile has left the screen
    }
    else{
        return false;   //missile has not left the screen
    }
}

void Missile::launch_sound(){
    launch_s.effect('m');  //play the missile firing sound
}