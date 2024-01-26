#pragma once
#include <Arduino.h>
#include "motor.hpp"

class Position{
    public:  
        enum coordinates_x{xA,xB,xC,xD,xE,xF,xG,xH};
        enum coordinates_y{y1,y2,y3,y4,y5,y6,y7,y8};

        struct coordinatesXY{
            coordinates_x x;
            coordinates_y y;
        };
        //virtual void updatePosition();
        virtual void setCoordinates(coordinates_x x, coordinates_y y);
        coordinatesXY getCoordinates(){
            return coordinates;
        };
    private:
        coordinatesXY coordinates;  

};