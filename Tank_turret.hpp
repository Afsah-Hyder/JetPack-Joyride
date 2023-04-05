#include "Unit.hpp"

class Tank_turret:public Unit{

SDL_Rect src, mover;
//setting initial parameters
bool recoil_enable=false;   //to stop recoil if this variable is false
int initial_x;  //to store the initial position of the turret to act as a reference for the recoil function
bool store_pos=true;  //varibale to allow the storing of the initial position
bool reverse_enable=false; //to activate reverse recoil (move towards the right) when true
int recoil_amount=9;  //to set the recoil length i.e. till what distance the turret recoils
int recoil_speed=2;  //to set the speed of recoil
public:

Tank_turret(SDL_Renderer* rend, SDL_Texture* ast, SDL_Rect mov);  //constructor

void draw(); //draw function

void recoil(); //recoil function

};