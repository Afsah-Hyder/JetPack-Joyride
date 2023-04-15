#pragma once
#include<SDL.h>
#include "barry.hpp"
#include "Killers.hpp"
#include "collectables.hpp"
#include "fx.hpp"
#include<list>
using namespace std;
class JetpackJoyride{
    
    SDL_Renderer *gRenderer;
    SDL_Texture *assets;
    list <Killers*> killer_holder;
    list<Killers*>::iterator killer_iter;  //iterator for the list of Bullet* objects
    list <Collectables*> collector_holder;
    list<Collectables*>::iterator collector_iter;
    bool coin_check=true;
    bool coin_collected_once=false;
    public:
    //function sketches
    Barry *b1;
    FX* audio;
    JetpackJoyride(SDL_Renderer *, SDL_Texture *);
    void createBarry();
    void drawObjects(); 
    // void createObject(int, int);
    void fire_jetpack();
    void jetpack_off();
    void create_at_random();
    int random_speed_controller=0;
    int random_speed=160; //the greater the number, the slower the creation of random objects
    int random_object_spacer=0; //creates objects sepated by random distances
    ~JetpackJoyride();  //destructor
};