#include "game.hpp"
#include<vector>
using namespace std;

int main(int argc, char *argv[]){
    Game game;
   
    srand(time(NULL));
    if( !game.init() ){
		printf( "Failed to initialize!\n" );
        return 0;
	}
    int i=0;
    bool run_check;

    //screen switching procedure
    while(i<3){
    //     	//Load media
        if( !game.loadMedia() ){
            printf( "Failed to load media!\n" );
            return 0;
        }
        int screen=i;
        switch (screen){
            case 0:
            case 1:
            case 3:
                run_check=game.run1();
                if (run_check==false){
                    i=999;
                }
                else{
                    i+=1;
                }
                break;
            case 2:
                run_check=game.run2();
                if(run_check){
                    i=2;
                }
                else{
                    i=999;
                }
                
                break;
            default:
                break;
        }
    }
    game.close();

    return 0;
}