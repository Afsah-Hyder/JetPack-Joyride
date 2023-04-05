#include "Tank_turret.hpp"   

    Tank_turret::Tank_turret(SDL_Renderer* rend, SDL_Texture* ast, SDL_Rect mov): Unit(rend, ast), mover(mov){
        src = {600, 0, 1100, 150};  //to draw the turret
        
    }

    void Tank_turret::draw(){
        Unit::draw(src, {mover.x+29,mover.y+23,mover.w+65, mover.h-50}); //taking the coordinates of the tank as reference
        /*The recoil_enable variable was needed to ensure the turret would not recoil on its own when draw() was called*/
        if (recoil_enable){   //make the turret recoil by calling the recoil function
            recoil();  //call the recoil function
        }
    }

    void Tank_turret::recoil(){
        recoil_enable=true;  //to allow the turret to recoil
        if (store_pos){
        initial_x = mover.x;  //store the starting position of the turret as reference
        }
        store_pos=false;  //disable the starting position storing functionality
        if (mover.x-1<=initial_x and mover.x>initial_x-recoil_amount and reverse_enable==false){
            mover.x-=recoil_speed; //make the turret recoil at a set speed per function call
            if (mover.x <= initial_x-recoil_amount){ //condition to enable the reverse recoil to start
                reverse_enable=true; //to break out of this condition and activate the second if condition
            }
        }
        else if (reverse_enable==true and mover.x<initial_x){ /*indicates the bullet has reached the max recoil distance
        and must return to its initial position.*/ 
            mover.x+=recoil_speed; //move the turret towards the right
        }
        else{ //reset to original state after one recoil is completed.
        store_pos=true;   
        reverse_enable=false;
        recoil_enable=false;
        }
    }
