#pragma once
#include<SDL.h>
#include "barry.hpp"

#include<list>
using namespace std;
class JetpackJoyride{
    
    SDL_Renderer *gRenderer;
    SDL_Texture *assets;
    // list<Bullet*>::iterator b;  //iterator for the list of Bullet* objects

    public:
    //function sketches
    Barry *b1;
    JetpackJoyride(SDL_Renderer *, SDL_Texture *);
    void createBarry();
    void drawObjects(); 
    void createObject(int, int);
    void fire_jetpack();
    void jetpack_off();


    ~JetpackJoyride();  //destructor
};