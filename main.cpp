#include "game.hpp"
#include<vector>
using namespace std;

int main(int argc, char *argv[]){
    Game game;
    // Test t1;
    // for(int i=0;i<5;i++)
    //     t1.add(i);
    srand(time(NULL));
    if( !game.init() ){
		printf( "Failed to initialize!\n" );
        return 0;
	}
    int i=0;
    bool run_check;
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
                run_check=game.run1();
                if (run_check==false){
                    i=999;
                }
                else{
                    i+=1;
                }
                break;
            case 2:
                game.run2();
                i=999;
                break;
            default:
                break;
        }
    }
    game.close();

    return 0;
}