#include "score_counter.hpp"    

#include <iostream>
// #include "JetpackJoyride.hpp"
using namespace std;

ScoreCounter::ScoreCounter(SDL_Renderer* rend, SDL_Texture* ast, SDL_Rect mov):  Unit(rend, ast), mover(mov){
    cout<<"Zapper created"<<endl;
    src = {682,8, 35, 54};    //constructor, calls the parent class constructor and saves data to its own attributes too
}

void ScoreCounter::draw(){
    Unit::draw(src, mover); 
    if (counter==0){
        src = {682,8, 35, 54};
    } 

    else if (counter==1){
        src = {682,67, 35, 54};
    }   

    else if (counter==2){
        src = {682,126, 35, 54};
    }    

    else if (counter==3){
        src = {682,185, 35, 54};
    } 

    else if (counter==4){
        src = {682,242, 35, 54};
    } 

    else if (counter==5){
        src = {682,301, 35, 54};
    } 

    else if (counter==6){
        src = {682,360, 35, 54};
    } 

    else if (counter==7){
        src = {682,418, 35, 54};
    } 

    else if (counter==8){
        src = {682,476, 35, 54};
    } 

    else if (counter==9){
        src = {682,535, 35, 54};
    } 

}

ScoreCounter::~ScoreCounter(){
    cout<<"Horizontal Zapper destroyed"<<endl;
}

void ScoreCounter::operator ++ ( ){
    // cout<<"I AM CALLED";
    // trigger=false;
    counter++;
    // if (counter==0){
    //     trigger =false;
    // }
    // counter=
    trigger=false;
    if (counter==10){
        trigger=true;
        counter=0;

    }
    
    // // trigger=false;
    // else if (counter>99){
    //     counter =0;
    //     trigger=false;
    // }
}

