#include "coins.hpp"    
#include <iostream>
#include "JetpackJoyride.hpp"
using namespace std;

Coins::Coins(SDL_Renderer* rend, SDL_Texture* ast, SDL_Rect mov): Unit(rend, ast), mover(mov){
    cout<<"Coin created"<<endl;
    src={388,0,22, 22};    //constructor, calls the parent class constructor and saves data to its own attributes too
    // src={411,2,20,20};
    // src={436,2,14,20};
    // src={458,2,6,20};
    // src={473,2,14,20};
    // src={493,2,20,20};
}

void Coins::draw(){
    if (invisible==true){
        src = {0,0,0,0};
    }
    Unit::draw(src, mover); 
    mover.x-=4;
    animation();
    frame++;
}

bool Coins::coin_delete(){
    if (mover.x < -150){
        return true;
    }

    else{
    return false;
    }
}

bool Coins::collision(int barry_x, int barry_y){
    if (barry_x>mover.x-10 and barry_x<(mover.x+mover.w+10)){
        if ((barry_y<mover.y+(mover.h/2)+15)and (barry_y>mover.y-(mover.h/2)-15)){
            cout<<"Barry collected a coin"<<endl;
            invisible=true;
            
            return true;
            //call score function
            // delete coin
        }
    }
    return false;
}

Coins::~Coins(){
    cout<<"Coin destroyed"<<endl;
}

void Coins::animation(){
    if (invisible==true){
        src = {0,0,0,0};
    }
    if (frame==1*frame_speed){
        src = {388,0,22, 22};
    }
    else if (frame==2*frame_speed){
        src={410, 0 ,22,22};
    }
    else if(frame==3*frame_speed){
        src={433, 0 ,22, 22};
    }
    else if (frame==4*frame_speed){
        src={450,0,22,22};
    }
    else if (frame==5*frame_speed){
        src={469,0,22,22};
    }
    else if(frame==6*frame_speed){
        src={492,0,22,22};
        frame=0;
    }
    
    
}