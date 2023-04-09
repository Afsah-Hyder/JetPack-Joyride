#include "JetpackJoyride.hpp"
#include "barry.hpp"
#include<iostream>
#include "Killers.hpp";
#include "Zapper.hpp"


void JetpackJoyride::drawObjects(){
    // call draw functions of all the objects here
    // for (Tank*& t: tanks)
    
    b1->draw();  //draw the tanks

    killer_iter = killer_holder.begin();   //assign the initial node to the iterator

    for (killer_iter; killer_iter!=killer_holder.end();killer_iter++){ 
        // (**killer_iter).collision(b1->barry_x_pos(),b1->barry_y_pos());  //loop to iterate over the list and remove the bullets that need to be removed
        if ((**killer_iter).zapper_delete()==true){  //if the zapper has to be removed
            Killers* new_ptr=*killer_iter; //create a new pointer to the place the bullet to be removed is stored
            killer_holder.erase(killer_iter); //remove the bullet object
            delete new_ptr; //delete the pointer
            cout<<"Zapper deleted"<<endl;
            
        }
    }


    for(Killers*& k: killer_holder){
        k->draw();  //draw the bullets
        k->collision(b1->barry_x_pos(),b1->barry_y_pos());
        // if (k->zapper_delete()==true){

        // }
    }
    
}
void JetpackJoyride::createBarry(){  //to make barry on the screen

    SDL_Rect mov_b = {353, 373, 51, 63}; 
    b1=new Barry(gRenderer, assets, mov_b);
}

void JetpackJoyride::createObject(int x, int y){
    SDL_Rect mov_z = {x, y-25, 170, 55}; //fixed pos for testing
    Killers* zap = new Zapper (gRenderer,assets, mov_z );
    killer_holder.push_back(zap);
    std::cout<<"Mouse clicked at: "<<x<<" -- "<<y<<std::endl;
}

void JetpackJoyride::create_at_random(){
    random_speed_controller++;
    random_object_spacer = rand()%100;
    if (random_speed_controller%(random_speed+random_object_spacer)==0){
        int random_y_pos = rand()%400;
        //we also need to implement a random selector
        SDL_Rect mov_z = {1000, random_y_pos-25, 170, 55}; //fixed pos for testing
        Killers* zap = new Zapper (gRenderer,assets, mov_z );
        killer_holder.push_back(zap);
        std::cout<<"Zapper created at: "<<1000<<" -- "<<random_y_pos<<std::endl;
    }
}

JetpackJoyride::JetpackJoyride(SDL_Renderer *renderer, SDL_Texture *asst):gRenderer(renderer), assets(asst){

}

void JetpackJoyride::fire_jetpack(){
    // cout<<"F key is pressed"<<endl;
    b1->drop=0;
    b1->flying();
   
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