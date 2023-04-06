// #include "InstructionScreen.hpp"

// bool InstructionScreen::init()


// {
// 	//Initialization flag
// 	bool success = true;

// 	//Initialize SDL
// 	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
// 	{
// 		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
// 		success = false;
// 	}
// 	else
// 	{
// 		//Set texture filtering to linear
// 		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
// 		{
// 			printf( "Warning: Linear texture filtering not enabled!" );
// 		}

// 		//Create window
// 		gWindow = SDL_CreateWindow( "Jetpack Joyride!", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
// 		if( gWindow == NULL )
// 		{
// 			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
// 			success = false;
// 		}
// 		else
// 		{
// 			//Create renderer for window
// 			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
// 			if( gRenderer == NULL )
// 			{
// 				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
// 				success = false;
// 			}
// 			else
// 			{
// 				//Initialize renderer color
// 				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

// 				//Initialize PNG loading
// 				int imgFlags = IMG_INIT_PNG;
// 				if( !( IMG_Init( imgFlags ) & imgFlags ) )
// 				{
// 					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
// 					success = false;
// 				}
				
// 				if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
// 				{
// 					printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
// 					success = false;
// 				}

// 			}
// 		}
// 	}

// 	return success;
// }

// bool InstructionScreen::loadMedia()
// {	
// 	//Loading success flag
// 	bool success = true;
// 	bgMusic = Mix_LoadMUS( "bg_music.ogg" );
// 	if(bgMusic == NULL){
// 		printf("Unable to load music: %s \n", Mix_GetError());
// 		success = false;
// 	}
// 	assets = loadTexture("assets.png");
//     gTexture = loadTexture("Sector1.png");
// 	if(assets==NULL || gTexture==NULL)
//     {
//         printf("Unable to run due to error: %s\n",SDL_GetError());
//         success =false;
//     }

// 	return success;
// }

// void Game::close()
// {
// 	//Free loaded images
// 	SDL_DestroyTexture(assets);
// 	assets=NULL;
// 	SDL_DestroyTexture(gTexture);
	
// 	//Destroy window
// 	SDL_DestroyRenderer( gRenderer );
// 	SDL_DestroyWindow( gWindow );
// 	gWindow = NULL;
// 	gRenderer = NULL;
// 	//Quit SDL subsystems
// 	IMG_Quit();
// 	SDL_Quit();
// }
// int bgWidth;
// int bgHeight;

// SDL_Texture* Game::loadTexture( std::string path )
// {	
// 	//The final texture
// 	SDL_Texture* newTexture = NULL;

// 	//Load image at specified path
// 	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
// 	if( loadedSurface == NULL )
// 	{
// 		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
// 	}
// 	else
// 	{
// 		//Create texture from surface pixels
//         newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
// 		if( newTexture == NULL )
// 		{
// 			printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
// 		}

// 		//Get rid of old loaded surface
// 		SDL_FreeSurface( loadedSurface );
// 	}

// 	return newTexture;
// }