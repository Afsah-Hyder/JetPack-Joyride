#pragma once
// #include "unit.hpp"
// #include "barry.hpp"

class Background_Elements{
    protected:
    // int frame_speed=6;
    public:
    Background_Elements();
    
    virtual void draw()=0;
    // virtual bool collision(int barry_x, int barry_y)=0;
    // virtual bool delete_item()=0;
    virtual ~Background_Elements();
    // virtual bool barry_collided=0;

};