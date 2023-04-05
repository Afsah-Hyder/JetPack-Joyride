
#include "Tank.hpp"


Tank::Tank(SDL_Renderer* rend, SDL_Texture* ast, SDL_Rect mov): Unit(rend, ast), mover(mov){
        
        tb = new Tank_body(rend, ast, mov); //dynamically create the tank body
        tt = new Tank_turret(rend, ast, mov);  //dynamically create the tank turret
        
}

void Tank::draw(){
        // Unit::draw(src, mover);
        tb->draw();
        tt->draw(); //draw the tank turret
        
    }

void Tank::fire(){
   
    tt->recoil(); //call the fire function of the tank turret.
    
}

int Tank::tank_x_pos(){  //functions to tell the bullet where it needs to be made
    return mover.x;
}

int Tank::tank_y_pos(){
    return mover.y;
}