#pragma once

#include <Arduino.h>

struct motorInfos_t{
    uint8_t currentSpeed;
    bool currentState;
    bool currentDirection; 
    uint8_t currentStep;
    uint8_t A;
    uint8_t B;
    uint8_t A_;
    uint8_t B_;
    bool updateMotorInfos;
};

class Motor{
    public:
        
        Motor(uint8_t pinA, uint8_t pinB, uint8_t pinC, uint8_t pinD);
        
        ~Motor();

        void setMotorSpeed(uint8_t speed);
        void setMotorDirection(bool direction);
        void setMotorOnOff(bool state);
        void setMotorUpdateStatus(bool state);

        uint8_t getMotorSpeed();
        bool getMotorDirection();
        bool getMotorOnOff();
        bool getMotorUpdateStatus();
        void updatePosition(void);
        void updatePos();
        motorInfos_t getMotorInfos();
    private:    
        motorInfos_t motorInfos;

};