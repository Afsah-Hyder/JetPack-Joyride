#pragma once
// #include "unit.hpp"
// #include "barry.hpp"

class Killers{
    protected:
    int frame_speed=6;
    public:
    Killers();
    
    virtual void draw()=0;
    virtual void collision(int barry_x, int barry_y)=0;
    virtual bool zapper_delete()=0;

};