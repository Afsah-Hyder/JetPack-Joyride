#include "JetpackJoyride.hpp"
#include "barry.hpp"
#include<iostream>
// #include "Killers.hpp"
// #include "collectables.hpp";
#include "fx.hpp"
#include "ZapperH.hpp"
#include "ZapperV.hpp"
#include "coins.hpp"
#include "Missile.hpp"
#include "Laser.hpp"
#include <string.h>

// bool coin_check=true;

void JetpackJoyride::drawObjects(){
    // call draw functions of all the objects here
   


    cout<<"Barry has "<<b1->score<<" coins."<<endl;
    units->draw();
    tens->draw();
    hundreds->draw();
    units_c->draw();
    tens_c->draw();
    hundreds_c->draw();
    if (game_end==false){
    delay_counter++;
    }
    if ((delay_counter%10==0) and game_end==false){

    ++(*units);
    }
    if ((delay_counter%100==0) and game_end==false){
        ++(*tens);
        // cout<<"Tens increased"<<endl;
    }

    if (delay_counter%1000==0){
        ++(*hundreds);
        // cout<<"Tens increased"<<endl;
    }

    if (units_c->counter>10){
        ++(*tens_c);
        units_c->counter=0;
    }

    if (tens_c->counter>10){
        ++(*hundreds_c);
        tens_c->counter=0;
    }


    meter_symbol->draw({639,17,30,38},{118, 25,30,28});
    coin_symbol->draw({388,1,21,21},{118, 60,21,21} );
    
    //counter for the laser to disable other killers
    if (laser_only==true){
        laser_timer++;
        if (laser_timer>850){
            laser_timer=0;
            laser_only=false;
        }
    }

    // cout<<b1->score<<endl;
    

    killer_iter = killer_holder.begin();   //assign the initial node to the iterator
    collector_iter = collector_holder.begin(); 
    
    for (killer_iter; killer_iter!=killer_holder.end();killer_iter++){ 
        // (**killer_iter).collision(b1->barry_x_pos(),b1->barry_y_pos());  //loop to iterate over the list and remove the bullets that need to be removed
        (**killer_iter).draw();

        if((**killer_iter).collision(b1->barry_x_pos(),b1->barry_y_pos())==true){
            b1->death = true;
            cout<<"Barry killed"<<endl;
            game_end=true;
        }
        if ((**killer_iter).delete_item()==true){  //if the zapper has to be removed
            Killers* new_ptr=*killer_iter; //create a new pointer to the place the bullet to be removed is stored
            killer_holder.erase(killer_iter); //remove the bullet object
            delete new_ptr; //delete the pointer
            // cout<<"Zapper deleted"<<endl;
        }
    }
    bool coin_coll;
    for (collector_iter; collector_iter!=collector_holder.end();collector_iter++){ 
        
        (**collector_iter).draw();
        
        // audio->effect('c');
        if ((**collector_iter).collision(b1->barry_x_pos(),b1->barry_y_pos())==true){
            b1->score+=1;
            ++(*units_c);
            audio->effect('c');
            
        }
        if ((**collector_iter).coin_delete()==true){  //if the zapper has to be removed
            Collectables* new_ptr=*collector_iter; //create a new pointer to the place the bullet to be removed is stored
            collector_holder.erase(collector_iter); //remove the bullet object
            delete new_ptr; //delete the pointer

            // cout<<"Coin deleted"<<endl;
        }
    }

    b1->draw();  //draw Barry
}
void JetpackJoyride::createBarry(){  //to make barry on the screen

    SDL_Rect mov_b = {353, 373, 51, 63}; 
    b1=new Barry(gRenderer, assets, mov_b);
}

void JetpackJoyride::create_at_random(){
    if (game_end==false){
    random_speed_controller++;
    random_object_spacer = rand()%100;
    int check=random_speed_controller%(random_speed+random_object_spacer+200);
    // if (random_object_spacer>=20 && random_object_spacer<=40){
    if(check==8 and laser_only==false){
        int h_v=rand()%2;
        if (h_v==0){
            int random_y_pos = rand()%400;
            //we also need to implement a random selector


            SDL_Rect mov_z = {1000, random_y_pos-25, 170, 55}; //fixed pos for testing
            Killers* zap = new Zapper_h (gRenderer,assets, mov_z );
            killer_holder.push_back(zap);
            // std::cout<<"Zapper_h created at: "<<1000<<" -- "<<random_y_pos<<std::endl;
        }
        else{
            int random_y_pos = rand()%290 + 30;
            //we also need to implement a random selector
            SDL_Rect mov_z = {1000, random_y_pos, 55, 170}; //fixed pos for testing
            Killers* zap = new Zapper_v (gRenderer,assets, mov_z );
            killer_holder.push_back(zap);
            // std::cout<<"Zapper_v created at: "<<1000<<" -- "<<random_y_pos<<std::endl;
        }
    }

    else if(check==0 and laser_only==false){
        //testing for bullets
        // SDL_Rect mov_bullet = {850,200,45,45};
        int laser_occurance_reducer = rand()%10;
        if (laser_occurance_reducer>7){
        int y_laser = rand()%300;
        SDL_Rect mov_laser = {0,y_laser,900,70};
        // Killers* missile = new Missile(gRenderer,assets, mov_bullet );
        Killers* laser = new Lasers(gRenderer,assets, mov_laser);
        
        // killer_holder.push_back(missile);
        killer_holder.push_back(laser);
        laser_only=true;
        }
    }

    else if(check==2 and laser_only==false){
        //testing for bullets
        SDL_Rect mov_bullet = {850,200,45,45};
        // SDL_Rect mov_laser = {50,200,750,200};
        Killers* missile = new Missile(gRenderer,assets, mov_bullet );
        // Killers* laser = new Lasers(gRenderer,assets, mov_laser);
        
        killer_holder.push_back(missile);
        // killer_holder.push_back(laser);
    }

    


    //coin creation
    else if(check==3 && coin_check){
        coin_check=false;
        int rect_x=rand()%4 +4;
        int rect_y=rand()%2 +2;
        int random_y_pos = rand()%320 +25;
        for (int j=0; j<rect_y;j++){
            for(int i=0; i<rect_x;i++){
                SDL_Rect mov_c={1000+(i*28), random_y_pos+(j*28),20,20};
                Collectables* coin_rect=new Coins(gRenderer,assets,mov_c);
                collector_holder.push_back(coin_rect);
                // std::cout<<"Coin created at: "<<1020<<" -- "<<random_y_pos<<std::endl;
            }
        }
        // SDL_Delay(10);	//causes sdl engine to delay for specified miliseconds
        coin_check=true;
    }
    }
}

JetpackJoyride::JetpackJoyride(SDL_Renderer *renderer, SDL_Texture *asst):gRenderer(renderer), assets(asst){
    audio=   new FX();
    audio->initialize();
    audio->load();
    SDL_Rect mov_u = {86,10,36,45};
    SDL_Rect mov_t = {54,10,36,45};
    SDL_Rect mov_h = {22,10,36,45};
    units = new ScoreCounter(gRenderer, assets, mov_u);
    tens = new ScoreCounter(gRenderer, assets, mov_t);
    hundreds = new ScoreCounter(gRenderer, assets, mov_h);
    meter_symbol = new Unit(gRenderer, assets);

    //coin counter stuff
    SDL_Rect mov_uc = {86,53,25,31};
    SDL_Rect mov_tc = {60,53,25,31};
    SDL_Rect mov_hc = {35,53,25,31};
    units_c = new CoinCounter(gRenderer, assets, mov_uc);
    tens_c = new CoinCounter(gRenderer, assets, mov_tc);
    hundreds_c = new CoinCounter(gRenderer, assets, mov_hc);
    coin_symbol = new Unit(gRenderer, assets);

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
    cout<<"Score "<<b1->score<<endl;
    cout<<"Everything destroyed!"<<endl;
}

