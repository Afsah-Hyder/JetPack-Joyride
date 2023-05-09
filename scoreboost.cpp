#include "scoreboost.hpp"    
#include <iostream>
#include "JetpackJoyride.hpp"
using namespace std;

Score_booster::Score_booster(SDL_Renderer* rend, SDL_Texture* ast, SDL_Rect mov):  Unit(rend, ast), mover(mov){
    cout<<"Booster created"<<endl;
    src = {382,46, 52, 53};    //constructor, calls the parent class constructor and saves data to its own attributes too
    mover.x=1000;
}

void Score_booster::draw(){
    if (invisible==true){
        src = {0,0,0,0};
    }
    Unit::draw(src, mover); 
    mover.x-=3;
    mover.y = mover.y + up_down_movt;
    if (mover.y<30){
        up_down_movt = -1*up_down_movt;
    }
    if (mover.y>350){
        up_down_movt = -1*up_down_movt;
    }
    animation();
    frame++;
}

bool Score_booster::coin_delete(){
    if (mover.x < -150){
        return true;
    }

    else{
    return false;
    }
}

int Score_booster::collision(int barry_x, int barry_y){
    if (collect_once_only==false){
    if (barry_x>mover.x-10 and barry_x<(mover.x+mover.w+10)){
        if ((barry_y<mover.y+(mover.h/2)+15)and (barry_y>mover.y-(mover.h/2)-15)){
            cout<<"Barry collected a booster"<<endl;
            invisible=true;
            collect_once_only=true;
            return 2;
        }
    }
    }
    return 0;
}

Score_booster::~Score_booster(){
    cout<<"Booster destroyed"<<endl;
}

void Score_booster::animation(){
    if (invisible==true){
        src = {0,0,0,0};
    }
    if (frame==1*frame_speed){
        src = {382,46, 52, 53};
    }

    else if (frame==2*frame_speed){
        src = {447,51,54,45};
    }

    else if (frame==3*frame_speed){
        src = {520,52,53,41};
        // frame=0;
    }

    else if (frame==4*frame_speed){
        src = {520,52,53,41};
        frame=0;
    }
}