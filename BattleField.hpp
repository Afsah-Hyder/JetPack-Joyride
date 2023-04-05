#pragma once
#include<SDL.h>
#include "Bullet.hpp"
#include "Tank.hpp"
#include<list>
using namespace std;
class BattleField{
    list<Bullet*> bullets;   //creating a list of bullets
    Bullet *b1;   //variable of type Bullet* to hold the newly created Bullt object
    list<Tank*> tanks; //lis of Tanks of type Tank*
    Tank *t1;  //pointer for a tank
    SDL_Renderer *gRenderer;
    SDL_Texture *assets;
    list<Bullet*>::iterator b;  //iterator for the list of Bullet* objects

    public:
    //function sketches
    BattleField(SDL_Renderer *, SDL_Texture *);
    void drawObjects(); 
    void createObject(int, int);
    void fire();


    ~BattleField();  //destructor
};