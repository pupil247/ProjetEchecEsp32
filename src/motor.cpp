#include "motor.hpp"

Motor::Motor(uint8_t pinA, uint8_t pinB, uint8_t pinC, uint8_t pinD){
    motorInfos.A = pinA;
    motorInfos.B = pinB;
    motorInfos.A_ = pinC;
    motorInfos.B_ = pinD;

    motorInfos.currentState = 0; //off
    motorInfos.currentDirection = 1; //forward
    motorInfos.currentSpeed = 50; //50%
    motorInfos.currentStep = 0;
    motorInfos.updateMotorInfos = 0;
}
Motor::~Motor(){
    
}

void Motor::setMotorSpeed(uint8_t speed){
    if(speed >= 0 && speed <= 100)
        this->motorInfos.currentSpeed = speed;
    this->motorInfos.updateMotorInfos = 1;
}

void Motor::setMotorDirection(bool direction){
    this->motorInfos.currentDirection = direction;
    this->motorInfos.updateMotorInfos = 1;
}

void Motor::setMotorOnOff(bool state){
    this->motorInfos.currentState = state;
    this->motorInfos.updateMotorInfos = 1;
}

void Motor::setMotorUpdateStatus(bool state){
    this->motorInfos.updateMotorInfos  = state;
}

uint8_t Motor::getMotorSpeed(){
    return this->motorInfos.currentSpeed;
}

bool Motor::getMotorDirection(){
    return this->motorInfos.currentDirection;
}

bool Motor::getMotorOnOff(){
    return this->motorInfos.currentState;
}

bool Motor::getMotorUpdateStatus(){
    return this->motorInfos.updateMotorInfos;
}

motorInfos_t Motor::getMotorInfos(){
    return this->motorInfos;
}

void Motor::updatePosition(void){
    switch(this->motorInfos.currentStep){
        case 0:
            digitalWrite(this->motorInfos.A, 1);
            ets_delay_us(1);  
            digitalWrite(this->motorInfos.B, 1); 
            ets_delay_us(1);  
            digitalWrite(this->motorInfos.B_, 0);
            this->motorInfos.currentDirection ? this->motorInfos.currentStep++ : this->motorInfos.currentStep = 4;  
            break;
        case 1:
            digitalWrite(this->motorInfos.A, 0); 
            ets_delay_us(1);   
            digitalWrite(this->motorInfos.A_, 1);   
            this->motorInfos.currentDirection ? this->motorInfos.currentStep++ : this->motorInfos.currentStep--; 
            break;
        case 2:
            digitalWrite(this->motorInfos.B, 0);
            ets_delay_us(1);  
            digitalWrite(this->motorInfos.B_, 1); 
            this->motorInfos.currentDirection ? this->motorInfos.currentStep++ : this->motorInfos.currentStep--; 
            break;
        default:
            digitalWrite(this->motorInfos.A_, 0);
            ets_delay_us(1);   
            digitalWrite(this->motorInfos.A, 1); 
            this->motorInfos.currentDirection ? this->motorInfos.currentStep = 0 : this->motorInfos.currentStep--;
            break;
    }
}

