#include "barry.hpp"    

Barry::Barry(SDL_Renderer* rend, SDL_Texture* ast, SDL_Rect mov): Unit(rend, ast), mover(mov){
    src = {0,0, 79, 88};    //constructor, calls the parent class constructor and saves data to its own attributes too
}

void Barry::draw(){
    Unit::draw(src, mover); 
    
    
    if (death==false){
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

    else{
        die();
        frames++;
    }
               
}

void Barry::running(){
    if (death==false){
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
}

void Barry::flying(){
    if (death==false){

        if (mover.y>30){
        mover.y-=rise;
        }

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
}

void Barry::move_up(){
    // if(mover.y>30)
    // mover.y=mover.y-6;
}

void Barry::move_down(){
    // if(mover.y<353){
    if (death==false){
    mover.y+=gravity;
    src = {0,95, 79, 97};
    if (mover.y>=373){
        mover.y=373;
        drop=0;
    }
    }
}

void Barry::falling(){

}

int Barry::barry_x_pos(){
    return mover.x;
}

int Barry::barry_y_pos(){
    return mover.y;
}

void Barry::die(){
    if (mover.y<400){
        mover.y = mover.y+gravity;

        if (frames < 1* die_frame_speed){
            mover.w = 38;

            src = {737,12,61,83};
    }

    else if (frames <2* die_frame_speed){
        src = {801,12,61,83};
    }

    else if (frames < 3* die_frame_speed){
        src = {862,12,61,83};

        frames=0;
    }
    }

    if (mover.y>=400){
        mover.w = 55;
        mover.h=30;
        // mover.y=400;
        src = {824,105,85,42};
    }

    


}