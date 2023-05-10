#include "game.hpp"
#include "JetpackJoyride.hpp"
#include<vector>
#include "fx.hpp"
float bg_speed=4;
float delay=9;
// int pause_delay;
bool isPaused=false;

bool Game::init()


{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		//Create window
		gWindow = SDL_CreateWindow( "Jetpack Joyride!", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Create renderer for window
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
			if( gRenderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = false;
				}
				
				if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
				{
					printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
					success = false;
				}

			}
		}
	}

	return success;
}

bool Game::loadMedia()
{	
	//Loading success flag
	bool success = true;
	// SDL_Event e;
	startscreen = Mix_LoadMUS( "The_Stash.mp3" );
	bgMusic = Mix_LoadMUS( "bg_music.wav" );
	jetpacksound = Mix_LoadMUS ("jetpack_jet_lp.wav");
	if(bgMusic == NULL or jetpacksound==NULL){
		printf("Unable to load music: %s \n", Mix_GetError());
		success = false;
	}
	assets = loadTexture("assets.png");

		gTexture=loadTexture(screen[bg_selector]);
	
    
	if(assets==NULL || gTexture==NULL)
    {
        printf("Unable to run due to error: %s\n",SDL_GetError());
        success =false;
    }

	return success;
}

void Game::close()
{
	//Free loaded images
	SDL_DestroyTexture(assets);
	assets=NULL;
	SDL_DestroyTexture(gTexture);
	
	//Destroy window
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;
	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}
int bgWidth;
int bgHeight;

SDL_Texture* Game::loadTexture( std::string path )
{	
	//The final texture
	SDL_Texture* newTexture = NULL;
	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	}
	else
	{
		//Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
		if( newTexture == NULL )
		{
			printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	return newTexture;
}

bool Game::run1( ){	
	SDL_QueryTexture(gTexture, NULL, NULL, &bgWidth, &bgHeight);
	SDL_Rect bgRect = {0, 0, bgWidth, bgHeight};
	bool quit = false;
	SDL_Event e;
	while( !quit ){
		if( Mix_PlayingMusic() == 0 )
			{	
				
				Mix_PlayMusic( startscreen,-1 );
			}
		while( SDL_PollEvent( &e ) != 0 )
		{
		

			//User requests quit
			if( e.type == SDL_QUIT )
			{
				quit = true;
				return false;    //so it exits the while loop in main
			}

			if((bg_selector==0) && (e.type == SDL_MOUSEBUTTONDOWN)){
				bg_selector+=1;
				return true;
			}

			if((bg_selector==1) && (e.type == SDL_MOUSEBUTTONDOWN)){
				int xMouse, yMouse;
				SDL_GetMouseState(&xMouse,&yMouse);
				if(xMouse>=542 && xMouse<=744){
					if(yMouse>=266 && yMouse<=353){
						bg_selector+=1;
						return true;
					}
				}
			}
			
		
			
		SDL_RenderClear(gRenderer); //removes everything from renderer
		SDL_RenderCopy(gRenderer, gTexture, NULL, &bgRect);//Draws background to renderer

		SDL_RenderPresent(gRenderer); //displays the updated renderer

		SDL_Delay(200);	//causes sdl engine to delay for specified miliseconds
	}
	}
}

bool Game::run2(){

	cout<<"run2 called"<<endl;
	SDL_QueryTexture(gTexture, NULL, NULL, &bgWidth, &bgHeight);
	SDL_Rect bgRect = {0, 0, bgWidth, bgHeight};
	bool quit = false;
	int dead_Counter=0;
	SDL_Event e;
	JetpackJoyride JetpackJoyride(gRenderer, assets);
	// bool check=true;
	FX effects;
	effects.initialize();
	effects.load();
	JetpackJoyride.createBarry();
	Mix_HaltMusic();
	while( !quit )
	{	
		
		if( Mix_PlayingMusic() == 0 )
			{	
				
				Mix_PlayMusic( bgMusic,-1 );
			}
		
		//Handle events on queue
		while( SDL_PollEvent( &e ) != 0 )
		{
			

			//User requests quit
			if( e.type == SDL_QUIT )
			{
				quit = true;
				return false;                       //so it exits the while loop in main
			}

			if(e.type == SDL_MOUSEBUTTONDOWN){
			//this is a good location to add pigeon in linked list.
				int xMouse, yMouse;
				SDL_GetMouseState(&xMouse,&yMouse);
				
			}

			if(e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_SPACE && !isPaused){
				JetpackJoyride.fire_jetpack();
				}

			if(e.type == SDL_KEYUP && e.key.keysym.sym == SDLK_SPACE && !isPaused){
				JetpackJoyride.jetpack_off();
			}

			if(e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_f){
				// JetpackJoyride.fire_jetpack();
				delay = 1;
				}

			if(e.type == SDL_KEYUP && e.key.keysym.sym == SDLK_f){
				// JetpackJoyride.jetpack_off();
				delay=9;
			}

			if(e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_p){
				// JetpackJoyride.fire_jetpack();
				isPaused = !isPaused;
				}

		}

		if (!isPaused){
		//to control speed of objects
		JetpackJoyride.object_speed=bg_speed;

		if (JetpackJoyride.game_end==true){
			if(bg_speed>0){
				bg_speed = bg_speed*0.993;
				dead_Counter+=1;
			}
			if(dead_Counter>=250){
				if(e.type == SDL_MOUSEBUTTONDOWN){
					int xMouse, yMouse;
					SDL_GetMouseState(&xMouse,&yMouse);
					if(xMouse>=705 && xMouse<=872){
						if(yMouse>=365 && yMouse<=430){
							bg_speed=4;
							delay = 9;
							return true;
						}
					}
				}
				
			}	
		}
		
		SDL_RenderClear(gRenderer); //removes everything from renderer
		SDL_RenderCopy(gRenderer, gTexture, NULL, &bgRect);//Draws background to renderer
		
		//***********************draw the objects here********************

		JetpackJoyride.drawObjects();
		//****************************************************************
		SDL_RenderPresent(gRenderer); //displays the updated renderer
		bgRect.x=bgRect.x-bg_speed; //moves the background
		if (bgRect.x <= -bgWidth+920) {
			bgRect.x = -40;
			delay = delay-0.4;  //to speed up the game
			bgRect.y = bgRect.y-460;
			JetpackJoyride.bselector=1;

		if (bgRect.y==-460){
			JetpackJoyride.bselector=2;
		}
		if (bgRect.y==-1840){
			bgRect.y=0;
		}
		}
		JetpackJoyride.create_at_random();
		SDL_Delay(delay);	//causes sdl engine to delay for specified miliseconds
		}	
	}
}