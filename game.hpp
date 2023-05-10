#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <SDL_mixer.h>
#include "score_counter.hpp"
#include "coin_counter.hpp"

class Game{
    //Screen dimension constants
    const int SCREEN_WIDTH = 900;
    const int SCREEN_HEIGHT = 460;

    //The window we'll be rendering to
    SDL_Window* gWindow = NULL;

    //The window renderer
    SDL_Renderer* gRenderer = NULL;
    SDL_Rect camera;
    //Current displayed texture
    SDL_Texture* gTexture = NULL;
    // SDL_Texture* bg2 = NULL;
    // SDL_Texture* bg3 = NULL;
    // SDL_Texture* bg4 = NULL;
    // SDL_Texture* bg5 = NULL;
    // SDL_Texture* bg6 = NULL;
    //global reference to png image sheets
    SDL_Texture* assets=NULL;
    const char* screen[4]={"Start_screen.jpeg","Instructions_screen.png","Sector1_new_3.png","end_screen_transparent.jpeg"};
    int bg_selector=0;
    int score=0;
    int distance=0;

    ScoreCounter* units;
    ScoreCounter* tens;
    ScoreCounter* hundreds;
    CoinCounter* units_c;
    CoinCounter* tens_c;
    CoinCounter* hundreds_c;
public:
    Mix_Music *bgMusic = NULL;
    Mix_Music *startscreen=NULL;
    Mix_Music *jetpacksound = NULL;
    float bgspeed;
    bool init();
    bool loadMedia();
    void close();
    // SDL_Rect bgRect;
    SDL_Texture* loadTexture( std::string path );
    bool run1();
    bool run2();
};
