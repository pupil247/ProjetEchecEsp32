#include "controleMoteurs.hpp"

volatile bool flagInt0;
volatile bool flagInt1;

Motor * moteur1;
Motor * moteur2;

hw_timer_t *Timer0_Cfg;
hw_timer_t *Timer1_Cfg;

void IRAM_ATTR Timer0_ISR(){
  flagInt0 = 1;        
}

void IRAM_ATTR Timer1_ISR(){
  flagInt1 = 1;        
}

void motorHandler(void * parameter) {

  while(1){
    if(moteur1->getMotorUpdateStatus() || moteur2->getMotorUpdateStatus()){
      updateMoteurs();
      Serial.print("Actif: ");
      Serial.println(moteur1->getMotorOnOff());
      Serial.print("Vitesse: ");
      Serial.println(moteur1->getMotorSpeed());
      Serial.print("Direction: ");
      Serial.println(moteur1->getMotorDirection());
      Serial.println();
      Serial.println();
      Serial.println();
      moteur1->setMotorUpdateStatus(0);
      moteur2->setMotorUpdateStatus(0);
    }

    if(flagInt0){
      flagInt0 = 0;
      moteur1->updatePosition();
    }
    vTaskDelay(1 / portTICK_PERIOD_MS);
  }
 

}

void initMotors(){
  flagInt1 = 0;
  flagInt0 = 0;
  moteur1 = new Motor(GPIO1_1,GPIO2_1,GPIO3_1,GPIO4_1);
  moteur2 = new Motor(GPIO1_2,GPIO2_2,GPIO3_2,GPIO4_2);

  pinMode(GPIO1_1,OUTPUT);
  digitalWrite(GPIO1_1,LOW);
  pinMode(GPIO2_1,OUTPUT);
  digitalWrite(GPIO2_1,LOW);
  pinMode(GPIO3_1,OUTPUT);
  digitalWrite(GPIO3_1,LOW);
  pinMode(GPIO4_1,OUTPUT);
  digitalWrite(GPIO4_1,LOW);

  pinMode(GPIO1_2,OUTPUT);
  digitalWrite(GPIO1_2,LOW);
  pinMode(GPIO2_2,OUTPUT);
  digitalWrite(GPIO2_2,LOW);
  pinMode(GPIO3_2,OUTPUT);
  digitalWrite(GPIO1_1,LOW);
  pinMode(GPIO4_2,OUTPUT);
  digitalWrite(GPIO1_1,LOW);

  Timer0_Cfg = timerBegin(0, 80, true);
  Timer1_Cfg = timerBegin(1, 80, true);

  timerAttachInterrupt(Timer0_Cfg, &Timer0_ISR, true);
  timerAttachInterrupt(Timer1_Cfg, &Timer1_ISR, true);
  timerAlarmWrite(Timer0_Cfg, 2000, true);
  timerAlarmEnable(Timer0_Cfg);

  xTaskCreatePinnedToCore( motorHandler,    "TaskMotors",    5000,      NULL,    1,    NULL,    0);
  delay(500);  // needed to start-up task1
}

void updateMoteurs(){

  timerAlarmWrite(Timer0_Cfg, 200 * moteur1->getMotorSpeed(), true);
  timerAlarmWrite(Timer1_Cfg, 200 * moteur2->getMotorSpeed(), true);

  moteur1->getMotorOnOff() ?  timerStart(Timer0_Cfg) : timerStop(Timer0_Cfg);
  moteur2->getMotorOnOff() ?  timerStart(Timer1_Cfg) : timerStop(Timer1_Cfg);
}




