#include "coins.hpp"    
#include <iostream>
#include "JetpackJoyride.hpp"
using namespace std;

Coins::Coins(SDL_Renderer* rend, SDL_Texture* ast, SDL_Rect mov):  Unit(rend, ast), mover(mov){
    cout<<"Coin created"<<endl;
    src = {389,2, 20, 20};    //constructor, calls the parent class constructor and saves data to its own attributes too
}

void Coins::draw(){
    if (coll_check){
        src={490,320,20,20};
        Unit::draw(src, mover); 

    }
    else{
    Unit::draw(src, mover); 
    mover.x-=4;
    animation();
    frame++;
    }
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
    if (barry_x>mover.x-2 and barry_x<(mover.x+mover.w+2)){
        if ((barry_y<mover.y+(mover.h))and (barry_y>mover.y-(mover.h))){
            coll_check=true;
            return coll_check;
            //call score function
            // delete coin
        }
    }
    return coll_check;
}

Coins::~Coins(){
    cout<<"Coin destroyed"<<endl;
}

void Coins::animation(){
    if (frame==1*frame_speed){
        src = {389,2, 20, 20};
    }
    else if (frame==2*frame_speed){
        src={411,2,20,20};
    }
    else if(frame==3*frame_speed){
        src={436,2,14,20};
    }
    else if (frame==4*frame_speed){
        src={458,2,6,20};
    }
    else if (frame==5*frame_speed){
        src={473,2,14,20};
    }
    else if(frame==6*frame_speed){
        src={493,2,20,20};
        frame=0;
    }
    
    
}