#include "game.hpp"
#include "JetpackJoyride.hpp"
#include<vector>
#include "fx.hpp"
int bg_speed=4;
// int bg_selector=0;
// int x;
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

bool Game::run1( )
{	
	SDL_QueryTexture(gTexture, NULL, NULL, &bgWidth, &bgHeight);
	SDL_Rect bgRect = {0, 0, bgWidth, bgHeight};
	bool quit = false;
	SDL_Event e;
	JetpackJoyride JetpackJoyride(gRenderer, assets);
	while( !quit ){
		if( Mix_PlayingMusic() == 0 )
			{	
				// Mix_PlayMusic(jetpacksound,0);
				// Play the music
				Mix_PlayMusic( bgMusic,-1 );
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
		}
		SDL_RenderClear(gRenderer); //removes everything from renderer
		SDL_RenderCopy(gRenderer, gTexture, NULL, &bgRect);//Draws background to renderer

		SDL_RenderPresent(gRenderer); //displays the updated renderer

		SDL_Delay(200);	//causes sdl engine to delay for specified miliseconds
	}
}

void Game::run2(){
	cout<<"run2 called"<<endl;
	SDL_QueryTexture(gTexture, NULL, NULL, &bgWidth, &bgHeight);
	SDL_Rect bgRect = {0, 0, bgWidth, bgHeight};
	bool quit = false;
	SDL_Event e;
	JetpackJoyride JetpackJoyride(gRenderer, assets);
	FX effects;
	effects.initialize();
	effects.load();
	JetpackJoyride.createBarry();
	while( !quit )
	{	
		
		if( Mix_PlayingMusic() == 0 )
			{	
				// effects.effect('c');
				// Mix_PlayMusic(jetpacksound,0);
				// Play the music
				Mix_PlayMusic( bgMusic,-1 );
			}
		
		//Handle events on queue
		while( SDL_PollEvent( &e ) != 0 )
		{
			

			//User requests quit
			if( e.type == SDL_QUIT )
			{
				quit = true;
				// return 999;                       //so it exits the while loop in main
			}

			if(e.type == SDL_MOUSEBUTTONDOWN){
			//this is a good location to add pigeon in linked list.
				int xMouse, yMouse;
				SDL_GetMouseState(&xMouse,&yMouse);
				// JetpackJoyride.createObject(xMouse, yMouse);
				// Mix_PlayMusic( firesound, 2 );
				// effects.effect('c');
			}

			if(e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_SPACE){
				JetpackJoyride.fire_jetpack();
				// effects.effect('j');
					
					
				}

			if(e.type == SDL_KEYUP && e.key.keysym.sym == SDLK_SPACE){
				JetpackJoyride.jetpack_off();
				
					
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
		bgRect.y = bgRect.y-460;
		if (bgRect.y==-1840){
			bgRect.y=0;
			}
		}
		JetpackJoyride.create_at_random();
		SDL_Delay(9);	//causes sdl engine to delay for specified miliseconds
	}
}