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
    //global reference to png image sheets
    SDL_Texture* assets=NULL;
    Mix_Music *firesound = NULL;
    

public:
    // int bgWidth, bgHeight;
    // int bgWidth, bgHeight;
    bool init();
    bool loadMedia();
    void close();
    // SDL_Rect bgRect;
    SDL_Texture* loadTexture( std::string path );
    void run();
};

