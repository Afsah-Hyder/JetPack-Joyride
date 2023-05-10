#include "Scientist.hpp"    

#include <iostream>
// #include "JetpackJoyride.hpp"
using namespace std;

Scientist::Scientist(SDL_Renderer* rend, SDL_Texture* ast, SDL_Rect mov):  Unit(rend, ast), mover(mov){
    // cout<<"Scientist created"<<endl;
    src = {996,18, 40, 71};   
}

void Scientist::draw(){  //draw the scientists
    Unit::draw(src, mover);   //draw the object
    
    mover.x -=3; //move the scientist to the left at a speed of 3 pixels
    animation();  //animate the scientist
    frame++;  //increment the frame
}


Scientist::~Scientist(){ //destructor
    // cout<<"Scientist destroyed"<<endl;
}



void Scientist::animation(){  //make the scientist walk
    if (frame==1*frame_speed){
        src={923,16, 65, 77};  //selecting the image from asset file
        
    }

    else if (frame==3*frame_speed){
        src = {987,16, 65, 77}; //selecting the image from asset file
        frame=0;
    }

    else if (frame==2*frame_speed){
        src = {1053,16, 65, 77};  //selecting the image from asset file
    }
}

bool Scientist::delete_item(){
    if (mover.x<-150){
        return true;
    }
    else{
        return false;
    }
}