#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <SDL_mixer.h>


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
    const char* screen[3]={"Start_screen.jpeg","Instructions_screen.jpeg","Sector1_new_2.png"};
    int bg_selector=0;
    

public:
    Mix_Music *bgMusic = NULL;
    Mix_Music *jetpacksound = NULL;
    int bgspeed;
    bool init();
    bool loadMedia();
    void close();
    // SDL_Rect bgRect;
    SDL_Texture* loadTexture( std::string path );
    bool run1();
    void run2();
};
