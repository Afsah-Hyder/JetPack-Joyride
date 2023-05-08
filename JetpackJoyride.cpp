#include "JetpackJoyride.hpp"
#include "barry.hpp"
#include<iostream>
#include "fx.hpp"
#include "ZapperH.hpp"
#include "ZapperV.hpp"
#include "coins.hpp"
#include "Missile.hpp"
#include "Laser.hpp"
#include "scoreboost.hpp"
#include "wreaking_ball.hpp"
#include "scientist.hpp"

// bool coin_check=true;

void JetpackJoyride::drawObjects(){
    // call draw functions of all the objects here
   if(dying_counter>=1){
    dying_counter+=1;
   }
    // end_screen->draw({1042, 248, 632, 323}, {0,0,900,460});
    if(dying_counter>=250){
    end_screen->draw({1042, 248, 632, 323}, {0,0,900,460});
    if (repositioned==false){
        units_c->reposition(440, 242);
        tens_c->reposition(410, 242);
        hundreds_c->reposition(370, 242);

        units->reposition(365, 100);
        tens->reposition(335, 100);
        hundreds->reposition(305,100);

        repositioned=true;
    }
    }   
    
    if (units_c->counter>9){
        units_c->add(tens_c);
        units_c->counter=0;
    }
    if (tens_c->counter>9){
        tens_c->add(hundreds_c);
        tens_c->counter=0;
    }

    // cout<<"Barry has "<<b1->score<<" coins."<<endl;
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
    if (repositioned==false){
        meter_symbol->draw({639,17,30,38},{118, 25,30,28});
        coin_symbol->draw({388,1,21,21},{118, 60,21,21} );
    }
    
    
    // if(dying_counter>=250){
    // end_screen->draw({1042, 248, 632, 323}, {0,0,900,460});
    // }

    //counter for the laser to disable other killers
    if (laser_only==true){
        laser_timer++;
        if (laser_timer>850){
            laser_timer=0;
            laser_only=false;
        }
    }


    killer_iter = killer_holder.begin();   //assign the initial node to the iterator
    collector_iter = collector_holder.begin(); 
    
    for (killer_iter; killer_iter!=killer_holder.end();killer_iter++){ 
        // (**killer_iter).collision(b1->barry_x_pos(),b1->barry_y_pos());  //loop to iterate over the list and remove the bullets that need to be removed
        (**killer_iter).draw();

        if((**killer_iter).collision(b1->barry_x_pos(),b1->barry_y_pos())==true){
            b1->death = true;
            cout<<"Barry killed"<<endl;
            game_end=true;
            dying_counter=1;
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
        int x=(**collector_iter).collision(b1->barry_x_pos(),b1->barry_y_pos());
        // audio->effect('c');
        if (x==1){
            b1->score+=1;
            ++(*units_c);
            audio->effect('c'); 
        }
        else if (x==2){
            cout<<"boosted"<<endl;
            b1->score+=10;
            // ++(*tens_c);
            tens_c->counter++;
            // units_c->add(tens_c);
            audio->effect('c'); 
        }
        if ((**collector_iter).coin_delete()==true){  //if the zapper has to be removed
            Collectables* new_ptr=*collector_iter; //create a new pointer to the place the bullet to be removed is stored
            collector_holder.erase(collector_iter); //remove the bullet object
            delete new_ptr; //delete the pointer

            // cout<<"Coin deleted"<<endl;
        }
    }

    bg_element_iter = bg_elements.begin();
    for (bg_element_iter; bg_element_iter!=bg_elements.end();bg_element_iter++){ 
        // (**killer_iter).collision(b1->barry_x_pos(),b1->barry_y_pos());  //loop to iterate over the list and remove the bullets that need to be removed
        (**bg_element_iter).draw();
    }

    b1->draw();  //draw Barry
}
void JetpackJoyride::createBarry(){  //to make barry on the screen

    SDL_Rect mov_b = {353, 373, 51, 63}; 
    b1=new Barry(gRenderer, assets, mov_b);
}

// bool JetpackJoyride::end_game(){
//     // bool quit=false;
//     SDL_Event e1;
//     while(true){
//         end_screen->draw({1042, 248, 632, 323}, {0,0,900,460});
//         if( e1.type == SDL_QUIT ){
//         // quit=true;
//         return false;
//         }
//         if(e1.type == SDL_MOUSEBUTTONDOWN){
//             int xMouse, yMouse;
//             SDL_GetMouseState(&xMouse,&yMouse);
//             if(xMouse>=705 && xMouse<=872){
//                 if(yMouse>=365 && yMouse<=430){
                    
//                     return true;}
//             }
//         }
//     }
    
// };

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
    else if(check==1){
        SDL_Rect mov_b={950,rand()%320 +25, 45,45};
        Collectables* booster_rect=new Score_booster(gRenderer,assets,mov_b);
        collector_holder.push_back(booster_rect);
    } 

    else if(check==2){
        //testing for bullets
        SDL_Rect mov_bullet = {850,200,45,45};
        // SDL_Rect mov_laser = {50,200,750,200};
        Killers* missile = new Missile(gRenderer,assets, mov_bullet );
        // Killers* laser = new Lasers(gRenderer,assets, mov_laser);
        
        killer_holder.push_back(missile);
        // killer_holder.push_back(laser);
    }

    else if(check==4){
        //testing for bullets
        SDL_Rect mov_scientist = {1000,365,52,61}; //for scientist only right now
        // SDL_Rect mov_laser = {50,200,750,200};
        Background_Elements* scientist = new Scientist(gRenderer,assets, mov_scientist);
        // Killers* laser = new Lasers(gRenderer,assets, mov_laser);
        
        bg_elements.push_back(scientist);
        // killer_holder.push_back(laser);
    }

    else if(check==5 and laser_only==false){
        int ball_occurance_reducer = rand()%10;
        if (ball_occurance_reducer>7){
        SDL_Rect mov_b = {850, 200, 45, 45};
        Killers *ball = new WreakingBall(gRenderer,assets,mov_b);
        killer_holder.push_back(ball);
        }
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

    end_screen=new Unit(gRenderer, assets);

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
        k=NULL;
        k=nullptr;
    }
    for (Collectables*& c: collector_holder){
        delete c;
        c=NULL;
        c=nullptr;
    }

    for (Background_Elements*& b: bg_elements){
        delete b;
        b=NULL;
        b= nullptr;
    }

    collector_holder.clear();
    killer_holder.clear();
    bg_elements.clear();
    cout<<"Score "<<b1->score<<endl;
    cout<<"Everything destroyed!"<<endl;
}

