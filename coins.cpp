#include "coins.hpp"    
#include <iostream>
// #include "JetpackJoyride.hpp"
using namespace std;

Coins::Coins(SDL_Renderer* rend, SDL_Texture* ast, SDL_Rect mov):  Unit(rend, ast), mover(mov){
    // cout<<"Coin created"<<endl;
    src = {389,2, 20, 20};    //constructor, calls the parent class constructor and saves data to its own attributes too
}

void Coins::draw(){
    if (invisible==true){           //once a coin is collected it disappears from the screen, we dont delete it at this point
        src = {0,0,0,0};          // blank space from assets file, so the coin "disappears"
    }
    Unit::draw(src, mover);   //draws the zapper every time for a new frame
    mover.x-=4;              //moves 4 units to the left each time it is drawn
    animation();
    frame++;          //frame incremented
}

bool Coins::coin_delete(){
    if (mover.x < -150){        //if x-coordinate of coin is less than -150, that is it has moved out of the screen
        return true;            //then it needs to be deleted
    }

    else{
    return false;  //else keep it on the screen
    }
}

int Coins::collision(int barry_x, int barry_y){
    if (collect_once_only==false){     //if coin is not already collected
    if (barry_x>mover.x-10 and barry_x<(mover.x+mover.w+10)){
        //if barry x coordinated lie within the width of the coin with +- 10 units uncertainity
        if ((barry_y<mover.y+(mover.h/2)+15)and (barry_y>mover.y-(mover.h/2)-15)){
            // and barry y coordianted lie within the height of the coin with a +-15 units uncertainity
            // cout<<"Barry collected a coin"<<endl;
            invisible=true;        //so we the coin collected is not drawn in the next frame
            collect_once_only=true;       //score increases only once for a coin collected, doesn't increasing for the whole time period Barry is in contact with the coin
            return 1;
        }
    }
    }
    return 0;
}

Coins::~Coins(){
    // cout<<"Coin destroyed"<<endl;       //destructor
}

void Coins::animation(){
    if (invisible==true){
        src = {0,0,0,0};        //selecting image from the assets file (this is a blank image, for when the coin disappears when collected
    }
    if (frame==1*frame_speed){
        src = {388,0,22, 22};           //selecting image from the assets file
    }
    else if (frame==2*frame_speed){
        src={410, 0 ,22,22};            //selecting image from the assets file
    }
    else if(frame==3*frame_speed){
        src={433, 0 ,22, 22};           //selecting image from the assets file
    }
    else if (frame==4*frame_speed){
        src={450,0,22,22};          //selecting image from the assets file
    }
    else if (frame==5*frame_speed){
        src={469,0,22,22};      //selecting image from the assets file
    }
    else if(frame==6*frame_speed){
        src={492,0,22,22};      //selecting image from the assets file
        // frame=0;
    }
    else if(frame==7*frame_speed){
        src={388,0,22, 22};         //selecting image from the assets file
        frame=0;            //set to 0 so the animations keep repeating in the above order 
    }
    
    
}