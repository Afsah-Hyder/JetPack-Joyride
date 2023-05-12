#pragma once
#include<SDL.h>
#include "barry.hpp"
#include "Killers.hpp"
#include "collectables.hpp"
#include "fx.hpp"
#include<list>
#include "score_counter.hpp"
#include "coin_counter.hpp"
#include "wreaking_ball.hpp"
#include "Background_Elements.hpp"
using namespace std;
class JetpackJoyride{
    
    SDL_Renderer *gRenderer;
    SDL_Texture *assets;
    list <Killers*> killer_holder;
    list<Killers*>::iterator killer_iter;  //iterator for the list of Killers* objects
    list <Collectables*> collector_holder;  //list of type Collectibles*
    list<Collectables*>::iterator collector_iter;  //iterator of the list of Collectibles*
    list<Background_Elements*> bg_elements;  //list of type Background_Elements
    list<Background_Elements*>::iterator bg_element_iter;  //iterator of the list of Background_Elements
    bool coin_check=true;
    bool coin_collected_once=false;  //coin collected only once
    public:
    //function sketches
    Barry *b1;  //Barry object
    FX* audio;  //FX* object
    JetpackJoyride(SDL_Renderer *, SDL_Texture *);
    void createBarry();
    void drawObjects(); 
    // void createObject(int, int);
    void fire_jetpack();
    void jetpack_off();
    void create_at_random();
    // bool end_game();
    int random_speed_controller=0;  //to control the rate at which objects are made
    int random_speed=160; //the greater the number, the slower the creation of random objects
    int random_object_spacer=0; //creates objects sepated by random distances
    ~JetpackJoyride();  //destructor
    int laser_timer=0;
    bool laser_only=false;
    bool repositioned=false;
   
    //Score Keeper Section
    ScoreCounter* units;
    ScoreCounter* tens;
    ScoreCounter* hundreds;
    ScoreCounter* thousands;
    Unit* meter_symbol;

    //Best Score Keeper Section
    ScoreCounter* units_b;
    ScoreCounter* tens_b;
    ScoreCounter* hundreds_b;
    ScoreCounter* thousands_b;

    //Coin Keeper Section
    CoinCounter* units_c;
    CoinCounter* tens_c;
    CoinCounter* hundreds_c;
    Unit* coin_symbol;

    //Miscellaneous  Objects
    Unit* end_screen;
    Unit* best_symbol;
    // SDL_Rect meter_pos = {639,17,30,38};


    //counters for the game end sequence
    int delay_counter=0;
    int dying_counter=0;
    bool once_only=false;
    // bool laser_delay
    public:
    
    int bselector=1;
   
    bool game_end=false;
    float object_speed;
    void text_file_generator(); //function to keep the best score
    int best_score[4];  //int array to hold the digits of the best score
    int current_score[4];  //int array to hold the digits of the current score
    void best_score_keeper();  //function to load the last best score into the game
};