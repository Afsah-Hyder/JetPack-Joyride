#pragma once

class Killers{
    protected:
    int frame_speed=6; //to control the killer animation speed
    public:
    Killers(); //constructor
    
    virtual void draw()=0;  //pure virual function to draw the killer
    virtual bool collision(int barry_x, int barry_y)=0;  //pure virtual function to detect collision
    virtual bool delete_item()=0; //pure virtual delete_item function to delete the killer object
    virtual ~Killers();  //virtual destructor so that the child is destroyed instead of the parent

};