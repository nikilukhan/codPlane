#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>

char auth[] = "customAuthenticator";

char ssid[] = "ssid";
char pass[] = "password";

Servo motor;
Servo servoRudder;
Servo servoAileronL;
Servo servoAileronR;
Servo servoElevator;

void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);

  motor.attach(2); //nodeMCU port D4
  servoRudder.attach(14); //nodeMCU port D5
  servoAileronL.attach(12); //nodeMCU port D6
  servoAileronR.attach(13); //nodeMCU port D7
  servoElevator.attach(15); //nodeMCU port D8
}

void loop()
{
  Blynk.run();
}

BLYNK_WRITE(V1) {
  servoRudder.write(param[0].asInt()); 
}
BLYNK_WRITE(V2) {
  int motorSpeed = 2*(param[1].asInt()) -90;
  motor.write(motorSpeed); 
}
BLYNK_WRITE(V3) {
  int controlL = param[0].asInt();
  int controlR = -(param[0].asInt());
  servoAileronL.write(controlL);
  servoAileronR.write(controlR); 
}
BLYNK_WRITE(V4) {
  servoElevator.write(param[0].asInt()); 
}
BLYNK_WRITE(V5) {
  int speedMultiplier = param.asInt()/2 +5; 
}
BLYNK_WRITE(V6) {
  int rudderTrim = param.asInt()/2 +5; 
}
BLYNK_WRITE(V7) {
  int aileronTrim = param.asInt()/2 +5; 
}
BLYNK_WRITE(V8) {
  int elevatorTrim = param.asInt()/2 +5; 
}
