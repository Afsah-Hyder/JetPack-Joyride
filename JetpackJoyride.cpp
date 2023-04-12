#include "JetpackJoyride.hpp"
#include "barry.hpp"
#include<iostream>
// #include "Killers.hpp";
// #include "collectables.hpp";
#include "Zapper.hpp"
#include "coins.hpp"

// bool coin_check=true;

void JetpackJoyride::drawObjects(){
    // call draw functions of all the objects here
    // for (Tank*& t: tanks)
    
    b1->draw();  //draw Barry

    killer_iter = killer_holder.begin();   //assign the initial node to the iterator
    collector_iter = collector_holder.begin(); 
    
    for (killer_iter; killer_iter!=killer_holder.end();killer_iter++){ 
        // (**killer_iter).collision(b1->barry_x_pos(),b1->barry_y_pos());  //loop to iterate over the list and remove the bullets that need to be removed
        (**killer_iter).draw();
        (**killer_iter).collision(b1->barry_x_pos(),b1->barry_y_pos());
        if ((**killer_iter).zapper_delete()==true){  //if the zapper has to be removed
            Killers* new_ptr=*killer_iter; //create a new pointer to the place the bullet to be removed is stored
            killer_holder.erase(killer_iter); //remove the bullet object
            delete new_ptr; //delete the pointer
            cout<<"Zapper deleted"<<endl;
        }
    }
    bool coin_coll;
    for (collector_iter; collector_iter!=collector_holder.end();collector_iter++){ 
        // (**killer_iter).collision(b1->barry_x_pos(),b1->barry_y_pos());  //loop to iterate over the list and remove the bullets that need to be removed
        (**collector_iter).draw();
        if ((**collector_iter).collision(b1->barry_x_pos(),b1->barry_y_pos())==true){
            b1->score+=5;
            Collectables* new_ptr=*collector_iter; //create a new pointer to the place the bullet to be removed is stored
            collector_holder.erase(collector_iter); //remove the bullet object
            delete new_ptr; //delete the pointer
            cout<<"Coin deleted"<<endl;
        }
        if ((**collector_iter).coin_delete()==true){  //if the zapper has to be removed
            Collectables* new_ptr=*collector_iter; //create a new pointer to the place the bullet to be removed is stored
            collector_holder.erase(collector_iter); //remove the bullet object
            delete new_ptr; //delete the pointer
            cout<<"Coin deleted"<<endl;
        }
    }

    // for(Killers*& k: killer_holder){
    //     k->draw();  //draw the bullets
    //     k->collision(b1->barry_x_pos(),b1->barry_y_pos());
    // }
    
    // for(Collectables*& c: collector_holder){
    //     c->draw();  //draw the bullets
    //     coin_coll=c->collision(b1->barry_x_pos(),b1->barry_y_pos());
    //     if (coin_coll==true){
    //         Collectables* new_ptr=*collector_iter; //create a new pointer to the place the bullet to be removed is stored
    //         collector_holder.erase(collector_iter); //remove the bullet object
    //         delete new_ptr; //delete the pointer
    //         cout<<"Coin deleted"<<endl;
    //     }
    // }
    
}
void JetpackJoyride::createBarry(){  //to make barry on the screen

    SDL_Rect mov_b = {353, 373, 51, 63}; 
    b1=new Barry(gRenderer, assets, mov_b);
}

void JetpackJoyride::create_at_random(){
    // std::cout<<"coin_check  "<<coin_check<<std::endl;
    random_speed_controller++;
    random_object_spacer = rand()%100;
    int check=random_speed_controller%(random_speed+random_object_spacer);
    // if (random_object_spacer>=20 && random_object_spacer<=40){
    if(check==0){
        int random_y_pos = rand()%400;
        //we also need to implement a random selector
        SDL_Rect mov_z = {1000, random_y_pos-25, 170, 55}; //fixed pos for testing
        Killers* zap = new Zapper (gRenderer,assets, mov_z );
        killer_holder.push_back(zap);
        std::cout<<"Zapper created at: "<<1000<<" -- "<<random_y_pos<<std::endl;
    }

    // if (random_object_spacer>=50 && random_object_spacer<=70){
    if(check==3 && coin_check){
        coin_check=false;
        int rect_x=rand()%9 +4;
        int rect_y=rand()%5 +1;
        int random_y_pos = rand()%320 +20;
        for (int j=0; j<rect_y;j++){
            for(int i=0; i<rect_x;i++){
                SDL_Rect mov_c={1000+(i*28), random_y_pos+(j*28),20,20};
                Collectables* coin_rect=new Coins(gRenderer,assets,mov_c);
                collector_holder.push_back(coin_rect);
                std::cout<<"Coin created at: "<<1020<<" -- "<<random_y_pos<<std::endl;
            }
        }
        SDL_Delay(10);	//causes sdl engine to delay for specified miliseconds
        coin_check=true;
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
    for (Killers*& k: killer_holder){
        delete k;
        k=nullptr;
    }
    for (Collectables*& c: collector_holder){
        delete c;
        c=nullptr;
    }
    collector_holder.clear();
    killer_holder.clear();
    cout<<"Everything destroyed!"<<endl;
}