
#include "controleMoteurs.hpp"
#include "BluetoothSerial.h"
#include <vector>

#define LED 2


// put function declarations here:

void comHandler(void * parameter);
BluetoothSerial SerialBT;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  SerialBT.begin("esp32");
  Serial.println("setup");
  initMotors();
  

  xTaskCreatePinnedToCore(  comHandler,    "Com",    5000,    NULL,    2,    NULL,    1);
  delay(500);

   //creating board
   
}

void loop(){

}

void comHandler(void * parameter) {
  while(1){

    if(Serial.available()){
      char car = Serial.read();
      switch(car){
        case 's':
          moteur1->setMotorOnOff(!moteur1->getMotorOnOff());  
          break;
        case 'v':
          moteur1->setMotorSpeed(moteur1->getMotorSpeed() + 10);  
          break;
        case 'c':
          moteur1->setMotorSpeed(moteur1->getMotorSpeed() - 10);
          break;
        case 'd':
          moteur1->setMotorDirection(!moteur1->getMotorDirection());   
          break; 
      }
    }
    vTaskDelay(100 / portTICK_PERIOD_MS);
  }
  
}

