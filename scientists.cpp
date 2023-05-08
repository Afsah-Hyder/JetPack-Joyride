#include "Scientist.hpp"    

#include <iostream>
// #include "JetpackJoyride.hpp"
using namespace std;

Scientist::Scientist(SDL_Renderer* rend, SDL_Texture* ast, SDL_Rect mov):  Unit(rend, ast), mover(mov){
    cout<<"Scientist created"<<endl;
    src = {996,18, 40, 71};    //constructor, calls the parent class constructor and saves data to its own attributes too
}

void Scientist::draw(){
    Unit::draw(src, mover); 
    
    mover.x -=3;
    animation();
    frame++;
}


Scientist::~Scientist(){
    cout<<"Scientist destroyed"<<endl;
}



void Scientist::animation(){
    if (frame==1*frame_speed){
        src={923,16, 65, 77};
        // SDL_Delay(40);
        // frames++;
    }

    else if (frame==3*frame_speed){
        src = {987,16, 65, 77};
        // SDL_Delay(40);
        frame=0;
    }

    else if (frame==2*frame_speed){
        src = {1053,16, 65, 77};
        // SDL_Delay(40);
        // frame=0;
    }
}