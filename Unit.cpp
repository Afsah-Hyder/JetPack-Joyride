#include "Unit.hpp"

Unit::Unit(SDL_Renderer* rend, SDL_Texture* ast): gRenderer(rend), assets(ast){ //constructor
}

void Unit::draw(SDL_Rect srcRect, SDL_Rect moverRect){   //to draw the object
    SDL_RenderCopy(gRenderer, assets, &srcRect, &moverRect);
}

Unit::~Unit(){}