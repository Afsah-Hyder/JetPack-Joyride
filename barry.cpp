#include "barry.hpp"    

Barry::Barry(SDL_Renderer* rend, SDL_Texture* ast, SDL_Rect mov): Unit(rend, ast), mover(mov){
    src = {0,0, 79, 88};    //constructor, calls the parent class constructor and saves data to its own attributes too
}

void Barry::draw(){
    Unit::draw(src, mover); 
    
    

    if (mover.y==373){
        running();
        frames++; 
    }   
    else if(drop==1){
        move_down();
    }
    else{
        flying();
        frames++;
    }
               
}

void Barry::running(){
    if (frames==0){
        src = {0,0, 79, 88};
        // SDL_Delay(40);
        // frames++;
    }

    else if (frames==1*frame_speed){
        src = {81,0, 79, 88};
        // SDL_Delay(40);
        // frames++;
    }

    else if (frames==2*frame_speed){
        src = {170,0, 79, 88};
        // SDL_Delay(40);
        // frames++;
    }

    else if (frames==3*frame_speed){
        src = {256,0, 79, 88};
        // SDL_Delay(40);
        frames=0;
    }
}

void Barry::flying(){
    if (mover.y>30){
    mover.y-=rise;
    }
    // if (frames==0){
    // src = {0,95, 79, 97};
    
    // }

    if (frames==1*frame_speed){
        src = {83,95, 79, 97};
        // SDL_Delay(40);
        // frames++;
    }

    else if (frames==2*frame_speed){
        src = {170,95, 79, 97};
        // SDL_Delay(40);
        // frames++;
    }

    else if (frames==3*frame_speed){
        src = {256,95, 79, 97};
        // SDL_Delay(40);
        frames=0;
    }
    

}

void Barry::move_up(){
    // if(mover.y>30)
    // mover.y=mover.y-6;
}

void Barry::move_down(){
    // if(mover.y<353){
    mover.y+=gravity;
    src = {0,95, 79, 97};
    if (mover.y>=373){
        mover.y=373;
        drop=0;
    }
    // }
}

void Barry::falling(){

}