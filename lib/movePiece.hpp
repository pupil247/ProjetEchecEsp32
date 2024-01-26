#pragma once
#include <Arduino.h>
#include "position.hpp"

class MovePiece : public Position {
    public:
        virtual void updatePosition();
        virtual void setCoordinates(coordinates_x x, coordinates_y y);   
    private:
       

};