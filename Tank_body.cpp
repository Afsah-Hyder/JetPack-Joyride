
#include "Tank_body.hpp"    

    Tank_body::Tank_body(SDL_Renderer* rend, SDL_Texture* ast, SDL_Rect mov): Unit(rend, ast), mover(mov){
        src = {0, 13, 425, 293}; //to draw the tank body
    }

    void Tank_body::draw(){
        Unit::draw(src, mover);  //to draw the tank body
        
    }