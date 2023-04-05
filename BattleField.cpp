#include "BattleField.hpp"
#include<iostream>
void BattleField::drawObjects(){
    // call draw functions of all the objects here
    for (Tank*& t: tanks)
        t->draw();  //draw the tanks

    for(Bullet*& b: bullets)
            b->draw();  //draw the bullets


    b = bullets.begin();   //assign the initial node to the iterator

    for (b; b!=bullets.end();b++){   //loop to iterate over the list and remove the bullets that need to be removed
        if ((**b).bullet_remove()==true){  //if the bullet has to be removes
            Bullet* new_ptr=*b; //create a new pointer to the place the bullet to be removed is stored
            bullets.erase(b); //remove the bullet object
            delete new_ptr; //delete the pointer
            
        }
    }


}

void BattleField::createObject(int x, int y){
    // SDL_Rect mov_b = {x, y, 30, 10};// let's make a rectangle on x, y of the size 30, 10
    SDL_Rect mov_t = {x-70, y-50, 130, 97}; //to centre the tank on the mouse click
    // Tank t1(gRenderer, assets, mov_t);
        
    t1 = new Tank(gRenderer, assets, mov_t); //creation of the new tank object
    tanks.push_back(t1); //pushing the tank object to the list

    
    std::cout<<"Mouse clicked at: "<<x<<" -- "<<y<<std::endl;
}

BattleField::BattleField(SDL_Renderer *renderer, SDL_Texture *asst):gRenderer(renderer), assets(asst){

}

void BattleField::fire(){
    cout<<"F key is pressed"<<endl;
    
    for (Tank*& t: tanks){
        t->fire(); //call the fire function of the tank
        int bulletx = t->tank_x_pos(); //to create the bullet at bulletx with reference to the tank x position
        int bullety = t->tank_y_pos(); //to create the bullet at bullety with reference to the tank y position
        b1= new Bullet(gRenderer, assets, {bulletx+70,bullety+50, 30,10});// make a new constructor
        bullets.push_back(b1);  //push the object into the list
        
    }
    
}


BattleField::~BattleField(){  //destructor for the battlefield
    for (Tank*& t: tanks){
        t->~Tank(); //destroy the tank objects
        t=NULL;  //make each position null
    }

    bullets.clear();  //to completely clear the bullets list
    cout<<"Everything destroyed!"<<endl;
}