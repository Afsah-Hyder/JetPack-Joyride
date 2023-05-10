#include "red_lights.hpp"    

#include <iostream>
// #include "JetpackJoyride.hpp"
using namespace std;

RedLights::RedLights(SDL_Renderer* rend, SDL_Texture* ast, SDL_Rect mov):  Unit(rend, ast), mover(mov){
    // cout<<"light created"<<endl;
    src = {996,18, 40, 71};   
}

void RedLights::draw(){  //draw the RedLightss
    Unit::draw(src, mover);   //draw the object
    
    mover.x -=4; //move the RedLights to the left at a speed of 3 pixels
    animation();  //animate the RedLights
    frame++;  //increment the frame
    // cout<<"Red light drawn"<<endl;
}


RedLights::~RedLights(){ //destructor
    // cout<<"Light destroyed"<<endl;
}



void RedLights::animation(){  //make the RedLights walk
    if (frame==1*frame_speed){
        src={1210,-8, 102, 102};  //selecting the image from asset file
        
    }

    else if (frame==2*frame_speed){
        src = {1368,-8, 102, 102}; //selecting the image from asset file
        // frame=0;
    }

    else if (frame==3*frame_speed){
        src = {1527,-8, 102, 102};  //selecting the image from asset file
        // frame=0;
    }

    else if (frame==4*frame_speed){
        src = {1210,140, 102, 102};  //selecting the image from asset file
        // frame=0;
    }

    else if (frame==5*frame_speed){
        src = {1368,140, 102, 102};  //selecting the image from asset file
        // frame=0;
    }

    else if (frame==6*frame_speed){
        src = {1527,140, 102, 102};  //selecting the image from asset file
        frame=0;
    }
}

bool RedLights::delete_item(){  //to delete the lights
    if (mover.x<-150){
        return true;
    }
    else{
        return false;
    }
}