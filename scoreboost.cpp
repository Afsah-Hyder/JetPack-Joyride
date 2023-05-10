#include "scoreboost.hpp"    
#include <iostream>

using namespace std;

Score_booster::Score_booster(SDL_Renderer* rend, SDL_Texture* ast, SDL_Rect mov):  Unit(rend, ast), mover(mov){
    // cout<<"Booster created"<<endl;
    src = {382,46, 52, 53};    //constructor, calls the parent class constructor and saves data to its own attributes too
    mover.x=1000; //create the score booster at x=1000
}

void Score_booster::draw(){
    if (invisible==true){ //make the score-booster disappear after it is touched
        src = {0,0,0,0};
    }
    Unit::draw(src, mover); 
    mover.x-=3;  //
    mover.y = mover.y + (up_down_movt) + direction*(230/mover.y);

    //procedure to move the score booster up and down the screen
    if (mover.y<50){
        up_down_movt = -1*up_down_movt;
        direction = 1;
    }
    if (mover.y>330){
        up_down_movt = -1*up_down_movt;
        direction = -1;
    }
    animation();  
    frame++;
}

bool Score_booster::coin_delete(){  //function to delete the score booster once it leaves the screen
    if (mover.x < -150){
        return true;
    }

    else{
    return false;
    }
}

int Score_booster::collision(int barry_x, int barry_y){  //for detecting collisions
    if (collect_once_only==false){
    if (barry_x>mover.x-10 and barry_x<(mover.x+mover.w+10)){
        if ((barry_y<mover.y+(mover.h/2)+15)and (barry_y>mover.y-(mover.h/2)-15)){
            // cout<<"Barry collected a booster"<<endl;
            invisible=true;
            collect_once_only=true;
            return 2;
        }
    }
    }
    return 0;
}

Score_booster::~Score_booster(){  //destructor
    // cout<<"Booster destroyed"<<endl;
}

void Score_booster::animation(){   //to animate the score booster
    if (invisible==true){
        src = {0,0,0,0};  //select the frame in the asset file
    }
    if (frame==1*frame_speed){
        src = {382,46, 52, 53}; //select the frame in the asset file
    }

    else if (frame==2*frame_speed){
        src = {447,51,54,45};  //select the frame in the asset file
    }

    else if (frame==3*frame_speed){
        src = {520,52,53,41};  //select the frame in the asset file
        // frame=0;
    }

    else if (frame==4*frame_speed){
        src = {447,51,54,45};  //select the frame in the asset file
        frame=0;
    }
}