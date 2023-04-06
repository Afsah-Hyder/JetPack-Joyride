#include "JetpackJoyride.hpp"
#include "barry.hpp"
#include<iostream>



void JetpackJoyride::drawObjects(){
    // call draw functions of all the objects here
    // for (Tank*& t: tanks)
        b1->draw();  //draw the tanks

    // for(Bullet*& b: bullets)
    //         b->draw();  //draw the bullets


    // b = bullets.begin();   //assign the initial node to the iterator

    // for (b; b!=bullets.end();b++){   //loop to iterate over the list and remove the bullets that need to be removed
    //     if ((**b).bullet_remove()==true){  //if the bullet has to be removes
    //         Bullet* new_ptr=*b; //create a new pointer to the place the bullet to be removed is stored
    //         bullets.erase(b); //remove the bullet object
    //         delete new_ptr; //delete the pointer
            
        // }
    


}
void JetpackJoyride::createBarry(){  //to make barry on the screen

    SDL_Rect mov_b = {353, 373, 51, 63}; 
    b1=new Barry(gRenderer, assets, mov_b);
}

void JetpackJoyride::createObject(int x, int y){
    // SDL_Rect mov_b = {x, y, 30, 10};// let's make a rectangle on x, y of the size 30, 10
    
        
    // t1 = new Tank(gRenderer, assets, mov_t); //creation of the new tank object
    // tanks.push_back(t1); //pushing the tank object to the list
    std::cout<<"Mouse clicked at: "<<x<<" -- "<<y<<std::endl;
}

JetpackJoyride::JetpackJoyride(SDL_Renderer *renderer, SDL_Texture *asst):gRenderer(renderer), assets(asst){

}

void JetpackJoyride::fire_jetpack(){
    // cout<<"F key is pressed"<<endl;
    b1->drop=0;
    b1->flying();
    b1->move_up();
    
    
}

void JetpackJoyride::jetpack_off(){
    b1->drop=1;
}

JetpackJoyride::~JetpackJoyride(){  //destructor for the JetpackJoyride
    // for (Tank*& t: tanks){
    //     t->~Tank(); //destroy the tank objects
    //     t=NULL;  //make each position null
    // }

    // bullets.clear();  //to completely clear the bullets list
    cout<<"Everything destroyed!"<<endl;
}