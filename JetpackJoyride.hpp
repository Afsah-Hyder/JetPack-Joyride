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
    list<Killers*>::iterator killer_iter;  //iterator for the list of Bullet* objects
    list <Collectables*> collector_holder;
    list<Collectables*>::iterator collector_iter;
    list<Background_Elements*> bg_elements;
    list<Background_Elements*>::iterator bg_element_iter;
    bool coin_check=true;
    bool coin_collected_once=false;
    public:
    //function sketches
    Barry *b1;
    FX* audio;
    JetpackJoyride(SDL_Renderer *, SDL_Texture *);
    void createBarry();
    void drawObjects(); 
    // void createObject(int, int);
    void fire_jetpack();
    void jetpack_off();
    void create_at_random();
    // bool end_game();
    int random_speed_controller=0;
    int random_speed=160; //the greater the number, the slower the creation of random objects
    int random_object_spacer=0; //creates objects sepated by random distances
    ~JetpackJoyride();  //destructor
    int laser_timer=0;
    bool laser_only=false;
    bool repositioned=false;
    // int unit_counter=0;
    // int tens_counter=0;
    // int hundreds_counter=0;

    //Score Keeper Section
    ScoreCounter* units;
    ScoreCounter* tens;
    ScoreCounter* hundreds;
    Unit* meter_symbol;

    //Coin Keeper Section

    CoinCounter* units_c;
    CoinCounter* tens_c;
    CoinCounter* hundreds_c;
    Unit* coin_symbol;

    Unit* end_screen;
    // SDL_Rect meter_pos = {639,17,30,38};

    int delay_counter=0;
    int dying_counter=0;
    bool once_only=false;
    // bool laser_delay
    public:
    int bselector=1;
    // int score=0;
    // int distance=0;
    bool game_end=false;
    float object_speed;
};