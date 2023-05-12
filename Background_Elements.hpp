#pragma once
// #include "unit.hpp"
// #include "barry.hpp"

class Background_Elements{
    protected:
    public:
    Background_Elements();
    
    //pure virtual functions
    virtual void draw()=0;
    virtual bool delete_item()=0;
    virtual ~Background_Elements();


};