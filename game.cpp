#include "game.hpp"
#include "JetpackJoyride.hpp"
#include<vector>
int bg_speed=4;
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
	bgMusic = Mix_LoadMUS( "bg_music.ogg" );
	jetpacksound = Mix_LoadMUS ("jetpack_jet_lp.wav");
	if(bgMusic == NULL or jetpacksound==NULL){
		printf("Unable to load music: %s \n", Mix_GetError());
		success = false;
	}
	assets = loadTexture("assets.png");
    gTexture = loadTexture("Sector1_new_1.png");
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


void Game::run( )
{	
	SDL_QueryTexture(gTexture, NULL, NULL, &bgWidth, &bgHeight);
	SDL_Rect bgRect = {0, 0, bgWidth, bgHeight};
	bool quit = false;
	SDL_Event e;
	
	
	JetpackJoyride JetpackJoyride(gRenderer, assets);
	JetpackJoyride.createBarry();
	while( !quit )
	{	if( Mix_PlayingMusic() == 0 )
			{	
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
			}

			if(e.type == SDL_MOUSEBUTTONDOWN){
			//this is a good location to add pigeon in linked list.
				int xMouse, yMouse;
				SDL_GetMouseState(&xMouse,&yMouse);
				JetpackJoyride.createObject(xMouse, yMouse);
				// Mix_PlayMusic( firesound, 2 );
			}

			if(e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_SPACE){
				JetpackJoyride.fire_jetpack();
				// if( Mix_PlayingMusic() == 0 )
				// {
					//Play the music
					// Mix_PlayMusic( bgMusic, 2);
					// x+=speed;
					// camera.x+=speed;
					
					
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
	    SDL_Delay(10);	//causes sdl engine to delay for specified miliseconds
	}
			
}
