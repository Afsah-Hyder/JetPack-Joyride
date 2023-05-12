#include "coin_counter.hpp"    

#include <iostream>
// #include "JetpackJoyride.hpp"
using namespace std;

CoinCounter::CoinCounter(SDL_Renderer* rend, SDL_Texture* ast, SDL_Rect mov, int cnt):  Unit(rend, ast), mover(mov){
    cout<<"coin counter created"<<endl;
    src = {682,8, 35, 54};    //constructor, calls the parent class constructor and saves data to its own attributes too
    counter=cnt;
}

void CoinCounter::reposition(int x, int y){  //reposition the coin counter to the required x and y
    mover.x+=x;
    mover.y+=y;
    mover.w=50;
    mover.h=65;
}

void CoinCounter::draw(){
    Unit::draw(src, mover); 
    if (counter==0){
        src = {731,166, 23, 34}; //select the frame in the asset file
    } 

    else if (counter==1){
        src = {731,209, 23, 34}; //select the frame in the asset file
    }   

    else if (counter==2){
        src = {731,252, 23, 34}; //select the frame in the asset file
    }    

    else if (counter==3){
        src = {731,295, 23, 34}; //select the frame in the asset file
    } 

    else if (counter==4){
        src = {731,338, 23, 34}; //select the frame in the asset file
    } 

    else if (counter==5){
        src = {731,381, 23, 34}; //select the frame in the asset file
    } 

    else if (counter==6){
        src = {731,423, 23, 34}; //select the frame in the asset file
    } 

    else if (counter==7){
        src = {731,467, 23, 34}; //select the frame in the asset file
    } 

    else if (counter==8){
        src = {731,509, 23, 34}; //select the frame in the asset file
    } 

    else if (counter==9){
        src = {731,553, 23, 34}; //select the frame in the asset file
    } 

}

CoinCounter::~CoinCounter(){
    cout<<"Coin destroyed"<<endl;
}


void CoinCounter::add(CoinCounter *obj){  //to increase the counter of the other object
    obj->counter++;
    // counter=0;
}

void CoinCounter::operator ++ ( ){  //overloaded operator

    counter++;

    }
    


