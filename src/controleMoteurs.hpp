#pragma once

#include <Arduino.h>
#include "motor.hpp"

#define GPIO1_1 32
#define GPIO2_1 33
#define GPIO3_1 25
#define GPIO4_1 26

#define  GPIO1_2 27
#define  GPIO2_2 14
#define  GPIO3_2 12
#define  GPIO4_2 13

extern Motor * moteur1;
extern Motor * moteur2;

void initMotors();

void updateMoteurs();

