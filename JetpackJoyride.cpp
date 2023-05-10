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
#include "red_lights.hpp"

// bool coin_check=true;

void JetpackJoyride::drawObjects(){
    // call draw functions of all the objects here

    if (bselector==2 and once_only==false){
        for (int i=0; i<9;i++){
        SDL_Rect mov_l = {2308+i*368.5,6,140,140};
        Background_Elements* rlights = new RedLights(gRenderer, assets, mov_l);
        bg_elements.push_back(rlights);
    }
    once_only=true;
    }

    //counter to add an delay between when barry dies and the end-screen appears
   if(dying_counter>=1){
    dying_counter+=1;
   }

    //condition for the end-screen to appear once the dying_counter reaches a specific value
    if(dying_counter>=250){
    end_screen->draw({1042, 248, 632, 323}, {0,0,900,460}); //draw the end screen
    if (repositioned==false){
        units_c->reposition(440, 242); //reposition the coins unit counter to the middle of the screen
        tens_c->reposition(410, 242); //reposition the coins tens counter to the middle of the screen
        hundreds_c->reposition(370, 242); //reposition the coins hundreds counter to the middle of the screen

        units->reposition(365, 100);  //reposition the distance unit counter to the middle of the screen
        tens->reposition(335, 100); //reposition the distance tens counter to the middle of the screen
        hundreds->reposition(305,100); //reposition the distance hundreds counter to the middle of the screen

        repositioned=true; //stop the repositioning
    }
    }   
    
    if (units_c->counter>9){  //condition for the units coin counter to reset to zero and the tens counter to increase by 1
        units_c->add(tens_c);
        units_c->counter=0;
    }
    if (tens_c->counter>9){  //condition for the tens coin counter to reset to zero and the hundreds counter to increase by 1
        tens_c->add(hundreds_c);
        tens_c->counter=0;
    }

    //to draw the counters
    units->draw();
    tens->draw();
    hundreds->draw();
    units_c->draw();
    tens_c->draw();
    hundreds_c->draw();

    if (game_end==false){ //count the meters barry has ran while the game is running
    delay_counter++;
    }
    if ((delay_counter%10==0) and game_end==false){  //add a delay to the units score counter
    ++(*units);
    }
    if ((delay_counter%100==0) and game_end==false){ //continue on the delay of 10 to the tens score counter
        ++(*tens);
        
    }

    if (delay_counter%1000==0){  //continue on the delay of 10 to the hundreds score counter
        ++(*hundreds);
        // cout<<"Tens increased"<<endl;
    }
    if (repositioned==false){
        meter_symbol->draw({639,17,30,38},{118, 25,30,28});  // draw the 'M' next to the score
        coin_symbol->draw({388,1,21,21},{118, 60,21,21} );  //draw the coin symbol next to the coin counter
    }
    

    //counter for the laser to disable other killers while it is active
    if (laser_only==true){
        laser_timer++;
        if (laser_timer>850){
            laser_timer=0;
            laser_only=false;
        }
    }


    killer_iter = killer_holder.begin();   //assign the initial node to the iterator
    collector_iter = collector_holder.begin();  //assign the initial node to the iterator
    
    for (killer_iter; killer_iter!=killer_holder.end();killer_iter++){   //start the for loop to iterate over the list
        (**killer_iter).draw(); //draw the object present in the list

        if((**killer_iter).collision(b1->barry_x_pos(),b1->barry_y_pos())==true){  //if barry has collided with the killer object
            b1->death = true;  //set barry's member bool variable to true to start dying animation
            // cout<<"Barry killed"<<endl;
            game_end=true;  //make the Jetpack Joyride member bool variable to true to start end procedure
            dying_counter=1;  //setting the counter to one so that the counter starts counting
        }
        if ((**killer_iter).delete_item()==true){  //if the killer has to be removed
            Killers* new_ptr=*killer_iter; //create a new pointer to the place the killer to be removed is stored
            killer_holder.erase(killer_iter); //remove the killer object
            delete new_ptr; //delete the pointer
            
        }
    }
    bool coin_coll;
    for (collector_iter; collector_iter!=collector_holder.end();collector_iter++){  //start the for loop to iterate over the list
        
        (**collector_iter).draw();  //draw te collectible
        int x=(**collector_iter).collision(b1->barry_x_pos(),b1->barry_y_pos()); //see if barry has collided with the collectible
        // audio->effect('c');
        if (x==1){  // '1' stands for coin i.e the object was a coin
            b1->score+=1; //increase barry's score by 1
            ++(*units_c); //increase coin counter by 1
            audio->effect('c'); //play coin sound
        }
        else if (x==2){  //if the collectible is the score booster
            // cout<<"boosted"<<endl;
            b1->score+=10; //increase the score by 10
            tens_c->counter++; //increase the score keeper object by 10
            // units_c->add(tens_c);
            audio->effect('c'); 
        }
        if ((**collector_iter).coin_delete()==true){  //if the collectible has to be removed
            Collectables* new_ptr=*collector_iter; //create a new pointer to the place the collectible to be removed is stored
            collector_holder.erase(collector_iter); //remove the collectible object
            delete new_ptr; //delete the pointer

        }
    }

    bg_element_iter = bg_elements.begin();    //assign the initial node to the iterator
    for (bg_element_iter; bg_element_iter!=bg_elements.end();bg_element_iter++){ //start the for loop
        
        (**bg_element_iter).draw(); //draw the background element
        if ((**bg_element_iter).delete_item()==true){
            Background_Elements* new_ptr=*bg_element_iter; //create a new pointer to the place the collectible to be removed is stored
            bg_elements.erase(bg_element_iter); //remove the collectible object
            delete new_ptr; //delete the pointer
        }
        
    }

    b1->draw();  //draw Barry
}
void JetpackJoyride::createBarry(){  //to make barry on the screen

    SDL_Rect mov_b = {353, 373, 51, 63}; 
    b1=new Barry(gRenderer, assets, mov_b);
}


void JetpackJoyride::create_at_random(){ //this function deals with the creation of all kinds of objects
    if (game_end==false){ //if the game hasn't ended yet
    random_speed_controller++; //to place objects at random distances
    random_object_spacer = rand()%100; //to ensure that objects dont overlap
    int check=random_speed_controller%(random_speed+random_object_spacer+200); //to determine which kind of object to create
    
    if(check==8 and laser_only==false){  //to create the zappers with the highest frequency when the laser is off
        int h_v=rand()%2; //to determine whether to create a horizontal or verticle zapper
        if (h_v==0){
            int random_y_pos = rand()%400; //randomly decide where to create the object
            


            SDL_Rect mov_z = {1000, random_y_pos-25, 170, 55}; 
            Killers* zap = new Zapper_h (gRenderer,assets, mov_z );  //create a new zapper object
            killer_holder.push_back(zap);  //push the object into the list
            
        }
        else{
            int random_y_pos = rand()%290 + 30;
            SDL_Rect mov_z = {1000, random_y_pos, 55, 170}; 
            Killers* zap = new Zapper_v (gRenderer,assets, mov_z ); //create a new zapper dynamically
            killer_holder.push_back(zap); //push the zapper into the list
            
        }
    }

    else if(check==0 and laser_only==false){  //make lasers with the least occurance
        
        int laser_occurance_reducer = rand()%10;
        if (laser_occurance_reducer>7){ //to further reduce the occurance of lasers
        int y_laser = rand()%300;
        SDL_Rect mov_laser = {0,y_laser,900,70};
        
        Killers* laser = new Lasers(gRenderer,assets, mov_laser); //create a new laser object
        
        killer_holder.push_back(laser);  //push the laser into the list
        laser_only=true;  //make this variable true so that other kinds of killers are not made when the laser is on
        }
    }
    else if(check==1){  //to make the score booster
        SDL_Rect mov_b={950,rand()%320 +25, 45,45};
        Collectables* booster_rect=new Score_booster(gRenderer,assets,mov_b); //create dynamically
        collector_holder.push_back(booster_rect); //push into list
    } 

    else if(check==2){
        
        SDL_Rect mov_bullet = {850,200,45,45};
        Killers* missile = new Missile(gRenderer,assets, mov_bullet ); //create missile dynamically
        
        
        killer_holder.push_back(missile);  //push the missile into the list
        
    }

    else if(check==4){ //to create the scientist
        SDL_Rect mov_scientist = {1000,365,52,61};
        Background_Elements* scientist = new Scientist(gRenderer,assets, mov_scientist); //create dynamically 
        
        bg_elements.push_back(scientist); //push the scientist into the list
    }

    else if(check==5 and laser_only==false){  //to create the wreaking ball
        int ball_occurance_reducer = rand()%10;  //to reduce the occurance of the ball further
        if (ball_occurance_reducer>7){
        SDL_Rect mov_b = {850, 340, 45, 45};
        Killers *ball = new WreakingBall(gRenderer,assets,mov_b); //create dynamically
        killer_holder.push_back(ball);  //push the ball into the killers list
        }
    }


    //coin creation
    else if(check==3 && coin_check){  //for coins
        coin_check=false;
        int rect_x=rand()%4 +4;
        int rect_y=rand()%2 +2;
        int random_y_pos = rand()%320 +25;
        //loop to create a random pattern of coins everytime
        for (int j=0; j<rect_y;j++){
            for(int i=0; i<rect_x;i++){
                SDL_Rect mov_c={1000+(i*28), random_y_pos+(j*28),20,20};
                Collectables* coin_rect=new Coins(gRenderer,assets,mov_c); //create dynamically
                collector_holder.push_back(coin_rect); //push the coins in the collectibles list
            }
        }
        coin_check=true; //to control when coins are made
    }
    }
}


//constructor for Jetpack Joyride
JetpackJoyride::JetpackJoyride(SDL_Renderer *renderer, SDL_Texture *asst):gRenderer(renderer), assets(asst){
    audio=   new FX();  //create an object of the FX class dynamically
    audio->initialize(); //initialize it
    audio->load(); //load the audio files

    //Score counter creation
    SDL_Rect mov_u = {86,10,36,45};
    SDL_Rect mov_t = {54,10,36,45};
    SDL_Rect mov_h = {22,10,36,45};
    units = new ScoreCounter(gRenderer, assets, mov_u);
    tens = new ScoreCounter(gRenderer, assets, mov_t);
    hundreds = new ScoreCounter(gRenderer, assets, mov_h);
    meter_symbol = new Unit(gRenderer, assets);

    //coin counter creation
    SDL_Rect mov_uc = {86,53,25,31};
    SDL_Rect mov_tc = {60,53,25,31};
    SDL_Rect mov_hc = {35,53,25,31};
    units_c = new CoinCounter(gRenderer, assets, mov_uc);
    tens_c = new CoinCounter(gRenderer, assets, mov_tc);
    hundreds_c = new CoinCounter(gRenderer, assets, mov_hc);
    coin_symbol = new Unit(gRenderer, assets);

    //end screen creation
    end_screen=new Unit(gRenderer, assets);

    

}

void JetpackJoyride::fire_jetpack(){
    
    b1->drop=0; // to stop dropping animation
    b1->flying(); //to make barry rise and play the right animations
   
}

void JetpackJoyride::jetpack_off(){
    b1->drop=1; //play the falling animation
}

JetpackJoyride::~JetpackJoyride(){  //destructor for the JetpackJoyride
    

    for (Killers*& k: killer_holder){ //emptying the killers list
        delete k;
        k=NULL;
        k=nullptr;
    }
    for (Collectables*& c: collector_holder){  //emptying the collectibles list
        delete c;
        c=NULL;
        c=nullptr;
    }

    for (Background_Elements*& b: bg_elements){  //emptying the bg_elements list
        delete b;
        b=NULL;
        b= nullptr;
    }

    collector_holder.clear();
    killer_holder.clear();
    bg_elements.clear();

    //delete the audio object
    delete []audio;
    audio = nullptr;
    cout<<"Score "<<b1->score<<endl;
    cout<<"Everything destroyed!"<<endl;
}

