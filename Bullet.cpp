#include "Bullet.hpp"    
#include <iostream>
using namespace std;

    Bullet::Bullet(SDL_Renderer* rend, SDL_Texture* ast, SDL_Rect mov): Unit(rend, ast), mover(mov){ //constructor
        
    }

    Bullet::~Bullet(){   //destructor for the bullet
        cout<<"Deleted the Blasted Bullet !!"<<endl;
    }

    void Bullet::draw(){
        if (frame==0){
            src = {616, 201, 302, 96};//set the frame to the bullet 
            
            }
        
        else if (frame==1)  {
            src = {0, 364, 163, 530}; //change the frame to the blast animation
            mover.h=55; //set the height of the blast animation
            mover.w = 65;         //set the width of the blast animation
            mover.y = mover.y-20;
        }

        else if (frame==2)  {
             src = {160, 364, 163, 530}; //frame 2
            
        }
        else if (frame==3)  {
            src = {330, 364, 163, 530}; //frame 3
            
        }
        else if (frame==4)  {
            src = {505, 364, 163, 530}; //frame 4
        }
        else if (frame==5)  {
            src = {673, 364, 163, 530}; //frame 5
            
        }
        else if (frame==6)  {
            src = {835, 364, 163, 530};//frame 6
            
        }
        else if (frame==7)  {
            src = {1006, 364, 163, 530};//frame 7
            
        }
        else if (frame==8){
            // ~Bullet();
            src = {0,0,0,0};  //make the bullet disappear
            // bullet_remove();
        }
            
        Unit::draw(src, {mover.x+80,mover.y-8,mover.w, mover.h});  //draw the bullet
        Bullet::fire();  //make the bullet move

        

    }

    void Bullet::fire(){
        if (mover.x<=850)  //if the bullet has not reached the end of the screen, it will move
            mover.x+=4;  //move the bullet at a speed of 4px per function call
        
        if (mover.x>850)  //stop the bullet and enter the blast animation by chnaging the frame
            frame++;  //advance the frame by one
    }

    bool Bullet::bullet_remove(){  //function that returns true if the bullet has reached the border of the screen and has recahed the final blast animation
        if (frame==8)
        return true;

        else
        return false;
    }

    