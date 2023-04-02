#include "obstacles.hpp"    

obstacles::obstacles(SDL_Renderer* rend, SDL_Texture* ast, SDL_Rect mov): Unit(rend, ast), mover(mov){
    src = {0,15, 425, 275};    //constructor, calls the parent class constructor and saves data to its own attributes too
}

void obstacles::draw(){
    Unit::draw(src, mover);                
}