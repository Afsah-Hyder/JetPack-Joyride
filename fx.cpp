#include "fx.hpp"
#include <iostream>

using namespace std;



void FX::initialize()
{   if (Mix_Init(MIX_INIT_OGG | MIX_INIT_MP3) != 0) {
    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
    {
        printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
    }
    }
}

void FX::load()
{
    jetpack = Mix_LoadWAV( "music/jetpack_plain_lp.wav" );
    if( jetpack == NULL )
    {
        printf( "Failed to load scratch sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
    }
    coin = Mix_LoadWAV( "music/coin.wav"  );
    if( coin == NULL )
    {
        printf( "Failed to load scratch sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
    }
    // touch = Mix_LoadWAV( ".\\music\\touch.wav" );
    // if( touch == NULL )
    // {
    //     printf( "Failed to load scratch sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
    // }

    // menuMusic = Mix_LoadWAV( ".\\music\\menumusic.mp3" );
    // if( stomp == NULL )
    // {
    //     printf( "Failed to load scratch sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
    // }     
    
    zapped = Mix_LoadWAV( "music/zapper.wav" );
    if( zapped == NULL )
    {
        printf( "Failed to load scratch sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
    }    

}

void FX::destroy()
{
    Mix_FreeChunk( jetpack);
    Mix_FreeChunk( zapped);
    Mix_FreeChunk( coin );
    // Mix_FreeChunk( die );
    jetpack = NULL;
    zapped = NULL;
    coin = NULL;
    // touch = NULL;
}

void FX::effect(char choice)
{
    

    if (choice == 'j')
    {   Mix_VolumeChunk(jetpack, 32);
    
        Mix_PlayChannel( -1, jetpack, 0 );
        Mix_FadeOutChannel(1, 100);
    }

    if (choice == 'z')
    {
        Mix_PlayChannel( -1, zapped, 0 );
    }

    if (choice == 'c')
    {   Mix_VolumeChunk(coin, 32);
        Mix_PlayChannel( -1, coin, 0 );

        cout<<"Coin chime"<<endl;
    }

    // if (choice == 'd')
    // {
    //     Mix_PlayChannel( -1, die, 0 );
    // }
}


