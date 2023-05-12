#include "score_counter.hpp"    

#include <iostream>
// #include "JetpackJoyride.hpp"
using namespace std;

ScoreCounter::ScoreCounter(SDL_Renderer* rend, SDL_Texture* ast, SDL_Rect mov,int cnt):  Unit(rend, ast), mover(mov){
    cout<<"score counter created"<<endl;
    src = {682,8, 35, 54};    //constructor, calls the parent class constructor and saves data to its own attributes too
    counter=cnt;
}

void ScoreCounter::reposition(int x, int y){
    //increase the size and reposition to the required x and y
    mover.x+=x;
    mover.y+=y;
    mover.w=80;
    mover.h=110;
}

void ScoreCounter::draw(){   //draw the score counter
    Unit::draw(src, mover); 
    if (counter==0){
        src = {682,8, 35, 54}; //selecting the image from asset file
    } 

    else if (counter==1){
        src = {682,67, 35, 54}; //selecting the image from asset file
    }   

    else if (counter==2){
        src = {682,126, 35, 54}; //selecting the image from asset file
    }    

    else if (counter==3){
        src = {682,185, 35, 54}; //selecting the image from asset file
    } 

    else if (counter==4){
        src = {682,242, 35, 54}; //selecting the image from asset file
    } 

    else if (counter==5){
        src = {682,301, 35, 54}; //selecting the image from asset file
    } 

    else if (counter==6){
        src = {682,360, 35, 54}; //selecting the image from asset file
    } 

    else if (counter==7){
        src = {682,418, 35, 54}; //selecting the image from asset file
    } 

    else if (counter==8){
        src = {682,476, 35, 54}; //selecting the image from asset file
    } 

    else if (counter==9){
        src = {682,535, 35, 54}; //selecting the image from asset file
    } 

}

ScoreCounter::~ScoreCounter(){
    // cout<<"Horizontal Zapper destroyed"<<endl;
}

void ScoreCounter::operator ++ ( ){
    counter++;  //increase the internal counter
  
    trigger=false;
    if (counter==10){    //turn over
        trigger=true;
        counter=0;

    }
    

}

